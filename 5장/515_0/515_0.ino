//p.270

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for(int x=0;x<7;x++){
    pinMode(led[x], OUTPUT);
  }
}

void loop() {
  for(int x=0;x<7;x++){
    digitalWrite(led[x], HIGH);
  }
  delay(500);
  for(int x=0;x<7;x++){
    digitalWrite(led[x], LOW);
  }
  delay(500);  
}
