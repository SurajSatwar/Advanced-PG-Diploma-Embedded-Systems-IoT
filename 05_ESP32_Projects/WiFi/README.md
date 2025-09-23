ESP32 WiFi Connection Example

This project demonstrates how to connect an ESP32 board to a WiFi network and display its local IP address using the Arduino IDE.

📌 Components Required

ESP32 Development Board

USB Cable (for programming)

WiFi network (2.4 GHz)

Arduino IDE with ESP32 board support

⚡ Circuit Connections

No external components are required for this project.
Just connect your ESP32 board to your computer using a USB cable.

💻 Code Explanation
#include <WiFi.h>

// WiFi credentials
const char *ssid = "184527";       // WiFi SSID
const char *pass = "184527184527"; // WiFi Password

WiFiClient Client;

void setup() {
  Serial.begin(115200);

  // Check WiFi status and connect
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      delay(5000);
      Serial.println(".");
    }
    Serial.print("Connected to WiFi! ");
  }

  // Print local IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(100);
}

📊 Working Principle

The ESP32 tries to connect to the WiFi network using the provided SSID and password.

While connecting, "." is printed on the Serial Monitor every 5 seconds.

Once connected, the ESP32 prints "Connected to WiFi!" and displays its local IP address.

The loop does not perform extra tasks here (only a short delay).

🔧 Required Libraries

WiFi.h (built-in with ESP32 board package in Arduino IDE)

🚀 How to Run

Install Arduino IDE and add ESP32 board support from Board Manager.

Select your ESP32 board and the correct COM port.

Replace ssid and pass with your WiFi credentials.

Upload the code.

Open Serial Monitor at 115200 baud rate.

Observe connection logs and note the ESP32’s local IP address.

📈 Applications

IoT projects requiring WiFi connectivity

Home automation systems

Data logging and monitoring via cloud platforms (ThingSpeak, Blynk, MQTT, etc.)
