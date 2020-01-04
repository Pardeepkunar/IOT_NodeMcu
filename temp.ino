#include "config.h"
#include<dht.h>
dht DHT;

AdafruitIO_Feed *printp = io.feed("printp");

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
void loop() 
{
  io.run();
int tempdata = DHT.read11(A0);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  delay(2000);
  
  printp->save(DHT.temperature);
 
  
  }
