#include "DHT.h"

//sensors
#define DHTPIN 2 
#define LEDPIN 13
#define DHTTYPE DHT22
    

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  dht.begin();
}

void loop() {

  delay(3000);
//humidity check
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    Serial.println("Sensor read error");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
//LED operations
  if (humidity < 30) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}