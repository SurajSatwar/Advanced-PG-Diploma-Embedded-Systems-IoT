#include <WiFi.h>
#include "ThingSpeak.h"
#include <HTTPClient.h>


const char* ssid     = "Redmi 13C";
const char* password = "pramod14";


WiFiClient client;
unsigned long myChannelNumber = 3096094;  
const char* myWriteAPIKey = "1Y571ABE8VDFN4NU";


String BOTtoken = "8077828265:AAEBfUXKmaHlMvkCrePQw0G0_zsJelm2YD4";  // Bot Token
String chat_id  = "6024942591";             


int gasSensorPin = 34;   
int gasValue = 0;
int threshold = 200;    

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  ThingSpeak.begin(client);
}

void loop() {
  // Read gas sensor
  gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  // Send to ThingSpeak
  int writeSuccess = ThingSpeak.writeField(myChannelNumber, 1, gasValue, myWriteAPIKey);
  if (writeSuccess == 200) {
    Serial.println("Data sent to ThingSpeak successfully");
  } else {
    Serial.println("Error sending data to ThingSpeak");
  }

  // If threshold exceeded, send Telegram alert
  if (gasValue > threshold) {
    sendTelegramMessage("ALERT");
  }

  delay(20000);  
}

void sendTelegramMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + BOTtoken +
                 "/sendMessage?chat_id=" + chat_id +
                 "&text=" + message;

    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode == 200) {
      Serial.println("Telegram message sent successfully");
    } else {
      Serial.print("Error sending Telegram message, code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}
