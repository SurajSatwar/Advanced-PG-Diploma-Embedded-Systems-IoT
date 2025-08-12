# ARM7 LPC2148 – 4x4 Keypad with LED Control

## 📌 Overview
This project demonstrates interfacing a **4x4 matrix keypad** with the **ARM7 LPC2148** microcontroller to control **4 LEDs**.  
When a key is pressed, the corresponding LED blinks.

---

## ⚙️ Hardware Connections

### **Keypad to LPC2148**
- **Columns (C0–C3)** → P1.16, P1.17, P1.18, P1.19 (INPUT)
- **Rows (R0–R3)** → P0.10, P0.11, P0.12, P0.13 (OUTPUT)

### **LEDs to LPC2148**
- LED1 → P0.14  
- LED2 → P0.15  
- LED3 → P0.16  
- LED4 → P0.17

---

## 🛠 Software Setup
- **Controller:** LPC2148 (ARM7TDMI-S core)
- **IDE:** Keil uVision 5
- **Programmer:** Flash Magic
- **Language:** Embedded C
- **Clock Frequency:** 12 MHz Crystal

---

## 📂 Code Explanation
1. **Pin Configuration**
   - Rows are set as output (`IO0DIR`)
   - Columns are set as input (`IO1DIR`)
   - LEDs are set as output (`IO0DIR`)

2. **Keypad Scanning**
   - One row is driven LOW at a time.
   - The columns are read to detect the pressed key.

3. **LED Control**
   - If a key in a row is pressed, the corresponding LED blinks.

4. **Delay Function**
   - `Delay_Ms()` generates approximate millisecond delays for LED blinking.

---

## ▶️ How to Run
1. Open the code in Keil uVision.
2. Compile and generate the HEX file.
3. Flash it to the LPC2148 using Flash Magic.
4. Connect the keypad and LEDs as per wiring diagram.
5. Press keys on the keypad to see the LEDs blink.

---

## 🔍 Example Behavior
- **Press C0 in Row 0** → LED1 blinks  
- **Press C1 in Row 0** → LED2 blinks  
- **Press C2 in Row 0** → LED3 blinks  
- **Press C3 in Row 0** → LED4 blinks  
- Same pattern applies for other rows.

---
