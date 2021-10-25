//p.137

const unsigned int led[6] = {3, 5 ,6, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
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
