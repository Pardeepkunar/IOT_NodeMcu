//***************Temperature control**************

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int temp;

char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";
char ssid[] = "pardeep";
char pass[] = "12345678";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
  
void loop()
{
  Blynk.run();
  temp = analogRead(A0);
  temp = temp * 0.48828125;
  Serial.println(temp);
  Blynk.virtualWrite(V1, temp);
}





