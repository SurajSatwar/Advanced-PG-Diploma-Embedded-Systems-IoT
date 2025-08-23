# LPC2148 External Interrupt (EINT2) with LEDs

This project demonstrates the use of **External Interrupt 2 (EINT2)** on the **LPC2148 ARM7 microcontroller**.  
When the external interrupt (falling edge at P0.15) is triggered, the ISR toggles LEDs connected to P0.4 and P0.5.

## 🔧 Hardware Connections
- **LED1** → P0.4  
- **LED2** → P0.5  
- **Interrupt Input (EINT2)** → P0.15 (active on falling edge)

## 📜 Code Highlights
- Configures **P0.15** as external interrupt (EINT2).  
- LEDs are controlled inside `main()` and ISR.  
- VIC (Vectored Interrupt Controller) used to handle ISR.  

## ▶️ Usage
1. Flash the program to LPC2148 using Keil/Flash Magic.  
2. Connect LEDs and push button to P0.15.  
3. On button press (falling edge), ISR executes and toggles LEDs.  

---
