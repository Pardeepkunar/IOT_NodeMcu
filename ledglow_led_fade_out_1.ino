// ledglow and led fade control on adafruit cloud
#include "config.h"
#define LED_PIN D0
#define LED_PIN1 D1
AdafruitIO_Feed *digital = io.feed("digital");
AdafruitIO_Feed *analog = io.feed("analog");
void setup() {

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  digital->onMessage(handleMessage);// function
  analog->onMessage(handleMessages);
 
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("welcome");
  Serial.println(io.statusText());
  digital->get();
  analog->get();
}
void loop() 
{
  io.run();
}
void handleMessage(AdafruitIO_Data *data) 
{
  if(data->toPinLevel() == HIGH)
    Serial.println("HIGH");
  else
    Serial.println("LOW");

   digitalWrite(LED_PIN, data->toPinLevel());
}
void handleMessages(AdafruitIO_Data *data) 
{
  int pardeep = data->toInt();
  Serial.println(pardeep);
  analogWrite(LED_PIN1, pardeep);
}
