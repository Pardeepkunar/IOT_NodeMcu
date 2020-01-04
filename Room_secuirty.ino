#include "config.h"   // Room security light on and off automatic
#define BUTTON_PIN A0
#define BUTTON_PIN1 D2
String deep;
int cou = 0;

AdafruitIO_Feed *printp = io.feed("printp");
AdafruitIO_Feed *counter = io.feed("counter");
void setup() {

  pinMode(BUTTON_PIN, INPUT);
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
void loop() {
  io.run();
  int p= analogRead(BUTTON_PIN);
   int a= digitalRead(BUTTON_PIN1);
    Serial.println(p);
  if(p >100 && a<100)
  {
    deep = "Some one";
    cou++;
    Serial.println(deep);
    delay(1000);
  }
  else  if(p <100 && a>100)
  {
    deep =  "empty";
    cou--;
    Serial.println(p);
    Serial.println(deep);
    delay(1000);
  }
  printp->save(deep);
  counter->save(cou);
  }
