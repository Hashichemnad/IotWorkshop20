#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Uwzx0MganUB9F_r24R6HW7N1CORDmmG2";
char ssid[] = "hashichemnad";
char pass[] = "passwords";

void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

}
void loop()
{
  Blynk.run();
}
