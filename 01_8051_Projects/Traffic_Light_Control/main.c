#include <reg51.h>

// Define LED pins
sbit RED    = P1^0;
sbit YELLOW = P1^1;
sbit GREEN  = P1^2;

// Simple delay function (~1 ms for 11.0592 MHz)
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++){
        for(j = 0; j < 1275; j++);
}
}

void turn_off_all() {
    RED = 0;
    YELLOW = 0;
    GREEN = 0;
}

void main() {
    while(1) {
        turn_off_all();   // Make sure all lights are OFF
        RED = 1;          // RED ON
        delay_ms(5000);   // 5 seconds

        turn_off_all();
        YELLOW = 1;       // YELLOW ON
        delay_ms(5000);   // 2 seconds

        turn_off_all();
        GREEN = 1;        // GREEN ON
        delay_ms(5000);   // 5 seconds
    }
}
