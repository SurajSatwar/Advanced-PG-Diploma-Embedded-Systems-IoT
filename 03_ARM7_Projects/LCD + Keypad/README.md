# LPC2148 LCD + 4x4 Keypad Interface

This embedded C program interfaces a **4x4 matrix keypad** with a **16x2 LCD** using the **LPC2148 (ARM7)** microcontroller. The pressed key is detected and displayed on the LCD in 8-bit mode.

---

##  Features
- 8-bit LCD interfacing (D0–D7)
- Detects key from 4x4 Keypad
- Displays the character on LCD in real time
- Debounce delay included

---

##  Pin Mapping

### LCD Connections
| LCD Pin        | LPC2148 Pin (P0) |
|----------------|------------------|
| D0 – D7        | P0.16 – P0.23    |
| RS             | P0.8             |
| RW             | P0.9             |
| EN             | P0.10            |

---

### Keypad Connections
| Keypad Line | LPC2148 Pin |
|-------------|--------------|
| Rows R1–R4  | P1.16–P1.19   |
| Cols C1–C4  | P0.11–P0.14   |

---

##  Keypad Character Map

7 8 9 D
4 5 6 M
1 2 3 S
C 0 E A
