#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float h; // humidity;
float t; //temparature;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temparature: ");
  Serial.println(t);

  delay(1000);
}
