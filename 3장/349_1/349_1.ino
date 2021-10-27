//p.199

const int ACTIVE_BUZZER = 9;

void setup() {
  pinMode(ACTIVE_BUZZER, OUTPUT);

  digitalWrite(ACTIVE_BUZZER, HIGH);
  delay(3000);
  digitalWrite(ACTIVE_BUZZER, LOW);
}

void loop() {

}
