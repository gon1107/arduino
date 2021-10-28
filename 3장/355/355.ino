//p.208

#include <Servo.h>

const int SERVO = 10;
Servo servo;

void setup() {
  servo.attach(SERVO);

  for(int cnt=0;cnt<=2;cnt++){
    for(int angle=0;angle<=180;angle++){
      servo.write(angle);
      delay(20);
    }
    delay(1000);
  }
  
  servo.detach();
}

void loop() {

}
