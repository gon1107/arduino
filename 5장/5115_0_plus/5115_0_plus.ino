//스위치를 누르면 1씩 증가

#include "PinChangeInterrupt.h"

bool segment_state_changed = false;
  
const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};

const unsigned int num[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1},          
};

const int button = 10;
int count = 0;

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

void display_number(int n){
  if(0<=n&&n<=9){
    for(int x=0;x<7;x++){
      digitalWrite(led[x], num[n][x] == 1 ? HIGH : LOW);
    }    
  }
}

void buttonPressed(){
  segment_state_changed = true;
}

void setup() {
  Serial.begin(115200);
  display_init();
  pinMode(button, INPUT);

  attachPCINT(digitalPinToPCINT(button), buttonPressed, RISING);  
}

void loop() {
  if(segment_state_changed){
    segment_state_changed = false;
    
    display_clear();  
    display_number(count%10);
    count++;
    
  }
}
