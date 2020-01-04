// counter IOT send data into cloud

#include "config.h"

int count = 0;
AdafruitIO_Feed *counter = io.feed("counter");

void setup() {

  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");

  io.connect();
  
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
}
void loop() {

  io.run();

  Serial.println(count);
  counter->save(count);

  count++;
  delay(3000);

}
