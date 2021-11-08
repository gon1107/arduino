//추가 실습 _millis 함수로 LED 점멸 반복해보기

const int led[2] = {12, 13};
int on_off[2] = {0, 0};
//int on_off = 0;

unsigned long t_prev[2] = {0, 0};
const unsigned long t_delay[2] = {500, 250};

void setup() {
  for(int x=0;x<=1;x++){
    pinMode(led[x], OUTPUT); 
  }
}

void loop() {
  for(int i=0; i<=1;i++){
    unsigned long t_now = millis();
    if(t_now - t_prev[i] >= t_delay[i]){
      t_prev[i] = t_now;
  
      on_off[i]++;
      if(on_off[i]>1)
        on_off[i] = 0;
      digitalWrite(led[i], on_off[i]);
    }
  }
}
