# UART LED Control using PIC18F4520

This project demonstrates how to control an LED using UART communication on a PIC18F4520 microcontroller. The system receives data via UART and performs actions based on the received input.

## 🔧 Project Details

- **Microcontroller:** PIC18F4520
- **Interface:** UART (9600 baud)
- **Compiler/IDE:** MPLAB X IDE with XC8 Compiler
- **Simulation:** Proteus 8 Professional
- **Language:** Embedded C

## 📱 Functionality

The microcontroller receives character input via UART. Based on the character received, the corresponding LED is turned ON or OFF.

### Input Mapping:
| Key Pressed | UART Char Sent | Action on PIC |
|-------------|----------------|----------------|
| `1`         | `1`            | LED ON         |
| `2`         | `2`            | LED OFF        |

## 🔌 Hardware Connections

| Component     | PIC18F4520 Pin |
|---------------|----------------|
| LED (active HIGH) | PORTx (e.g., RA0)     |
| UART RX       | RC7 (Pin 26)   |
| UART TX       | RC6 (Pin 25)   |
| GND           | GND            |
| Vcc (5V)      | Vcc            |

## 🛠️ How to Use

1. Load the code into MPLAB X IDE and compile using the XC8 compiler.
2. Flash the HEX file to the PIC18F4520 or simulate in Proteus.
3. Use a Serial Terminal (e.g., Tera Term, RealTerm) to send characters via UART (9600 8N1).
4. Observe the LED behavior:
   - Send `1` → LED turns ON
   - Send `2` → LED turns OFF

## 📷 Screenshot (Proteus Simulation)

_Include an image here showing the Proteus simulation._

## 📂 File Structure

