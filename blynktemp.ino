#define BLYNK_PRINT Serial 
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "Uwzx0MganUB9F_r24R6HW7N1CORDmmG2";
char ssid[] = "hashichemnad";
char pass[] = "passwords";

#define DHTPIN 2 

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;


void sendSensor()
{
 float h = dht.readHumidity();
 float t = dht.readTemperature(); 

 if (isnan(h) || isnan(t)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 
 Blynk.virtualWrite(V5, h); // Humidity for gauge
 Blynk.virtualWrite(V6, t); // Temperature for gauge
}

void setup()
{
 Serial.begin(115200);
 Blynk.begin(auth, ssid, pass);

 dht.begin();

 timer.setInterval(1000L, sendSensor);
}

void loop()
{
 Blynk.run(); // Initiates Blynk
 timer.run(); // Initiates SimpleTimer
  float h = dht.readHumidity();
 float t = dht.readTemperature(); 
 Serial.println(h);
 Serial.println(t);
 delay(1000);
}
