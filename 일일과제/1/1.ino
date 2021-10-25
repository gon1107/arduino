//p.137

const unsigned int led[6] = {3, 5 ,6, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    char userInput = Serial.read();
    int num = Serial.parseInt();
    char enter = Serial.read();

    if(userInput == 'r'){
      for(int i=1;i<=num;i++){
        for(int n=5;n>=0;n--){
          for(int t_high=0;t_high<=255;t_high++){
            analogWrite(led[n], t_high);
            delay(2);
          }
        }
        
        for(int n=0;n<=5;n++){
          for(int t_high=255;t_high>=0;t_high--){
            analogWrite(led[n], t_high);
            delay(2);
          }
        }
      
        delay(500);
      }
    }
    else if(userInput == 'l'){
      for(int i=1;i<=num;i++){
        for(int n=0;n<=5;n++){
          for(int t_high=0;t_high<=255;t_high++){
            analogWrite(led[n], t_high);
            delay(2);
          }
        }
      
        for(int n=5;n>=0;n--){
          for(int t_high=255;t_high>=0;t_high--){
            analogWrite(led[n], t_high);
            delay(2);
          }
        }
      
        delay(500);
      }
    }
  }
}
