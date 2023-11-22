const int pinLight = A0;
const int pinLed  = 7;

int thresholdValue=200;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(pinLight);
  if (sensorValue<thresholdValue) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
  Serial.print("Sensor = ");
  Serial.println(sensorValue);
  delay(200);
}
