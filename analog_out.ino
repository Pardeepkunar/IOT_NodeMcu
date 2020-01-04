#include "config.h"// .h file include i this program help of #include
#define LED_PIN D0 // led pin decleare connect led in D1 pin of the hardware
// AdafruitIO_feed and io.feed is a keyword import for same write without any modify
// *(thats a pointer)digital is a variale you can change we say thats a feed because
// help of this all data transfer to cloud 
AdafruitIO_Feed *analog = io.feed("analog");

// on time declear
void setup() {

  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  analog->onMessage(handleMessage); // function

   while(io.status() < AIO_CONNECTED) {
   Serial.print(".");
   delay(500);
  }
  Serial.println("welcome");
  Serial.println(io.statusText());
  analog->get();
}
void loop() 
{
   io.run();
}
// Start function
void handleMessage(AdafruitIO_Data *data) {
  // when we change a value on adafruit.io led brightness change in harware
  int pardeep = data->toInt();
  Serial.println(pardeep);
  analogWrite(LED_PIN, pardeep);

}
