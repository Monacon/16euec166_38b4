#include <SoftwareSerial.h>
#include <AS726X.h>
#include <LiquidCrystal.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo;
AS726X sensor;
String apiKey = "O4YXL90R0KBIOPUQ";
int m;
SoftwareSerial ser(11,12); 
void setup() {  
  sensor.begin();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
   Serial.begin(115200);
   ser.begin(9600);
ser.println("AT+RST");  
}
void loop() {  
  
  int a=0,b=0,i,q;
  for(i=0;i<=10;i++)
  {
    
sensor.enableBulb();
sensor.takeMeasurements();
  a=a+sensor.getR();
  //Serial.println(sensor.getR());
   b=b+sensor.getS();
   sensor.disableBulb();

 //sensor.printMeasurements();
  }

  a=a/11;
  b=b/11;
  Serial.println("r=");
  Serial.print(a);
  Serial.println("s=");
  Serial.print(b);
    
  digitalWrite(3, LOW);
          digitalWrite(2,LOW);
  while(digitalRead(4)!=HIGH&&digitalRead(5)!=HIGH&&digitalRead(6)!=HIGH)
  {
    Serial.println("HI");
    
    
  }
  
  if(digitalRead(4)==HIGH)
  {
    m=1;
    goto lol;
    Serial.print(m+" ");
  }
    if(digitalRead(5)==HIGH)
  {
    m=2;
   goto lo;
      Serial.print(m+" ");
  }
    if(digitalRead(6)==HIGH)
  {
    m=3;
   goto l;
      Serial.print(m);
  }
  Serial.print(m+"**");
   
  
Serial.print(m+"*/////**");
 //switch(m)
 
  
  lol :
  Serial.println(a);
  Serial.println(b);
    if(a>100)

      {
   
       myservo.write(0);
       digitalWrite(2, HIGH);
        digitalWrite(3,LOW);
          delay(4000);
          Serial.print("*BAD FOOD");
          
 
       }
         else 
  {

    
       myservo.write(180);
       digitalWrite(3, HIGH);
          digitalWrite(2,HIGH); 
       delay(4000);
       Serial.print("*GOOD FOOD");
  }
  goto f;
  lo:if(a>100)

  {
   
       myservo.write(0);
       
          delay(4000);
          digitalWrite(2, HIGH);
        digitalWrite(3,LOW);
          
          Serial.print("**BAD FOOD");
          
 
  }
  else 
  {

    
       myservo.write(180);
       delay(4000);
       digitalWrite(3, HIGH);
          digitalWrite(2,HIGH); 
       
       Serial.print("**GOOD FOOD");
  }
  goto f;
  l:if(a>100)

  {
   
       myservo.write(0);
       delay(4000);
       digitalWrite(2, HIGH);
        digitalWrite(3,LOW);
          delay(1000);
          Serial.print("***BAD FOOD");
          
 
  }
  else 
  {

    delay(4000);
       myservo.write(180);
       digitalWrite(3, HIGH);
          digitalWrite(2,HIGH); 
       
       Serial.print("***GOOD FOOD");
  }
//  break;
 f:
pinMode(4,LOW);
  pinMode(5,LOW);
  pinMode(6,LOW);

}

