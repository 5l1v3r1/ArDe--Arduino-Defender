//
//  Coded By Marco Angione
//  @marc_angio on twitter & GitHub
//

#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

const int rosso = 9;
const int verde = 8;
const int buzzer = 7;
const int Pin = 0;
int stato = 0;
int luce;
int message = 0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Arduino Defender");
  lcd.setCursor(1,1);
  lcd.print("By @marc_angio");
  digitalWrite(verde,HIGH);
  digitalWrite(rosso,HIGH);
  tone(buzzer,500,1000);
  pinMode(verde,OUTPUT);
  pinMode(rosso,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0){
    message = Serial.read();
    

    switch (message)
    {
      case 'A':
       lcd.clear();
       stato = 1;
       noTone(buzzer);
       digitalWrite(verde,HIGH);
       digitalWrite(rosso,LOW);
       lcd.setCursor (6,0);
       lcd.print ("ArDe");
       lcd.setCursor (8,1);
       lcd.print("ON");
       break;
       
      case 'a':
       lcd.clear();
       stato = 0;
       noTone(buzzer);
       digitalWrite(verde,LOW);
       digitalWrite(rosso,HIGH);
       lcd.setCursor (6,0);
       lcd.print ("ArDe");
       lcd.setCursor (8,1);
       lcd.print("OFF");
       break;

      case 'B':
       lcd.clear();
       stato=1;
       digitalWrite(rosso,HIGH);
       digitalWrite(verde,LOW);
       tone(buzzer,500,1000);
       lcd.setCursor (5,0);
       lcd.print ("ALERT!");
       lcd.setCursor (4,1);
       lcd.print("INTRUSION!");
       break;
      }

    }
    
    if (stato==1)
    {
      luce=analogRead(Pin);
      
      if(luce<100){
        lcd.clear();
        digitalWrite(rosso,HIGH);
        digitalWrite(verde,LOW);
        tone(buzzer,500,10000);
        lcd.setCursor (5,0);
        lcd.print ("ALERT!");
        lcd.setCursor (3,1);
        lcd.print("INTRUSION! ");
        lcd.setCursor (14,1);

      }
      else  //ritorna in calma se il laser punta il fotoresistore
      {
        //noTone(buzzer);
        
      }
      
    }
}
   
