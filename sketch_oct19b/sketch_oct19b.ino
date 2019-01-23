
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "e1d95f54bb9e44cf8da4a66dc2a9450b";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "error404";
char pass[] = "12345678";
WidgetLCD lcd(V4);
int i,j,k,h;
// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); 
i=pinValue;

}
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); 
j=pinValue;

}
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); 
k=pinValue;

}

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D8,INPUT);
pinMode(D9,INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  lcd.clear(); 
  lcd.print(4, 0, "welcome"); 
  lcd.print(2, 1, "intializing");
  delay(4000);
    lcd.clear(); 
  lcd.print(2, 0, "Select Your"); 
  lcd.print(5, 1, "Choice");
   
  
}

void loop()
{
  j=0;k=0;i=0,h=0;
  lcd.clear(); 
  lcd.print(0,0, "Your option is"); 
  while(j!=1&&k!=2&&i!=3)
  {
    Blynk.run();
    Serial.print(i+j+k);
  }
   if(j==1)
  {
      lcd.print(4,1, "APPLE"); 
    Serial.print(i);
    digitalWrite(D2,HIGH);
    
  }
  if(i==3){
      lcd.print(4,1, "RICE"); 
    digitalWrite(D1,HIGH);
    Serial.print(i);
  }
  if(k==2)
  {
      lcd.print(4,1, "Bread"); 
    digitalWrite(D3,HIGH);
  }
  //digitalWrite(D8,LOW);
while (digitalRead(D6) == LOW) {
  
}
  
  if(D9==LOW)
  {
     lcd.clear(); 
  lcd.print(0,0, "Your fOOD IS"); 
  lcd.print(0,1, "AFFECTED"); 
  delay(1000);
  }
  else
  {
     lcd.clear(); 
  lcd.print(0,0, "Your fOOD IS"); 
  lcd.print(0,1, "NOT AFFECTED"); 
  delay(1000);
  }
  
  
}

