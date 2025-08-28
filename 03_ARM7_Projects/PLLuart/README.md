# LPC2148 UART Example

This project demonstrates **UART communication** on the LPC2148 microcontroller with PLL configuration.

##  Hardware Connections
- UART0:
  - TxD0 → P0.0
  - RxD0 → P0.1

##  Features
- PLL set to run core at 60 MHz (PCLK = 15 MHz).
- UART configured for **9600 baud, 8N1**.
- Receives a character from PC and transmits `'@'` back.
- (Optional: echo received character).

##  Usage
1. Flash program onto LPC2148 using Keil/Flash Magic.
2. Connect USB-to-Serial or MAX232 to UART0.
3. Open Serial Terminal (9600 baud, 8N1).
4. Send any character → Board responds with `@`.
