//***************Phone secuirty System IOT****************
//________________________________Part 1(programing) ____________________________________
#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>
//________________________________Part 2(programing) ____________________________________
char auth[] = "fd8aaf2bc2a94aa9ac255e44affc28a4";  
int IR_sensor= D1; 
int switch1 = D2; 
Servo servo;
WidgetLED led1(V2);
//________________________________Part 3(programing) ____________________________________
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "pardeep", "12345678");  //wifi name and password
  pinMode(IR_sensor,INPUT);
  pinMode(switch1,INPUT);
   servo.attach(D3);
}
//________________________________Part 4(programing) ____________________________________
void loop()
{ 
 Blynk.run();
 int a = digitalRead(switch1);
 int sensorState = digitalRead(IR_sensor);
 if( a == HIGH)
  {
       Serial.print(a);
       if (sensorState == HIGH )
         {
            Blynk.notify("check your phone somthing wrong");
            led1.on();
            servo.write(0);
            delay(1000);
         }  
        else
         {
            led1.off();
            servo.write(90);
            delay(1000); 
         }
  }
else
  {
   Serial.print(a);
  }
}
//________________________________Thanks a lot  ____________________________________


