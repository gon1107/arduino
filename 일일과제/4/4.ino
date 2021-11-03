//일일과제

#include <Servo.h>

const int SERVO = 10;
Servo servo;
const int analogPin = A0;
int count = 1;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorInput = analogRead(analogPin);
  int delayTime = 500 + 1023 - sensorInput;
  
  if(count == 0){
    servo.detach();
  }  
  else if(count == 1){
    servo.attach(SERVO);
  }
  Serial.println(sensorInput);
  if(sensorInput <= 100){
    count = 0;
  }
  else{
    count++;
  }

  servo.write(0);
  delay(delayTime); 
  servo.write(180);
  delay(delayTime); 
}
