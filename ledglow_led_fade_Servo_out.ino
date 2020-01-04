#include "config.h"
#include<Servo.h>
#define LED_PIN D0
#define LED_PIN1 D1
#define SERVO_PIN D3
Servo servo;

AdafruitIO_Feed *digital = io.feed("digital");
AdafruitIO_Feed *analog = io.feed("analog");
AdafruitIO_Feed *servo_feed = io.feed("servo");

void setup() {

  pinMode(LED_PIN, OUTPUT);
  servo.attach(SERVO_PIN);
  Serial.begin(115200);
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");
  io.connect();

  digital->onMessage(handleMessage);// function
  analog->onMessage(handleMessage1);
  servo_feed->onMessage(handleMessage2);
 
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("welcome");
  Serial.println(io.statusText());
  digital->get();
  analog->get();
  servo_feed->get();
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
void handleMessage1(AdafruitIO_Data *data) 
{
  int pardeep = data->toInt();
  Serial.println(pardeep);
  analogWrite(LED_PIN1, pardeep);

}
void handleMessage2(AdafruitIO_Data *data) {

  int pardeep1 = data->toInt();

  if(pardeep1 < 0)
     pardeep1 = 0;
  else if(pardeep1 > 180)
     pardeep1 = 180;

  servo.write(pardeep1);

}
