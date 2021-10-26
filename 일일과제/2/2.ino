//일일과제

const int led[6] = {3, 5, 6, 9, 10, 11};
const int analogPin = A0;
int count = 0;

int randNumber = random (683, 341);
int randNumber2 = random (1, 341);
int randNumber3 = random (342, 341);

void setup() {
  randomSeed(1024);
}

void loop() {
  int sensorInput = analogRead(analogPin);

  if(sensorInput==randNumber && count==0){
    analogWrite(led[0], 255);
    count++;
  }

  if(sensorInput==randNumber2 && count==1){
    analogWrite(led[1], 255);
    count++;
  }
  if(sensorInput==randNumber3 && count==2){
    analogWrite(led[2], 255);
    count++;
    for(int n=0;n<=2;n++)
      analogWrite(led[n], 0);
    for(int i=0;i<=2;i++){
      for(int n=0;n<=5;n++){
        analogWrite(led[n], 255);
        delay(200);
      }
      for(int n=5;n>=0;n--){
        analogWrite(led[n], 0);
        delay(200);
      }
    }
  }
}
