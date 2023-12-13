#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


const int trig = 2;
const int echo = 3;
float duree;
float distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);
  // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duree = pulseIn(echo, HIGH);
  distance = duree*0.034/2;
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");
  lcd.setCursor(0,0);
  lcd.print("distance:");
  lcd.print(distance);
  lcd.print("cm");
  delay(200);
}


