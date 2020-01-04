#include "config.h"
#include <Servo.h>
#define SERVO_PIN D3
Servo servo;

AdafruitIO_Feed *servo_feed = io.feed("servo");

void setup() {

  servo.attach(SERVO_PIN);
  Serial.begin(115200);
  while(! Serial);
  
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  servo_feed->onMessage(handleMessage);

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  servo_feed->get();
}
void loop() 
{
  io.run();
}
void handleMessage(AdafruitIO_Data *data) {

  int pardeep1 = data->toInt();

  if(pardeep1 < 0)
     pardeep1 = 0;
  else if(pardeep1 > 180)
     pardeep1 = 180;

  servo.write(pardeep1);

}
