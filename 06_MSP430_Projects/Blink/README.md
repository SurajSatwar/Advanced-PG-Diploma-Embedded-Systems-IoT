MSP430 Push Button and LED Control
📘 Overview

This project demonstrates digital input and output control using the MSP430 microcontroller.
A push button connected to P1.3 acts as an input, and an LED connected to P1.6 acts as an output.
When the button is pressed, the LED turns ON; when released, it turns OFF.

⚙️ Hardware Requirements

MSP430 LaunchPad (e.g., MSP430G2553 or compatible board)

Push Button

LED + 220Ω resistor

Breadboard and jumper wires

USB cable for uploading code

🔌 Circuit Connections
MSP430 Pin	Component	Description
P1.3	Push Button	Digital input with internal pull-up
P1.6	LED	Digital output
VCC (3.3V)	Push Button terminal	Power supply
GND	Push Button & LED GND	Common ground
🧠 Working Principle

The input pin P1.3 is configured with an internal pull-up resistor, so its normal state is HIGH.

When the button is pressed, it connects P1.3 to GND, pulling the input LOW.

The code checks the state continuously:

If LOW (pressed) → LED ON

If HIGH (released) → LED OFF

🧩 Source Code
void setup() {
  pinMode(P1_3, INPUT_PULLUP); // Set P1.3 as input with internal pull-up
  pinMode(P1_6, OUTPUT);       // Set P1.6 as output for LED
}

void loop() {
  int x = digitalRead(P1_3);   // Read button input
  if (x == 0) {                // Button pressed
    digitalWrite(P1_6, HIGH);  // Turn ON LED
  } else {                     // Button released
    digitalWrite(P1_6, LOW);   // Turn OFF LED
  }
}

🧰 Software Requirements

Energia IDE (Arduino-compatible IDE for MSP430)

MSP430 Board Package

Optional: Code Composer Studio (CCS) for HEX generation or debugging

🚀 How to Run

Open Energia IDE.

Select your board:
Tools → Board → MSP430G2553 LaunchPad

Copy the code above and upload it.

Observe the LED toggle based on button press.

💾 Precompiled HEX File

If you don’t want to recompile, upload the included MSP430_Button_LED.hex file using:

MSP430Flasher or

Code Composer Studio → Target → Load Program
