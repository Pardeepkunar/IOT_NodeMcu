#include "config.h" // .h file include i this program help of #include
#define LED_PIN D0 // led pin decleare connect led in D1 pin of the hardware
// AdafruitIO_feed and io.feed is a keyword import for same write without any modify
// *(thats a pointer)digital is a variale you can change we say thats a feed because
// help of this all data transfer to cloud 
AdafruitIO_Feed *digitalp = io.feed("digitalp");

// on time declear
void setup() {
  pinMode(LED_PIN, OUTPUT);
   Serial.begin(115200);
   while(! Serial);
   Serial.print("Connecting to Adafruit IO");
  io.connect();
   digitalp->onMessage(handleMessage1); // function
    while(io.status() < AIO_CONNECTED) 
  {
   Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  digitalp->get();
}
void loop() 
{
   io.run();
}
// Start function
void handleMessage1(AdafruitIO_Data *data) 
{ // when we change a value on adafruit.io help of cloud we on light 
  //like as asecurity if in program "deep==10" if we enetr 10 led on harware
  int deep = data->toInt();
  if(deep == 10)
  {
     Serial.println("welcome pardeep");
     digitalWrite(LED_PIN,HIGH);
     Serial.println(data->value());
   }
  else
   {
     digitalWrite(LED_PIN,LOW);
     Serial.println("soory pardeep");
     Serial.println(data->value());
   }}
  
