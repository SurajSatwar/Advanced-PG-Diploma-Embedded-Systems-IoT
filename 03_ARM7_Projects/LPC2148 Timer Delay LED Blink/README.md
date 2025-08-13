# LPC2148 Timer Delay LED Blink

This project demonstrates using **Timer0** in the LPC2148 ARM7 microcontroller to blink an LED with precise delays.

---

## Features
- Uses **Timer0** in timer mode.
- LED connected to **P0.4**.
- 1-second ON / 1-second OFF blinking.

---

## Hardware Requirements
- LPC2148 Development Board
- 12 MHz Crystal Oscillator
- LED + Current Limiting Resistor
- USB to UART (for flashing)

---

## Pin Connections
| Pin   | Function       |
|-------|---------------|
| P0.4  | LED Output    |
| GND   | LED Ground    |

---

## How It Works
1. **Timer Initialization**  
   - Configures `T0PR` so that each timer tick = 1 ms.  
2. **Delay Function**  
   - Waits for the required number of milliseconds using Timer0.  
3. **Main Loop**  
   - Turns LED ON → Delay 1s → Turns LED OFF → Delay 1s.

---

## Code
```c
#include <LPC214x.h>

void timer_init(void){
    VPBDIV = 0x01;       // PCLK = CCLK = 12 MHz
    T0CTCR = 0x00;       // Timer mode
    T0PR = 119999;       // 1 ms tick
}

void timer_delay(int s){
    T0TC = 0x00;
    T0TCR = 0x02;        // Reset timer
    T0TCR = 0x01;        // Start timer
    while(T0TC < s);     // Wait
    T0TCR = 0x00;        // Stop timer
}

int main(void){
    PINSEL0 = 0x00000000; // P0.4 as GPIO
    IO0DIR |= (1<<4);     // P0.4 output
    timer_init();
    
    while(1){
        IO0SET |= (1<<4); // LED ON
        timer_delay(1000);
        IO0CLR |= (1<<4); // LED OFF
        timer_delay(1000);
    }
}
