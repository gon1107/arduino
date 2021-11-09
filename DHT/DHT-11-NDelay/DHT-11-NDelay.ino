#include "NDelayFunc.h"
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); // DHT 객체를 생성, dht(2, 11)

float h; // humidity;
float t; //temparature;

void readDHT() {
  t = dht.readTemperature();
  h = dht.readHumidity();
  
  Serial.print("Temparature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);
}

NDelayFunc nDelayReadDHT(1000, readDHT);


void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  nDelayReadDHT.run();
}
