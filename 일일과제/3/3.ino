//일일과제

int count = 0;

const int ACTIVE_BUZZER = 9;
const int BUZZER = 10;
const int button[4] = {2, 3, 4, 5};

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ACTIVE_BUZZER, OUTPUT);

  for(int n=0;n<=3;n++){
    pinMode(button[n], INPUT);
  }
  Serial.println("문제 1) 다음 중 컴퓨터의 기능이 아닌 것은?");
  Serial.println("1. 출력기능  2. 입력기능");
  Serial.println("3. 연산기능  4. 판단기능");
}

void loop() {
  if(count == 0){
    if(digitalRead(button[0])==HIGH || digitalRead(button[1])==HIGH || digitalRead(button[2])==HIGH){
      digitalWrite(ACTIVE_BUZZER, HIGH);
      delay(3000);
      digitalWrite(ACTIVE_BUZZER, LOW);
    }
    else if(digitalRead(button[3])==HIGH){
      count++;

      Serial.println("문제 1) 다음 중 컴퓨터 언어가 아닌 것은?");
      Serial.println("1. python  2. java");
      Serial.println("3. c--  4. c++");
      
      for(int i=0;i<note_length;i++){
        if(note[i] != ' '){
          tone(BUZZER, freq(note[i]));  
        }
        delay(tempo*duration(beat[i]));
        
        noTone(BUZZER);
        delay(100);
      }
    }
  }
  
  if(count == 1){
    if(digitalRead(button[0])==HIGH || digitalRead(button[1])==HIGH || digitalRead(button[3])==HIGH){
    
      digitalWrite(ACTIVE_BUZZER, HIGH);
      delay(3000);
      digitalWrite(ACTIVE_BUZZER, LOW);
    }
    else if(digitalRead(button[2])==HIGH){
      count=0;

      Serial.println("문제 1) 다음 중 컴퓨터의 기능이 아닌 것은?");
      Serial.println("1. 출력기능  2. 입력기능");
      Serial.println("3. 연산기능  4. 판단기능");

      for(int i=0;i<note_length;i++){
        if(note[i] != ' '){
          tone(BUZZER, freq(note[i]));  
        }
        delay(tempo*duration(beat[i]));
        
        noTone(BUZZER);
        delay(100);
      }
    }
  }
}
