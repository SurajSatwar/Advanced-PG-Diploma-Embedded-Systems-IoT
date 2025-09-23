//ADC using mq6 sensor wi display range and print data on serial monitor
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); //baud rate
pinMode(2,OUTPUT);
pinMode(32,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int x = analogRead(32);
 if (x>3000) {
  digitalWrite(2, HIGH);
 }
 else {
 {digitalWrite(2, LOW);}
 }


Serial.println(x);
delay(1000);
}