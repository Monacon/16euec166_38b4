#include <SoftwareSerial.h>
#include <AS726X.h>
#include <LiquidCrystal.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo;
AS726X sensor;
String apiKey = "O4YXL90R0KBIOPUQ";
SoftwareSerial ser(11,12); 
void setup() {  
  sensor.begin();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
   Serial.begin(115200);
   ser.begin(9600);
ser.println("AT+RST");  
}
void loop() {  
  int a=0,b=0,i;
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
    

  

  if(a>100)
  {
   
       myservo.write(0);
       digitalWrite(2, HIGH);
        digitalWrite(3,LOW);
          delay(1000);
          Serial.print("BAD FOOD");
          
 
  }
  else 
  {
    
       myservo.write(180);
       digitalWrite(3, HIGH);
          digitalWrite(2,LOW); 
       delay(1000);
       Serial.print("GOOD FOOD");
  }

}

