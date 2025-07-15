# RTC with I2C (DS1307) - PIC18F4520

This project interfaces the DS1307 RTC module with the PIC18F4520 microcontroller using I2C protocol. The current time is displayed on a 16x2 LCD.

## Components:
- PIC18F4520
- DS1307 RTC Module
- 16x2 LCD (PORTD)
- 4.7k pull-ups for SDA, SCL

## Features:
- Time display in HH:MM:SS
- I2C communication using MSSP
- BCD to ASCII conversion

## Tools:
- MPLAB X IDE
- XC8 Compiler
- Proteus for simulation

## Pin Mapping:
- LCD RS, RW, E: RC1, RC0, RC2
- LCD Data: PORTD
- I2C: RC3 (SCL), RC4 (SDA)
