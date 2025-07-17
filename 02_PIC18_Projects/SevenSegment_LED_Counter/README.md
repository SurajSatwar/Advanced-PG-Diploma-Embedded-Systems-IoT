# 02_SevenSegment_LED_Counter

This project demonstrates the use of two 7-segment displays with the PIC18F4520 microcontroller.

## Description:
- Uses PORTB to send 7-segment data.
- Controls two digits using RD0 and RD1.
- Increments numbers from 0 to 9 with delay.
- LED-like functionality via RD0/RD1 switching.

## Tools:
- MPLAB X IDE
- Proteus for simulation
- XC8 Compiler

## Connections:
- PORTB -> 7-Segment segments (a-g)
- RD0 and RD1 -> Common anodes/cathodes of displays
