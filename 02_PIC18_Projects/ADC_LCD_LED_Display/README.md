# ADC Reading and LED Control using PIC18F4520

This project reads analog input using the ADC module of the PIC18F4520 microcontroller, displays the value on an LCD, and controls up to 10 LEDs based on the input level.

## Components Used
- PIC18F4520 Microcontroller
- 16x2 LCD Display (connected via LATB)
- Analog sensor input on RA0
- 10 LEDs (connected to PORTD and RC0-RC1)

## Functionality
- Analog input on RA0 is read via ADC.
- Value is displayed on the LCD.
- Depending on the value, up to 10 LEDs light up.

## Tools
- MPLAB X IDE
- XC8 Compiler
- Proteus (for simulation)

## Files
- `main.c` — Contains the source code.
