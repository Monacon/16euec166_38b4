#include <LiquidCrystal.h>
LiquidCrystallcd(12, 11, 5, 4, 3, 2);
constint i=10,j=9;
int k=0;
void setup() {
pinMode(i,INPUT);
pinMode(j,INPUT);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("WELCOME");
lcd.setCursor(0, 1);
lcd.print("INITIALIZATION");
delay(5000);
lcd.setCursor(0, 0);
lcd.print("FOOD PROCESS");
}

void loop() {
pinMode(i,LOW);
   k = digitalRead(i);
if (k == HIGH &&digitalRead(j)==HIGH) {
lcd.setCursor(0, 0);
lcd.print("FOOD PROCESS");
lcd.setCursor(0, 1);
lcd.print("GOOD FOOD SAMPLE");
delay(10000);
lcd.clear();
  } else if(k == HIGH &&digitalRead(j)==LOW) {
lcd.setCursor(0, 0);
lcd.print("FOOD PROCESS");
lcd.setCursor(0, 1);
lcd.print("BAD FOOD SAMPLE");
delay(10000);
lcd.clear();
  } 
else if(k == LOW) {
lcd.setCursor(0, 0);
lcd.print("FOOD PROCESS");
lcd.setCursor(0, 1);
lcd.print("INITIALIZING");
delay(10000);
lcd.clear();
  }
}

