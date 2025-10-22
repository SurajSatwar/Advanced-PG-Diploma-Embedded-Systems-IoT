ESP32 ThingSpeak Data Upload Example

This project demonstrates how to connect an ESP32 to a Wi-Fi network and send sensor data (or any test value) to a ThingSpeak IoT cloud channel. It helps you understand how to upload real-time data for visualization, logging, and analysis on the cloud.

📌 Features

✅ Connects ESP32 to WiFi automatically
✅ Sends data to ThingSpeak every 20 seconds
✅ Checks connection and reconnects if disconnected
✅ Displays status on Serial Monitor

🧰 Components Required
Component	Quantity	Description
ESP32 Board	1	WiFi-enabled microcontroller
USB Cable	1	For programming ESP32
Laptop/PC	1	For code upload
WiFi Network	1	2.4 GHz network preferred
💻 Code Explanation
#include <WiFi.h>
#include "ThingSpeak.h" // Include after WiFi.h

// WiFi credentials
char ssid[] = "184527";
char pass[] = "184527184527";

WiFiClient client;

// ThingSpeak channel details
unsigned long myChannelNumber = 3071490;
const char *myWriteAPIKey = "6DPGGJCT5AGZ6HGR";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // Connect to WiFi if not connected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  // Send data to ThingSpeak
  int x = ThingSpeak.writeField(myChannelNumber, 1, 100, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  delay(20000); // Wait 20 seconds before next update
}

⚡ How It Works

ESP32 connects to your WiFi network using SSID and password.

Once connected, it sends a sample data value (100) to Field 1 of your ThingSpeak channel.

The cloud responds with HTTP code 200 if the upload is successful.

The ESP32 waits 20 seconds before sending the next update.

🔧 Required Libraries

Install the following from Arduino IDE Library Manager:

WiFi.h → included with ESP32 board package

ThingSpeak.h → ThingSpeak Arduino Library

🚀 Setup Instructions

Open ThingSpeak
 and create a free account.

Create a new Channel → note down your Channel ID and Write API Key.

Open Arduino IDE → install ESP32 board support via Board Manager.

Select Tools → Board → ESP32 Dev Module and correct COM port.

Replace:

ssid and pass with your WiFi credentials.

myChannelNumber and myWriteAPIKey with your ThingSpeak details.

Upload the code to your ESP32.

Open Serial Monitor (115200 baud) to check connection logs.

Visit your ThingSpeak channel → view live data updates in the graph.

📊 Example Output

Serial Monitor:

Attempting to connect to SSID: 184527
......
Connected.
Channel update successful.


ThingSpeak Dashboard:

Time	Field 1 Value
12:00:00	100
12:00:20	100
12:00:40	100
🧠 Applications

IoT sensor data logging (Temperature, Humidity, Gas, etc.)

Smart agriculture or weather monitoring systems

Remote environmental tracking projects

⚙️ Notes

ThingSpeak allows updates every 15 seconds minimum.

If you send data too fast, it may reject requests with error 400 or 403.

You can extend this code to include multiple fields or real sensor data.
