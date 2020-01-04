//***************water plant notification****************

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";  //code sent via email
const int sensorPin = D4; 
WidgetLED led1(V2);
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "Google", "123456788");  //wifi name and password
  pinMode(sensorPin, INPUT);
}

void loop()
{ 
  Blynk.run();
int sensorState = digitalRead(sensorPin);
 Serial.println(sensorState);

if (sensorState == LOW) {
   Blynk.notify("pump start");
   led1.on();
  delay(1000);
   } 
  else
  {   
    Serial.println("does not need water");
     led1.off();
    delay(1000);
  }
}
