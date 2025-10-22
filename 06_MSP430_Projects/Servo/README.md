Servo Motor Sweep using Arduino / ESP32
📘 Overview

This project demonstrates how to control a servo motor using Arduino or ESP32.
The servo rotates smoothly from 0° to 180° in steps of 1° using the Servo library.

⚙️ Components Required
Component	Quantity	Description
Arduino Uno / ESP32 / Compatible Board	1	Microcontroller
Servo Motor	1	Standard hobby servo (e.g., SG90)
Jumper Wires	—	For connections
External Power Supply (optional)	1	Recommended for stable servo operation
🔌 Circuit Connections
Servo Pin	Microcontroller Pin	Description
Signal	D9	PWM control from Arduino/ESP32
VCC	5V	Power supply for servo
GND	GND	Common ground

Note: For ESP32, ensure the servo uses 3.3V tolerant PWM pin or an external 5V supply.

Key Points:

Servo myservo; → Creates a servo object.

myservo.attach(9); → Connects the servo to pin D9.

myservo.write(angle); → Sets servo to the specified angle (0–180°).

delay(100); → Controls the speed of rotation.

🚀 How to Run

Open Arduino IDE and select the correct board (Arduino Uno or ESP32).

Connect the servo as per the circuit diagram.

Upload the code.

The servo will sweep smoothly from 0° to 180° repeatedly.

📈 Learning Outcomes

Understanding PWM control for servo motors.

Using the Arduino Servo library for precise angle control.

Controlling the servo motor sweep speed using delay().
