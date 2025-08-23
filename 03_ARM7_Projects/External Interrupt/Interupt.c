#include <lpc214x.h>

void ext2_ISR(void) __irq;
void delay(unsigned int);

int main(void)
{
    // 1. Set P0.15 as EINT2 (Function 10 ? bit 31 = 1, bit 30 = 0)
    PINSEL0 = 0x80000000;

    // 2. Set P0.4 and P0.5 as output for LEDs
    IO0DIR |= (1 << 4) | (1 << 5);
	  IO0DIR &= ~ (1<<15);

    // 3. Configure external interrupt EINT2
    EXTINT     = 0x04;              // Clear EINT2 flag (write 1 to clear)
    EXTMODE    = 0x04;              // Edge-sensitive mode
    EXTPOLAR  &= ~(1 << 2);         // Falling edge triggered

    // 4. Configure interrupt controller (VIC)
    VICIntSelect &= ~(1 << 16);     // EINT2 as IRQ
    VICVectAddr0 = (unsigned int)ext2_ISR;  // Set ISR address
    VICVectCntl0 = (1 << 5) | 16;   // Enable slot 0 for EINT2
    VICIntEnable |= (1 << 16);      // Enable EINT2 interrupt

    while (1)
    {
        // Main loop: LED1 ON (P0.4 LOW), LED2 OFF (P0.5 HIGH)
        IO0CLR = (1 << 4);          // LED1 OFF
        IO0SET = (1 << 5);          // LED2 ON
    }
}

void ext2_ISR(void) __irq
{
    // In ISR: LED1 OFF (P0.4 HIGH), LED2 ON (P0.5 LOW)
    IO0SET = (1 << 4);              // LED1 ON
    IO0CLR = (1 << 5);              // LED2 OFF
    delay(500);                     // Visual delay

    EXTINT = 0x04;                  // Clear EINT2 interrupt flag (write 1)
    VICVectAddr = 0;                // End of interrupt
}

void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 90000; j++);   // Rough delay loop
}

