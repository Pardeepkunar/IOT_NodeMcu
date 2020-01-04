// motor speed data show in  Adafruit cloud
#include "config.h"
#define Motor D2
#define potentiometer A0
String deep;
AdafruitIO_Feed *printp = io.feed("printp");
void setup() {
  pinMode(potentiometer,INPUT);
  pinMode(Motor,OUTPUT);
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  while(io.status() < AIO_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  }
void loop() 
{
  io.run();
  int p= analogRead(potentiometer);
  Serial.println(p);
  analogWrite(Motor,p);
  if(p >10)
  {
    deep = "Motor speed High";
    Serial.println(deep);
    delay(2000);
  }
  else if(p <10)
  {
    deep =  "Motor Safe";
    Serial.println(p);
    Serial.println(deep);
    delay(2000);
  }
  printp->save(deep);
  delay(3000);
   }
