#include <LiquidCrystal.h>
#define echo 11
#define trig 10
int distance,duration;
LiquidCrystal lcd(7,6,5,4,3,2);

void setup()
{
Serial.begin(9600);
  lcd.begin(16,2);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trig,LOW);
}

void loop()
{

digitalWrite(trig, HIGH);
delayMicroseconds(10) ;
digitalWrite(trig,LOW);
duration=pulseIn(echo,HIGH);
distance=duration/58;
  if(distance>50)
		lcd.print(distance);
  delay(90);
  lcd.clear();
if(distance<50)
  lcd.print("Dangrous!!");

}
