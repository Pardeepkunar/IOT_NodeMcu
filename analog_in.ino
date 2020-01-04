 //********************* LM35 data show in Adafruit.io cloud*********************
#include "config.h"


AdafruitIO_Feed *potet = io.feed("potet");

void setup() {
  pinMode(A0,INPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  Serial.begin(115200);
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");
  io.connect();

   while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run();
  int temp = analogRead(A0);
  int voltage =temp*3.2;
    temp = voltage/100;
  if (temp>=22)
  {
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
     digitalWrite(D3,LOW);
  }
  else
  {
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
     digitalWrite(D3,HIGH);
  }
  Serial.print("Temperature = ");
  Serial.println(temp);
   potet->save(temp);
   delay(2000);
  }
