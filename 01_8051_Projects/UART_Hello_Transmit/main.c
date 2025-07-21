#include <reg51.h>

// Function prototypes
void UART_init(void);
void trans(unsigned char a);
void string(char str[]);
void delay(unsigned int ms);

// UART Initialization
void UART_init() {
    SCON = 0x50;   // 8-bit UART mode, REN enabled
    TMOD |= 0x20;  // Timer1, Mode2 (auto-reload)
    TH1 = 0xFD;    // 9600 baud rate for 11.0592 MHz crystal
    TL1 = 0xFD;
    TR1 = 1;       // Start Timer1
}

// Transmit a single character
void trans(unsigned char a) {
    SBUF = a;
    while (TI == 0);  // Wait for transmission complete
    TI = 0;
}

// Transmit a string
void string(char str[]) {
    unsigned int i = 0;
    while (str[i] != '\0') {
        trans(str[i]);
        i++;
    }
}

// Delay in milliseconds (approximate)
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 127; j++);
}

// Main function
void main() {
    UART_init();
    while (1) {
        string("Hello\n");
        delay(1000);  // Delay of approx 1 second
    }
}
