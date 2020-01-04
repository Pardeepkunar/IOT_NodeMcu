
#include "config.h"// .h file include i this program help of #include
#define BUTTON_PIN D1 // Button connect to a D1 hardware and led show in cloud
int current = HIGH;   //  create a variable and store value
int last = LOW;
// AdafruitIO_feed and io.feed is a keyword import for same write without any modify
// *(thats a pointer)digital is a variale you can change we say thats a feed because
// help of this all data transfer to cloud 
AdafruitIO_Feed *digital = io.feed("digital");

// one time decleare function
void setup() {
  pinMode(BUTTON_PIN, INPUT); // button is input
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

// if statement decleare when you press switch send value in cloud led operate
  if(digitalRead(BUTTON_PIN) == LOW)
    current = HIGH; // varibale store value 1 or 0 and sensd to cloud 
  else
    current = LOW;
   if(current == last)
    return;
  Serial.print("sending button -> ");
  Serial.println(current);
  digital->save(current); // if you send any data harware to cloude use keyword ""feed->"save(variable)""
  last = current;

}
