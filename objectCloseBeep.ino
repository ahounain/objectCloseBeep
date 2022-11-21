#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int timesObjectCameClose;
int buzzer = 7;
void setup() {
  pinMode(buzzer,OUTPUT);
   Serial.begin(9600);
   delay(1000);
   int timesObjectCameClose = 0;
   
}

void loop() {
  unsigned char i;  
   a=sr04.Distance();
   if (sr04.Distance() < 100) {
    timesObjectCameClose++; 
   
   while (sr04.Distance() < 100) {
     
     Serial.println("OBJECT CAME CLOSE");
     for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
     
     Serial.println();
   }
   }
   
   Serial.println("Object has came");
   Serial.print(timesObjectCameClose);
   Serial.print(" times");
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}
