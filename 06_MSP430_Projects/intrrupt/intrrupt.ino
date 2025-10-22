const byte ledPin = P1_6;
const byte interruptPin = P1_3;
volatile byte state = LOW;

void setup() {
  pinMode (ledPin, OUTPUT);
  pinMode (interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);

}

void loop() {
  digitalWrite(ledPin, state);
}
 void blink() {
  state = !state;
 }
