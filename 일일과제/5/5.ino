//일일과제

const int BUZZER = 10;
const int melody[8] = {
  262, 294, 330, 349, 393, 440, 494, 523,
};

const int trig_pin = 11;
const int echo_pin = 12;

int count = 0;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(115200);

}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);
  long distance = (duration/2) / 29.1;

  Serial.print(distance);
  Serial.println(" cm");

  if(distance <= 10){
    count = 0;
  }
  
  if(distance > 10 && count ==0){
    for(int note=0;note<=7;note++){
      tone(BUZZER, melody[note]);
      delay(500);
    }
    
    noTone(BUZZER);
    count++;
  }
}
