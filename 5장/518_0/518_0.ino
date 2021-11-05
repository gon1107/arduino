//p.275 0 숫자 표시하기

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};

const unsigned int num_0[7] = {1, 1, 1, 1, 1, 1, 0};

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
  display_clear();  

  for(int x=0;x<7;x++){
    digitalWrite(led[x], num_0[x] == 1 ? HIGH : LOW);
  }
}

void loop() {

}
