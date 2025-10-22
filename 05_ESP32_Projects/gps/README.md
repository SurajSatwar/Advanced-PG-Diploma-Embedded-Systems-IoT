🛰️ GPS Location Tracker using TinyGPS++ and Arduino/ESP32

This project demonstrates how to interface a GPS module (e.g., NEO-6M) with an Arduino or ESP32 to read and display real-time latitude, longitude, date, and time using the TinyGPSPlus library.

📌 Features

✅ Reads and decodes GPS NMEA sentences
✅ Displays latitude, longitude, date, and time on Serial Monitor
✅ Detects if the GPS module is not connected
✅ Compact and efficient code using TinyGPS++ library

🧰 Components Required
Component	Quantity	Description
Arduino UNO / ESP32	1	Microcontroller board
GPS Module (e.g., NEO-6M)	1	Provides satellite location data
Jumper Wires	—	For connections
Breadboard	1	For prototyping
USB Cable	1	For programming
⚡ Circuit Connections
GPS Module Pin	Arduino/ESP32 Pin	Description
VCC	3.3V / 5V	Power supply
GND	GND	Ground
TX	Pin 4	Transmit data (connects to RXPin)
RX	Pin 5	Receive data (connects to TXPin)

⚠️ Note: GPS TX → Microcontroller RX and GPS RX → Microcontroller TX (cross connection).
Make sure the baud rate (9600) matches your GPS module’s configuration.

💻 Code Explanation
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);
}

void loop() {
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS detected: check wiring."));
    while (true);
  }
}

void displayInfo() {
  Serial.print(F("Location: "));
  if (gps.location.isValid()) {
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date/Time: "));
  if (gps.date.isValid()) {
    Serial.printf("%02d/%02d/%04d ", gps.date.month(), gps.date.day(), gps.date.year());
  } else {
    Serial.print(F("INVALID "));
  }

  if (gps.time.isValid()) {
    Serial.printf("%02d:%02d:%02d.%02d", gps.time.hour(), gps.time.minute(), gps.time.second(), gps.time.centisecond());
  } else {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}

🧠 Working Principle

The GPS module continuously transmits NMEA sentences containing location and time data.

The SoftwareSerial interface reads this data on pins 4 (RX) and 5 (TX).

The TinyGPS++ library decodes these sentences to extract:

Latitude and Longitude

Date and Time (UTC)

Data is printed on the Serial Monitor in readable format.

If no GPS data is detected after 5 seconds, an error message appears.

🔧 Required Libraries

Install the following from Arduino IDE → Library Manager:

TinyGPSPlus by Mikal Hart

SoftwareSerial (included by default with Arduino IDE)

🚀 How to Run

Connect GPS module as per the circuit diagram.

Open Arduino IDE and select your board and COM port.

Copy and upload the code.

Open Serial Monitor → Set baud rate to 115200.

Place the GPS module near an open sky for best signal.

Watch latitude, longitude, date, and time update live.

📊 Example Output
Location: 12.971599,77.594566  Date/Time: 10/22/2025 14:32:12.00
Location: 12.971602,77.594569  Date/Time: 10/22/2025 14:32:13.00


If GPS is not detected:

No GPS detected: check wiring.

🧩 Applications

Vehicle or asset tracking systems

GPS-based navigation projects

IoT geo-location devices

Data logging and mapping applications

⚙️ Notes

Keep GPS antenna facing open sky for accurate results.

First GPS fix may take 30–60 seconds.

You can easily extend this project to send coordinates to ThingSpeak, Blynk, or Telegram.
