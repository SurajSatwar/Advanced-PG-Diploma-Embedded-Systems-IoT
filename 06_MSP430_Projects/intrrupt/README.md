MSP430 Interrupt-Based LED Control
🔍 Overview

This project demonstrates how to use external interrupts on the MSP430 microcontroller to control an LED.
When a button connected to pin P1.3 is pressed, an interrupt is triggered that toggles the LED state connected to P1.6.

⚙️ Components Used

MSP430 LaunchPad (e.g., MSP430G2553 or MSP430G2231)

Push button switch

LED

Resistors (for LED and button pull-up)

USB cable (for programming via Energia IDE)

🧠 Working Principle

The button is connected to the interrupt pin (P1.3) and configured as INPUT_PULLUP.

When the button is pressed, a falling edge interrupt occurs.

The Interrupt Service Routine (ISR) named blink() toggles the state variable.

The main loop continuously updates the LED according to the state value.

🧾 Code Explanation
const byte ledPin = P1_6;          // LED connected to P1.6
const byte interruptPin = P1_3;    // Button connected to P1.3
volatile byte state = LOW;         // LED state variable

void setup() {
  pinMode(ledPin, OUTPUT);         // Set LED as output
  pinMode(interruptPin, INPUT_PULLUP);  // Enable internal pull-up for button
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);  
  // Trigger interrupt on button press
}

void loop() {
  digitalWrite(ledPin, state);     // Reflect LED state
}

void blink() {
  state = !state;                  // Toggle LED on interrupt
}

⚡ Connection Diagram
Component	MSP430 Pin	Description
LED	P1.6	Output pin
Push Button	P1.3	Interrupt input (active LOW)
GND	GND	Common ground
🧩 Features

✅ Demonstrates interrupt-based event handling
✅ Debounce-free hardware-level response
✅ Energy-efficient (main loop is lightweight)

🧪 Testing Steps

Upload the code using Energia IDE or Code Composer Studio.

Press the button connected to P1.3.

Observe the LED toggling on each button press.

📂 Files Included

msp430_interrupt_led.ino – Main source code

msp430_interrupt_led.hex – Compiled HEX file for direct flashing

🧰 Tools Used

IDE: Energia IDE / Code Composer Studio

Microcontroller: MSP430G2 series

Language: Embedded C / Arduino-style

🏁 Output

Each press of the button toggles the LED state ON or OFF instantly using hardware interrupt control.
