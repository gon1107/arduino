//p.128

const int LED = 10;

void setup() {

 }

void loop() {
  for(int t_high=0;t_high<=10;t_high++){
      analogWrite(LED, t_high*25);
      delay(100);
  }
}
