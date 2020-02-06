#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BREva_4dVcoBfdnQ_aZxTj60QAPcviFn";

char ssid[] = "hashichemnad";
char pass[] = "passwords";

WidgetLED led1(1);
#define IR D7
bool ir;
void setup() {
Serial.begin(9600);
pinMode(IR, INPUT);
Blynk.begin(auth, ssid, pass);
}
void loop() {
ir = digitalRead(IR);
if(ir == 1)
{
 Serial.println("No Object");
 led1.off();
}
else if (ir == 0)
{
 Serial.println("Object Detected");
 led1.on();
}

Blynk.run();
}
