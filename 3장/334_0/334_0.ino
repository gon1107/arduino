//p.171

const int ledPin = 10;
const int analogPin = A0;//const int A0=?;

void setup() {   
}

void loop() {
  int sensorInput = analogRead(analogPin);
  analogWrite(ledPin, sensorInput/4);
}
