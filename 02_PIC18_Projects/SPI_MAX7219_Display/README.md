# SPI Interface with MAX7219 using PIC18F4520

This project demonstrates interfacing the PIC18F4520 microcontroller with a MAX7219 driver to control a 7-segment display using the SPI protocol.

## Features

- Displays digits 0–9 on the first digit (address 0x01) of the MAX7219
- Uses SPI communication protocol
- Simple delay-based looping

## Connections

| PIC18F4520 Pin | MAX7219 Pin |
|----------------|-------------|
| RC5 (SDO)      | DIN         |
| RC3 (SCK)      | CLK         |
| RA5 (manual CS)| CS          |
| GND            | GND         |
| VDD            | VCC         |

## MAX7219 Initialization Commands

- Decode mode: OFF
- Intensity: High (0x0F)
- Scan limit: All 8 digits
- Shutdown: Normal operation
- Display test: OFF

## Components Used

- PIC18F4520 microcontroller
- MAX7219 IC
- 7-segment display (8-digit)
- SPI protocol

## Tools Used

- MPLAB X IDE
- XC8 Compiler
- Proteus (optional, for simulation)

## How it works

1. Initializes SPI and MAX7219
2. Continuously displays digits `0` to `9` on the first display segment (address `0x01`)
