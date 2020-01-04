
//*****************************using Switch(led on and off by Blynk)***********************
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";  //code sent via email
WidgetLED led1(V2);

void setup()
{
  Serial.begin(9600);
 pinMode(D1,INPUT);
  
  Blynk.begin(auth, "pardeep", "12345678");  //wifi name and password
}
void loop()
{ 
  Blynk.run();
 
  int deep = digitalRead(D1);
  if(deep == HIGH)
    {
      led1.on();
      Serial.print(deep); 
    }
    else
    {
      
      led1.off();
    }
  delay(1000);
 }

