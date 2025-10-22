MSP430 Analog Voltage Measurement using ADC
📘 Overview

This project demonstrates how to read analog voltage values from a sensor or potentiometer using the MSP430 microcontroller’s ADC (Analog-to-Digital Converter).
The raw ADC values and corresponding voltage levels are displayed on the Serial Monitor.

⚙️ Hardware Requirements

MSP430 LaunchPad (e.g., MSP430G2231, MSP430G2553)

Analog Sensor (e.g., Potentiometer, Temperature sensor, or MQ gas sensor)

Jumper Wires & Breadboard

USB Cable for programming and power

🔌 Circuit Connections
MSP430 Pin	Component	Description
A3	Analog Output of Sensor / Potentiometer	ADC input
3.3V	VCC of sensor	Power supply
GND	GND of sensor	Ground connection
🧠 Working Principle

The analogRead() function reads the voltage level from pin A3.

The MSP430’s ADC converts this analog signal (0V–3.3V) to a 10-bit digital value (0–1023).

The voltage is calculated using the formula:

𝑉
𝑖
𝑛
=
ADC Value
×
3.0
1023.0
V
in
	​

=ADC Value×
1023.0
3.0
	​


Both the ADC value and the voltage are displayed on the Serial Monitor.

🧩 Source Code
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // for MSP430G2231 use 4800
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A3);             // Read analog value
  float voltage = sensorValue * (3.0 / 1023.0); // Convert to voltage

  Serial.println(voltage);      // Print voltage
  Serial.println(sensorValue);  // Print ADC raw value
  delay(500);
}

🧰 Software Requirements

Energia IDE (Arduino-compatible IDE for MSP430)

MSP430 Board Package installed

Serial Monitor configured at 9600 baud (or 4800 baud for MSP430G2231)

🚀 How to Run

Open Energia IDE.

Select your board:
Tools → Board → MSP430G2231 (or your specific variant)

Upload the code to your MSP430 LaunchPad.

Open the Serial Monitor.

Observe live ADC values and voltage readings.
Turning the potentiometer or changing sensor input varies the readings.

📈 Sample Serial Output
1.23
420
1.65
560


(Voltage in Volts, followed by ADC value)

💾 Optional: HEX File

You can upload the precompiled HEX file (if provided) using:

MSP430Flasher utility

Code Composer Studio → Target → Load Program
