#include "Wire.h"  
#include "DHT.h"  
   
DHT dht(2, DHT11);  
  
void setup() {  
   
   Serial.begin(9600);  
   dht.begin();  
}  
  
void loop() {  
   float t = dht.readTemperature();  
  
   Serial.println(t);
  
   delay(1000);  
}