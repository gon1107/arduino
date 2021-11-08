//일일과제 (공통 양극 4자리 7세그먼트)

#include "PinChangeInterrupt.h"

int count = 0;

const int button = 13;
bool segment_state_changed = false;

const unsigned int led[7] = {2, 3, 4, 5, 6, 7, 8};
const unsigned int com[1+4] = {-1, 9, 10, 11, 12};

const unsigned int num[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, /* 0 */
  { 0, 1, 1, 0, 0, 0, 0 }, /* 1 */
  { 1, 1, 0, 1, 1, 0, 1 }, /* 2 */
  { 1, 1, 1, 1, 0, 0, 1 }, /* 3 */
  { 0, 1, 1, 0, 0, 1, 1 }, /* 4 */
  { 1, 0, 1, 1, 0, 1, 1 }, /* 5 */
  { 1, 0, 1, 1, 1, 1, 1 }, /* 6 */
  { 1, 1, 1, 0, 0, 1, 0 }, /* 7 */
  { 1, 1, 1, 1, 1, 1, 1 }, /* 8 */
  { 1, 1, 1, 1, 0, 1, 1 }  /* 9 */         
};

void display_init(){
  for(int x=0;x<7;x++){
    pinMode(led[x], OUTPUT);
  }
  for(int y=1;y<=4;y++){
    pinMode(com[y], HIGH);
  }
}

void display_clear(){
  for(int x=0;x<7;x++){
    digitalWrite(led[x], HIGH); //공통양극, 음극이면 LOW일 때 꺼짐
  }
  for(int y=1;y<=4;y++){
    digitalWrite(com[y], LOW); //공통양극, 음극이면 HIGH일 때 켜짐
  }
}

void display_number(unsigned int n, unsigned int m){
  display_clear();
  if(0<=n&&n<=9 && 1<=m&&m<=4){
    for(int x=0;x<7;x++){
      digitalWrite(led[x], num[n][x] == 1 ? LOW : HIGH); // 공통양극
    }
    digitalWrite(com[m], HIGH); //공통양극
  }
}

void display_numbers(unsigned int num){
  unsigned int num_1000 = count%10;
  unsigned int num_100 = 0;
  unsigned int num_10 = (num%100)/10;
  unsigned int num_1 = num%10;

  
  display_number(num_1000, 1);
  delay(1);
  display_number(num_100, 2);
  delay(1);
  display_number(num_10, 3);
  delay(1);
  display_number(num_1, 4);
  delay(1);
}

void buttonPressed(){
  segment_state_changed = true;
}

void setup() {
  Serial.begin(115200);
  display_init();
  attachPCINT(digitalPinToPCINT(button), buttonPressed, RISING);
}

void loop() {
  static unsigned int num = 0;
  
  if(segment_state_changed){
    segment_state_changed = false;
    num++;
    if(num%16 == 0){
      count++;
      num = 0;
    }
  }
  display_numbers(num);
}
