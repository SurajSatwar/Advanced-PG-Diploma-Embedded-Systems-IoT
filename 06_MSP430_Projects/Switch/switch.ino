void setup() {
  pinMode(P1_3, INPUT_PULLUP);
  pinMode(P1_6, OUTPUT);
  

}

void loop() {
 int x=digitalRead(P1_3);
 if (x==0)
 {
  digitalWrite(P1_6, HIGH);
  }
  else
  {
    digitalWrite(P1_6, LOW);
    }
}
