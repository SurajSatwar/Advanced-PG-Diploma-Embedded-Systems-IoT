
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // msp430g2231 must use 4800
}

// the loop routine runs over and over again forever:
void loop() {
  
  int sensorValue = analogRead(A3);
  
  float voltage = sensorValue * (3.0 / 1023.0);  
  Serial.println(voltage);
  Serial.println(sensorValue);
  delay(500);

  
  
}
