//p.346 _millis 함수로 delay 대체하기

unsigned long t_prev = 0;
const unsigned long t_delay = 1000;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long t_now = millis();
  if(t_now - t_prev >= t_delay){
    t_prev = t_now;
    Serial.println(t_now);
  }
  //delay(1000);
}
