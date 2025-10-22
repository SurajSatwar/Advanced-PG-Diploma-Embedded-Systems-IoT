ESP32 Gas Sensor Monitoring with ThingSpeak and Telegram Alert

This project uses an ESP32 to monitor gas levels via an MQ gas sensor and upload data to ThingSpeak Cloud for visualization.
If the gas concentration crosses a set threshold, an instant alert message is sent to a Telegram bot.

📌 Features

✅ Real-time gas monitoring using ESP32 ADC
✅ Cloud logging to ThingSpeak for analysis and graphs
✅ Telegram alert notification for threshold breach
✅ WiFi-based IoT automation system

🧰 Components Required
Component	Quantity	Description
ESP32 Board	1	Main microcontroller with WiFi
MQ Gas Sensor (MQ-2 / MQ-6)	1	Detects LPG, butane, or methane gases
Jumper Wires	—	For connections
Breadboard	1	For prototyping
USB Cable	1	For programming ESP32
⚡ Circuit Connections
MQ Sensor Pin	ESP32 Pin	Description
VCC	5V	Power supply
GND	GND	Ground
AOUT	GPIO 34	Analog output signal
💻 Code Explanation
#include <WiFi.h>
#include "ThingSpeak.h"
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "Redmi 13C";
const char* password = "pramod14";

// ThingSpeak details
WiFiClient client;
unsigned long myChannelNumber = 3096094;
const char* myWriteAPIKey = "1Y571ABE8VDFN4NU";

// Telegram bot details
String BOTtoken = "BOT_TOKEN";  // Replace with your Telegram Bot token
String chat_id  = "CHAT_ID";    // Replace with your chat ID

int gasSensorPin = 34;
int gasValue = 0;
int threshold = 200;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  ThingSpeak.begin(client);
}

void loop() {
  gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  // Upload data to ThingSpeak
  int writeSuccess = ThingSpeak.writeField(myChannelNumber, 1, gasValue, myWriteAPIKey);
  if (writeSuccess == 200)
    Serial.println("Data sent to ThingSpeak successfully");
  else
    Serial.println("Error sending data to ThingSpeak");

  // Send Telegram alert if threshold exceeded
  if (gasValue > threshold)
    sendTelegramMessage("⚠️ Gas Level High! Take Action Immediately!");

  delay(20000); // Send data every 20 seconds
}

void sendTelegramMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + BOTtoken +
                 "/sendMessage?chat_id=" + chat_id + "&text=" + message;
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode == 200)
      Serial.println("Telegram message sent successfully");
    else
      Serial.println("Error sending Telegram message");
    http.end();
  }
}

🌐 How It Works

ESP32 connects to WiFi using the given SSID and password.

Gas sensor continuously reads analog data (gas concentration).

The readings are uploaded to ThingSpeak Channel Field 1 every 20 seconds.

If gas value exceeds the threshold, a Telegram bot alert is sent instantly.

🔧 Required Libraries

Install these from Arduino IDE Library Manager:

WiFi.h → Built-in with ESP32 core

ThingSpeak.h → ThingSpeak Arduino Library

HTTPClient.h → Built-in with ESP32 core

🚀 Setup Instructions

Create a ThingSpeak account → ThingSpeak.com

Create a new channel and note down your Channel ID and Write API Key.

Create a Telegram Bot → Using BotFather

Get your Bot Token and Chat ID.

Edit the code with your:

WiFi credentials

ThingSpeak channel info

Telegram bot token and chat ID

Upload the code to ESP32 using Arduino IDE.

Open Serial Monitor (115200 baud) → Observe gas values and connection status.

Check ThingSpeak channel for real-time graph.

Receive Telegram alert when gas level > threshold.

📊 Example ThingSpeak Output
Time	Gas Value
10:00:00	120
10:00:20	180
10:00:40	⚠️ 250 (Alert Triggered)
🧠 Applications

Smart home gas leakage alert system

Industrial safety and monitoring

IoT-based environmental data logging

⚠️ Safety Note

Always handle gas sensors in a well-ventilated environment. Avoid exposure to open flames or pressurized gases during testing.
