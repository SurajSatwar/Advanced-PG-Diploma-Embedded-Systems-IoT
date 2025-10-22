🔌 ESP32 Smart Switch using Sinric Pro
📘 Project Overview

This project demonstrates how to control a relay (or any electronic appliance) remotely using the ESP32 and Sinric Pro IoT platform. The device connects to Wi-Fi and allows control through the Sinric Pro mobile app or voice assistants like Alexa and Google Assistant.

🧠 Features

Connect ESP32 to Wi-Fi and Sinric Pro cloud.

Control a relay (ON/OFF) using Sinric Pro mobile app or Alexa/Google.

Real-time synchronization between device and app.

Works even after reconnection or reboot.

⚙️ Hardware Components
Component	Quantity	Description
ESP32 Dev Board	1	Main microcontroller
Relay Module	1	To control AC/DC appliances
Jumper Wires	—	For connections
Power Supply	1	5V or USB power for ESP32
🧩 Circuit Connections
ESP32 Pin	Component	Description
GPIO 2	Relay IN	Controls relay state
3.3V	Relay VCC	Power supply
GND	Relay GND	Common ground
🔑 Sinric Pro Setup

Go to Sinric Pro Dashboard
.

Create a new Switch device.

Copy the Device ID, App Key, and App Secret.

Replace these values in the Arduino code:

#define APP_KEY "your_app_key_here"
#define APP_SECRET "your_app_secret_here"
#define SWITCH_ID "your_device_id_here"


Use the Sinric Pro mobile app to link and control your device.

💻 Arduino Code Explanation
1. Libraries Used
#include <WiFi.h>
#include "SinricPro.h"
#include "SinricProSwitch.h"


WiFi.h → Handles Wi-Fi connection.

SinricPro.h → Core library for Sinric Pro IoT platform.

SinricProSwitch.h → Provides support for switch-type devices.

2. Wi-Fi Connection
WiFi.begin(WIFI_SSID, WIFI_PASS);
while (WiFi.status() != WL_CONNECTED) {
  delay(250);
}


This code connects your ESP32 to your home Wi-Fi network.

3. Sinric Pro Device Setup
SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];
mySwitch.onPowerState(onPowerState);
SinricPro.begin(APP_KEY, APP_SECRET);


Registers your device and defines the behavior when ON/OFF commands are received.

4. Relay Control Callback
bool onPowerState(const String &deviceId, bool &state) {
  digitalWrite(RELAY_PIN, state);
  return true;
}


Turns the relay ON when the state is true, and OFF when false.

📲 Usage

Upload the code to your ESP32 using Arduino IDE.

Open the Serial Monitor (115200 baud) to see connection logs.

Once connected, open the Sinric Pro App → Tap the switch → The relay toggles ON/OFF.

You can also control it using Alexa or Google Assistant (link Sinric Pro skill/service).

🧪 Example Output (Serial Monitor)
Connecting to WiFi...
Connected to WiFi
Connected to Sinric Pro
Switch toggled ON
Switch toggled OFF

⚠️ Notes

Make sure the relay module operates safely (use opto-isolated type for AC loads).

Double-check your wiring to avoid short circuits.

Use a 5V power supply for stable operation.

🧾 License

This project is open-source and available for educational use.
