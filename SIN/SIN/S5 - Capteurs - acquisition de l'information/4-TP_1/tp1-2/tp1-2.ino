#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int pinTemp = A0;
const int pinBuzz = 13;

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(115200);
  analogReference(INTERNAL);
  pinMode(pinBuzz, OUTPUT);
}
void loop() { // put your main code here, to run repeatedly:
  float sensorValue = analogRead(pinTemp);
  float temp = sensorValue/1024*100;
  lcd.setCursor(0,0);
  lcd.print("Sensor = ");lcd.print(temp);
  Serial.print("Sensor = ");Serial.println(sensorValue);
  if (temp > 30.0) {
    digitalWrite(pinBuzz, HIGH);
  } else {
    digitalWrite(pinBuzz, LOW);
  }
  delay(1000);
}
