//p.351 _millis LED 밝기 조절해보기

const int LED = 10;

void setup() {  

}

void loop() {
  for(int t_high=0;t_high<=255;t_high++){
    analogWrite(LED, t_high);
    delay(4);
  }
}
