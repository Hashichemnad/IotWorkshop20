#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

char auth[] = "BREva_4dVcoBfdnQ_aZxTj60QAPcviFn";

char ssid[] = "hashichemnad";
char pass[] = "passwords";

WidgetLCD lcd(V1);

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Blynk.begin(auth, ssid, pass);

  lcd.clear(); 
  lcd.print(0, 0, "Distance in cm"); 
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Distance in cm"); 
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);
  Blynk.run();

  delay(3500);

}
