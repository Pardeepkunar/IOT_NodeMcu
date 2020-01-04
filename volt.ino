 //********************* LM35 data show in Adafruit.io cloud*********************
#include "config.h"
//#include<dht.h>
//dht DHT;
int led1 = D1;
int led2 = D2;
int led3 = D3;
int led4 = D4;
String g = " ";
AdafruitIO_Feed *potet = io.feed("potet");

void setup() {

  Serial.begin(115200);
  pinMode(A0,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
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
  int a= analogRead(A0);
  //Serial.println(a);


if(a<=69)
{
  Serial.println("0V");
  digitalWrite(led1,LOW);
  g="0V";
}

// 1v 
else if(a<=133)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  Serial.println("1V");
  g="1V";
}


//// 2v
//else if(a<=160)
//{
//  Serial.println("2V");
//}

//3v
else if(a<=198)
{
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
  Serial.println("2V");
  g="2V";
}
else if(a<=261)
{
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  Serial.println("3V");
  g="3V";
}
// 2v
else if(a<=325)
{
  digitalWrite(led4,HIGH);
  Serial.println("4V");
  g="4V";
}

//3v
else if(a<=387)
{
  Serial.println("5V");
  g="5V";
}
else if(a<=451)
{
  Serial.println("6V");
  g="6V";
}
// 2v
else if(a<=514)
{
  Serial.println("7V");
  g="7V";
}

//3v
else if(a<=578)
{
  Serial.println("8V");
  g="8V";
}
else if(a<=640)
{
  Serial.println("9V");
  g="9V";
}
// 2v
else if(a<=705)
{
  Serial.println("10V");
  g="10V";
}

//3v
else if(a<=768)
{
  Serial.println("11V");
  g="11V";
}
else if(a<=800)
{
  Serial.println("12V");
  g="12V";
}

else if(a<=810)
{
  Serial.println("Relay operate cut off suplly");
  g="Cut Supply battery full charge";
}
 
   potet->save(g);
   delay(10000);
  }
