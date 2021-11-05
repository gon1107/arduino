//p.274 함수로 만들기

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};

void display_clear(){
  for(int x=0;x<7;x++){
    digitalWrite(led[x], LOW);
  }  
}

void display_init(){
  for(int x=0;x<7;x++){
    pinMode(led[x], OUTPUT);
  }
}

void setup() {
  display_init();
}

void loop() {
  for(int x=0;x<7;x++){
    display_clear();
    
    digitalWrite(led[x], HIGH);
  
    delay(500);
  }
}
