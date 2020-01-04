
#include "config.h"
#define LED_PIN D

AdafruitIO_Feed *digital = io.feed("digital");

void setup() {

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");
  io.connect();

  digital->onMessage(handleMessage);// function

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("welcome");
  Serial.println(io.statusText());
  digital->get();
}
void loop() 
{
  io.run();
}
void handleMessage(AdafruitIO_Data *data) {

  if(data->toPinLevel() == HIGH)
    Serial.println("HIGH");
  else
   Serial.println("LOW");
   digitalWrite(LED_PIN, data->toPinLevel());

}
