# LPC2148 RTC with LCD

This project demonstrates **Real Time Clock (RTC)** interfacing with a **16x2 LCD** on the LPC2148 microcontroller.

##  Hardware Connections
- LCD:
  - RS → P0.10
  - RW → P0.11
  - EN → P0.12
  - D0–D7 → P0.16–P0.23
- RTC:
  - Uses internal **RTC registers** with external 32.768 kHz crystal.

##  Features
- Displays **Date (DD_MM_YYYY)** and **Day of Week** on the first line.
- Displays **Time (HH:MM:SS)** on the second line.

##  Usage
1. Flash program onto LPC2148 using Keil/Flash Magic.
2. Connect a 32.768 kHz crystal to the RTC pins.
3. Observe Date, Day, and Time on LCD.
