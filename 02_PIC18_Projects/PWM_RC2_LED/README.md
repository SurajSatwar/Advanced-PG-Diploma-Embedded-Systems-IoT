PWM Fading LED using PIC18F4520

This project demonstrates Pulse Width Modulation (PWM) using the CCP1 module of the PIC18F4520. The output is connected to RC2 (Pin 17), and it smoothly fades an LED brightness up and down.

Configuration
- Microcontroller: PIC18F4520
- Output Pin: RC2 (CCP1)
- PWM Frequency: ~5kHz
- Clock: 20 MHz External Crystal

Files
- `main.c` – Embedded C program
- `PWM_RC2_LED_Fade.hex` – Compiled HEX for Proteus

Simulation
Connect an LED (via resistor) to RC2. Load the HEX in Proteus and run simulation. The LED will fade in and out due to changing duty cycle.
