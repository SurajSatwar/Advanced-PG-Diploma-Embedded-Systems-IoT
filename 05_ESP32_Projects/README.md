ESP32 Projects – Advanced PG Diploma in Embedded Systems & IoT
📘 Overview

This repository contains a collection of ESP32-based IoT and embedded projects developed as part of the Advanced PG Diploma in Embedded Systems and IoT.
Each project demonstrates a key concept of IoT connectivity, sensor interfacing, or cloud integration using ESP32.

⚙️ Hardware Used

ESP32 Development Board

MQ Gas Sensor (MQ-6 or MQ-135)

LCD Display (16x2 / I2C)

GPS Module (NEO-6M)

Relay Module

Jumper Wires, Breadboard, and USB Cable

📡 Project List
No.	Project Title	Description	Key Libraries / Platforms
1	WiFi Connection Test	Connect ESP32 to a WiFi network and print local IP on Serial Monitor.	WiFi.h
2	ThingSpeak Data Logging	Send sensor data (e.g., ADC readings) to ThingSpeak cloud channel.	WiFi.h, ThingSpeak.h
3	MQ Gas Sensor Monitoring	Read gas sensor via ADC, display readings, and alert when above threshold.	analogRead(), Serial.println()
4	MQ Sensor + ThingSpeak + Telegram Alert	Monitor air quality and automatically send Telegram alert if the threshold is exceeded.	WiFi.h, ThingSpeak.h, HTTPClient.h
5	GPS Location Tracking	Display live GPS coordinates, date, and time on Serial Monitor using NEO-6M GPS module.	TinyGPSPlus.h, SoftwareSerial.h
6	Smart Switch using SinricPro	Control home appliances remotely using Alexa/Google Assistant through SinricPro cloud.	SinricPro.h, SinricProSwitch.h
🔌 Connections Example (MQ6 Gas Sensor)
ESP32 Pin	MQ6 Pin	Description
32	AO	Analog output to ADC
3V3	VCC	Power supply
GND	GND	Ground
☁️ Cloud Platforms Used

ThingSpeak: IoT data logging and visualization.

Telegram Bot API: Real-time alerts and notifications.

SinricPro: Voice assistant integration for smart home control.

🧰 Software Requirements

Arduino IDE (v2.x or later)

ESP32 Board Package Installed

Required Libraries:

WiFi.h

ThingSpeak.h

HTTPClient.h

TinyGPSPlus.h

SinricPro.h

🚀 How to Run

Open Arduino IDE → Select ESP32 Dev Module.

Connect your ESP32 via USB.

Open any .ino file from this folder.

Update your WiFi SSID, Password, and API keys as required.

Upload and open the Serial Monitor (115200 baud).

📈 Learning Outcomes

Establish WiFi connectivity and cloud data communication.

Read and process analog sensor data.

Automate cloud alerts using APIs (Telegram, ThingSpeak).

Control IoT devices using Alexa/Google Assistant (SinricPro).

Parse GPS data and integrate with location-based IoT systems.
