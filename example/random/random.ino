void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  randomSeed(100);

  int randNumber = random(300);//0~299
  Serial.println(randNumber);
  
  int randNumber2 = random(10, 20);//10~19
  Serial.println(randNumber2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
