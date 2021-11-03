//p.234

#include <TimerOne.h>

const int BUZZER = 10;

void setup() {
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);

  Timer1.setPwmDuty(BUZZER, 512); //0~1023

  Timer1.setPeriod(1000000/262); //262Hz

  delay(3000);

  Timer1.setPwmDuty(BUZZER, 0);
}

void loop() {

}
