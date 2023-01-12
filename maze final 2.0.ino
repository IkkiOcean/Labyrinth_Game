#include <Wire.h> 
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myServoX;

Servo myServoY;
int ir = 6;
int buz = 3;
int ServoXPin = 8;

int ServoYPin = 11;  

int XAxisPin = A0;

int YAxisPin = A1;

int SW = 2;
unsigned long start, end, time;
unsigned long pre = 0;
int m , s, ms;
void setup()

{
  pinMode (buz, OUTPUT);
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  
  myServoX.attach(ServoXPin);

  myServoY.attach(ServoYPin);

  pinMode(SW, INPUT_PULLUP);

  
  int i = 0;
  while(i== 0){
    if(digitalRead(SW)== 0){
      i = 1;
    }
  }

  lcd.setCursor(0, 0);
  lcd.print("STARTING IN 3");
  digitalWrite(buz,HIGH);
  delay(400);
  digitalWrite(buz,LOW);
  delay(600);
  lcd.clear();
  lcd.print("STARTING IN 2");
  digitalWrite(buz,HIGH);
  delay(400);
  digitalWrite(buz,LOW);
  delay(600);
  lcd.clear();
  lcd.print("STARTING IN 1");
  digitalWrite(buz,HIGH);
  delay(1000);
  digitalWrite(buz,LOW);
  lcd.clear();
  start = millis();
  //Serial.begin(9600);
}

void loop()

{    
      //Serial.println(String(map(analogRead(XAxisPin), 0, 1023, 40, 140)));
      myServoX.write(map(analogRead(XAxisPin), 0, 1023, 53, 113));
      myServoY.write(map(analogRead(YAxisPin), 0, 1023, 120, 60));
      unsigned long over;
      end = millis();
      time = end - start;
      over=time%3600000;
      m=int(over/60000);
      over=over%60000;
      s=int(over/1000);
      lcd.setCursor(0, 0);
      lcd.print("Time passed : ");
      int a = 0;
      if (a == 0){
        lcd.setCursor(0, 1);
        lcd.print(String(m) + "min " + String(s) + "sec");
        a = 1;
      }
      else{
        if(end - pre > 1000){
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print(String(m) + "min " + String(s) + "sec");
        end = pre;
      }
      }
      
      // digitalWrite(tPin,LOW);
      // delayMicroseconds(2);
      // digitalWrite(tPin, HIGH);
      // delayMicroseconds(10);
      // digitalWrite(tPin,LOW);
      // int duration = pulseIn(ePin, HIGH);
      // int distance = duration * 0.034/2;
      if (digitalRead(ir) == 1){
        lcd.clear();
        digitalWrite(buz,HIGH);
        lcd.setCursor(0, 0);
        lcd.print("CONGRATULATIONS!");
        lcd.setCursor(4, 1);
        lcd.print("YOU WIN!");
        delay(2000);

        digitalWrite(buz,LOW);
        delay(1000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("YOUR RECORD :");
        lcd.setCursor(4, 1);
        lcd.print(String(m) + "min " + String(s) + "sec");;
        
        exit(0);
      }
      else{
        lcd.clear();  
      }
      

//this code is short one and servo will have an accurate angle with respect to joystick

 

}
