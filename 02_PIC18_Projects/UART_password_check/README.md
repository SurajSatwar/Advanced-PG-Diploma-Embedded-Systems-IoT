# PIC18F4520 UART Password Check

This project uses the PIC18F4520 microcontroller to implement a simple password authentication system via UART. When the correct 4-digit password is entered, a GPIO pin (RA0) is set high (e.g., to turn on an LED or relay).

## Features

- UART-based password input (4-digit)
- Echo input characters back to terminal
- Compare with preset password (`1234`)
- LED or output ON on success
- Message feedback for both success/failure

## Connection (USART)

- TX: RC6
- RX: RC7
- Output: RA0 (Connect LED or relay)

## Baud Rate Setting

- SPBRG = 0x81 (approx. 9600 bps @ 20MHz clock)

## Tools Used

- MPLAB X IDE
- XC8 Compiler
- Proteus (for simulation, optional)

## How it works

1. Waits for user to enter a 4-digit password via UART
2. Compares it with `1234`
3. Displays appropriate message via UART
4. Turns on RA0 pin for 10 seconds on success
