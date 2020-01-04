#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


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
   
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}


