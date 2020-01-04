#include "config.h" // .h file include i this program help of #include
#define LED_PIN D1  // led pin decleare connect led in D0 pin of the hardware

// AdafruitIO_feed and io.feed is a keyword import for same write without any modify
// *(thats a pointer)digital is a variale you can change we say thats a feed because
// help of this all data transfer to cloud   
AdafruitIO_Feed *digital = io.feed("digital");

// on time declear
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
// Start function
void handleMessage(AdafruitIO_Data *data) 
{
 // when we press a switch on adafruit.io led on and off in harware
 if(data->toPinLevel() == HIGH)
    Serial.println("HIGH");
  else
    Serial.println("LOW");
  // write the current state to the led
  digitalWrite(LED_PIN, data->toPinLevel());
  }
  
