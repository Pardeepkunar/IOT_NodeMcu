
//*****************************LED ON AND OFF (Control by Blynk)***********************
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";  //code sent via email

void setup()
{
  Serial.begin(9600);
 pinMode(D0,OUTPUT);
  Blynk.begin(auth, "pardeep", "12345678");  //wifi name and password
}
void loop()
{ 
  Blynk.run();
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.println(pinValue);
  if(pinValue == 1)
  {
    digitalWrite(D0,HIGH);
  }
  else
  {
    digitalWrite(D0,LOW);
  }
}

