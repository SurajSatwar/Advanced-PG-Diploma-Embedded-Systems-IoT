#include <lpc214x.h>

void Delay_Ms(unsigned int t)
{
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 600; j++);
}

int main(void)
{
    // Configure column pins (P1.16 to P1.19) as input
    IO1DIR &= ~(1 << 16);  // C0 = P1.16
    IO1DIR &= ~(1 << 17);  // C1 = P1.17
    IO1DIR &= ~(1 << 18);  // C2 = P1.18
    IO1DIR &= ~(1 << 19);  // C3 = P1.19

    // Configure row pins (P0.10 to P0.13) as output
    IO0DIR |= (1 << 10);   // R0 = P0.10
    IO0DIR |= (1 << 11);   // R1 = P0.11
    IO0DIR |= (1 << 12);   // R2 = P0.12
    IO0DIR |= (1 << 13);   // R3 = P0.13

    // Configure LEDs (P0.14 to P0.17) as output
    IO0DIR |= (1 << 14);   // LED1
    IO0DIR |= (1 << 15);   // LED2
    IO0DIR |= (1 << 16);   // LED3
    IO0DIR |= (1 << 17);   // LED4

    // Turn OFF all LEDs initially
    IO0SET |= (1 << 14);
    IO0SET |= (1 << 15);
    IO0SET |= (1 << 16);
    IO0SET |= (1 << 17);

    while(1)
    {
        // --- Row 0 ---
        IO0CLR |= (1 << 10);  // R0 = 0
        IO0SET |= (1 << 11) | (1 << 12) | (1 << 13);
        if ((IO1PIN & (1 << 16)) == 0) { IO0CLR |= (1 << 14); Delay_Ms(500); IO0SET |= (1 << 14); Delay_Ms(500); }
        if ((IO1PIN & (1 << 17)) == 0) { IO0CLR |= (1 << 15); Delay_Ms(500); IO0SET |= (1 << 15); Delay_Ms(500); }
        if ((IO1PIN & (1 << 18)) == 0) { IO0CLR |= (1 << 16); Delay_Ms(500); IO0SET |= (1 << 16); Delay_Ms(500); }
        if ((IO1PIN & (1 << 19)) == 0) { IO0CLR |= (1 << 17); Delay_Ms(500); IO0SET |= (1 << 17); Delay_Ms(500); }

        // --- Row 1 ---
        IO0CLR |= (1 << 11);  // R1 = 0
        IO0SET |= (1 << 10) | (1 << 12) | (1 << 13);
        if ((IO1PIN & (1 << 16)) == 0) { IO0CLR |= (1 << 14); Delay_Ms(500); IO0SET |= (1 << 14); Delay_Ms(500); }
        if ((IO1PIN & (1 << 17)) == 0) { IO0CLR |= (1 << 15); Delay_Ms(500); IO0SET |= (1 << 15); Delay_Ms(500); }
        if ((IO1PIN & (1 << 18)) == 0) { IO0CLR |= (1 << 16); Delay_Ms(500); IO0SET |= (1 << 16); Delay_Ms(500); }
        if ((IO1PIN & (1 << 19)) == 0) { IO0CLR |= (1 << 17); Delay_Ms(500); IO0SET |= (1 << 17); Delay_Ms(500); }

        // --- Row 2 ---
        IO0CLR |= (1 << 12);  // R2 = 0
        IO0SET |= (1 << 10) | (1 << 11) | (1 << 13);
        if ((IO1PIN & (1 << 16)) == 0) { IO0CLR |= (1 << 14); Delay_Ms(500); IO0SET |= (1 << 14); Delay_Ms(500); }
        if ((IO1PIN & (1 << 17)) == 0) { IO0CLR |= (1 << 15); Delay_Ms(500); IO0SET |= (1 << 15); Delay_Ms(500); }
        if ((IO1PIN & (1 << 18)) == 0) { IO0CLR |= (1 << 16); Delay_Ms(500); IO0SET |= (1 << 16); Delay_Ms(500); }
        if ((IO1PIN & (1 << 19)) == 0) { IO0CLR |= (1 << 17); Delay_Ms(500); IO0SET |= (1 << 17); Delay_Ms(500); }

        // --- Row 3 ---
        IO0CLR |= (1 << 13);  // R3 = 0
        IO0SET |= (1 << 10) | (1 << 11) | (1 << 12);
        if ((IO1PIN & (1 << 16)) == 0) { IO0CLR |= (1 << 14); Delay_Ms(500); IO0SET |= (1 << 14); Delay_Ms(500); }
        if ((IO1PIN & (1 << 17)) == 0) { IO0CLR |= (1 << 15); Delay_Ms(500); IO0SET |= (1 << 15); Delay_Ms(500); }
        if ((IO1PIN & (1 << 18)) == 0) { IO0CLR |= (1 << 16); Delay_Ms(500); IO0SET |= (1 << 16); Delay_Ms(500); }
        if ((IO1PIN & (1 << 19)) == 0) { IO0CLR |= (1 << 17); Delay_Ms(500); IO0SET |= (1 << 17); Delay_Ms(500); }
    }
}