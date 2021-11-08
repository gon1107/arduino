//p.349 _millis 함수로 LED 점멸 반복해보기

const int LED = 13;

void setup() {  
  pinMode(LED, OUTPUT);
}

void loop() {
  for(int on_off = 0; on_off <= 1; on_off++){
    digitalWrite(LED, on_off);
    delay(500);
  }
}
