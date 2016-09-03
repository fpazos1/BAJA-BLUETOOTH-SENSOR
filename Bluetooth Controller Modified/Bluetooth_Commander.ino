#include <LiquidCrystal.h>
#define button 7
#define button1 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String inData;

void setup() {

pinMode(button,INPUT);
pinMode(button1,INPUT);
  
  Serial.begin(9600);       
    lcd.begin(16,2);
    lcd.print("Welcome!");
    delay(3000);
    lcd.clear();

    
}
void loop() {
 int i=0;
 int r=1;
 char commandbuffer[100];
 int  number;
 int number2;
 

 number=digitalRead(button);
 //Serial.println(number);

 number2=digitalRead(button1);

if(number==0)
Serial.print("Ready");



if(number2==0)
Serial.print("Hello");


  
  if(Serial.available()){
     delay(100);
     while( Serial.available() && i< 99) {
        commandbuffer[i++] = Serial.read();
     }
     commandbuffer[i++]='\0';
  }

  
  if(i>0)

     Serial.println((char*)commandbuffer);
     lcd.print((char*)commandbuffer);
     delay(1000);
     lcd.clear();
     }

  
  
