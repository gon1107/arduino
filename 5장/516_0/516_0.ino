//p.271

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for(int x=0;x<7;x++){
    pinMode(led[x], OUTPUT);
  }
}

void loop() {
  for(int x=0;x<7;x++){
    for(int y=0;y<7;y++){
      digitalWrite(led[y], LOW);
    }
  
    digitalWrite(led[x], HIGH);
  
    delay(500);  // 1/3.5 = 0.286Hz(50Hz 이하이기 때문에)
//    delay(1); // 1/0.007 = 143Hz
  }
}
