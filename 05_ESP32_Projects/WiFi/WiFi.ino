#include<WiFi.h>

const char *ssid="184527";
const char *pass="184527184527";
WiFiClient Client;
void setup(){
  Serial.begin(115200);
  if(WiFi.status()!=WL_CONNECTED)
{
 WiFi.begin(ssid,pass);
 while (WiFi.status()!=WL_CONNECTED)
 {
  WiFi.begin(ssid,pass);
  delay(5000);
  Serial.println(".");
 }
 Serial.print("connected");
 }
 Serial.println(WiFi.localIP());
 }

  void loop(){
    delay(100);
  }