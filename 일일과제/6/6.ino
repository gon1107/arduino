//일일과제

#include "PinChangeInterrupt.h"

int pre_count = 0;
int count = 0;

//int buzzer_state = LOW;
bool buzzer_state_changed = false;

const int ACTIVE_BUZZER = 11;
const int BUZZER = 10;
const int button[4] = {2, 3, 4, 5};

const int max_quiz = 2;

const char *questions[max_quiz] = {
  "문제 1) 다음 중 컴퓨터의 기능이 아닌 것은?\n",
  "문제 2) 기록되어 있는 자료를 읽기만 가능한 기억 장치는?\n",
};

const char *options[max_quiz] = {
  "1. 출력기능\t2. 입력기능\n3. 연산기능\t4. 판단기능\n",
  "1. 롬(ROM)\t2. 램(RAM)\n3. 하드디스크\t4. 모니터\n",
};

const int answers[max_quiz] = {4, 3};

char note[] = "ggaaggeggeed ggaaggegedec ";
char beat[] = "11111121111221111112111122";
int note_length = sizeof(note)/sizeof(note[0])-1;

int tempo = 300;

int freq(char note){
  char note_name[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C',};
  int note_freq[] = {262, 294, 330, 349, 393, 440, 494, 523};

  for(int i=0;i<sizeof(note_name)/sizeof(note_name[0]);i++){
    if(note_name[i] == note){
      return note_freq[i];
    }
  }
}

int duration(char beat){
  return beat - '0';
}

void buttonPressed0() {
  pre_count = count;
  buzzer_state_changed = true;
 
  if (answers[count] == 1){
    count++;      
  }
}

void buttonPressed1() {
  pre_count = count;
  buzzer_state_changed = true;
  
  if (answers[count] == 2){
    count++;        
  }
}

void buttonPressed2() {
  pre_count = count;
  buzzer_state_changed = true;
  
  if (answers[count] == 3){
    count++;        
  }  
}

void buttonPressed3() {
  pre_count = count;
  buzzer_state_changed = true;
  
  if (answers[count] == 4){
    count++;  
  }
}

// 함수 포인터 배열
void (*fp[4])() = {buttonPressed0, buttonPressed1, buttonPressed2, buttonPressed3};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  
  pinMode(ACTIVE_BUZZER, OUTPUT);

  for(int n=0;n<=3;n++){
    pinMode(button[n], INPUT);
  }

//  attachPCINT(digitalPinToPCINT(button[0]), buttonPressed0, RISING);
//  attachPCINT(digitalPinToPCINT(button[1]), buttonPressed1, RISING);
//  attachPCINT(digitalPinToPCINT(button[2]), buttonPressed2, RISING);
//  attachPCINT(digitalPinToPCINT(button[3]), buttonPressed3, RISING);    

  for(int i=0; i < 4; i++){
    if(button[i] == 2 || button[i] == 3){
      attachInterrupt(digitalPinToInterrupt(button[i]), fp[i], RISING);
    }else{
      attachPCINT(digitalPinToPCINT(button[i]), fp[i], RISING);      
    }
  }
  
  Serial.print(questions[count]);
  Serial.print(options[count]);
}

void loop() {
  if(buzzer_state_changed){
    buzzer_state_changed = false;
        
    if(count == pre_count + 1){
      for(int i=0;i<note_length;i++){
        if(note[i] != ' '){
          tone(BUZZER, freq(note[i]));  
        }
        delay(tempo*duration(beat[i]));
        
        noTone(BUZZER);
        delay(100);
      }
    
      if(count != max_quiz){
        Serial.print(questions[count]);
        Serial.print(options[count]);                  
      }
    }
    else{
      digitalWrite(ACTIVE_BUZZER, HIGH);
      delay(3000);
      digitalWrite(ACTIVE_BUZZER, LOW);
    }     
  }
}
