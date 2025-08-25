# LPC2148 ADC with LCD

This project reads analog input from **ADC0.1 (P0.28)** of the LPC2148 microcontroller and displays the result on a **16x2 LCD** in 8-bit mode.

## 🔧 Hardware Connections
- **LCD**
  - RS → P0.10
  - RW → P0.11
  - EN → P0.12
  - D0–D7 → P0.16–P0.23
- **ADC Input**
  - ADC0.1 → P0.28

## ▶️ Usage
1. Connect a variable voltage source (0–3.3V) to **P0.28**.  
2. Flash program using Keil/Flash Magic.  
3. The ADC result (0–1023) will be displayed on the LCD.
