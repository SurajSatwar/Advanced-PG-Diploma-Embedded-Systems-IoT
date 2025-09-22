STM32 LCD Project
Project Overview

This project demonstrates how to interface an LCD module with an STM32 microcontroller. It includes example code to initialize the LCD, send characters/text, and optionally clear or move the cursor. Useful for embedded systems learning and displays basic usage of GPIOs & delays.

Features

Initialize the LCD in 4-bit (or 8-bit) mode

Send characters and strings to display

Clear display

Move cursor to specific positions

Basic delay routines

Hardware Requirements

STM32 microcontroller (e.g. STM32F1 / STM32F4 series)

LCD module (e.g. HD44780-compatible 16×2 or 20×4 LCD)

Resistor(s) for contrast (usually ~10k)

Potentiometer for contrast (optional)

Breadboard, jumper wires

Connections / Pin Configuration
LCD Pin	MCU Pin	Description
RS	Specify MCU pin used	Register Select
RW	Specify MCU pin used (often tied to GND for write only)	Read/Write
EN	Specify MCU pin used	Enable signal
D4–D7	Specify 4 or 8 data pins	Data lines (for 4-bit mode just D4–D7)
VCC	5V (or 3.3V depending on the LCD)	Power supply
VSS	GND	Ground
V0	Potentiometer middle pin	Contrast adjustment

Note: Adjust voltage levels according to your LCD’s requirements; some LCDs need 5 V, some support 3.3 V.

Software / Library Usage

Code written in C for STM32 (using HAL library / LL / bare-metal, depending on folder implementation)

Delay routines implemented using SysTick / HAL_Delay / busy-wait loop

Functions typically include:

LCD_Init() — Initialize the LCD

LCD_SendCommand(cmd) — Send command byte

LCD_SendChar(ch) — Send single character

LCD_SendString(str) — Send string

LCD_Clear() — Clear the display

LCD_SetCursor(row, col) — Move cursor

Build & Flash

Open the project in your IDE (e.g. STM32CubeIDE)

Ensure correct MCU is selected in project settings

Configure the pin mappings to match your hardware

Build / compile the code

Flash to the STM32 target

Usage

Power up the circuit

After reset, LCD should initialize and display a welcome message

Try sending your own messages by modifying the main() function

Troubleshooting

If nothing shows:

Check contrast potentiometer setting

Ensure EN, RS pins are correct and working

Check delays after initialization — sometimes waiting longer helps

If characters appear garbled: wrong pin wiring or setting wrong mode (4-bit vs 8-bit)

If only some segments visible: possible supply voltage issue or leaking pins

Directory Structure
/
├── Inc/        → Header files (LCD interface, pin definitions)
├── Src/        → Source files (LCD driver, main program)
├── .project / .ioc etc → IDE configuration files
└── README.md   → This document
