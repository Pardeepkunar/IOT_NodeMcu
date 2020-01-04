//*****************************potentiometer*****************
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int sensor = A0;
char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";
char ssid[] = "pardeep";
char pass[] = "12345678";

void setup()
{
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  int a = analogRead(sensor);
  Blynk.virtualWrite(V0,a);
  Blynk.run();
}

