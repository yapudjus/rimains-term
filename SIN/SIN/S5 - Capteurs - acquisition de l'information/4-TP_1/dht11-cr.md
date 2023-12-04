# Compte Rendu - Étude du Capteur DHT11  
  
## Introduction  
  
Dans le cadre de cette étude, nous nous sommes penchés sur le capteur DHT11, un dispositif largement utilisé pour mesurer la température et l'humidité. Notre analyse a porté sur divers aspects, notamment la nature du capteur, ses caractéristiques techniques, les principes de mesure de la température et de l'humidité, ainsi que des considérations sur sa précision.  
  
## Calculs Préliminaires  
  
### 1- Nature du Capteur  
Le capteur DHT11 est de nature numérique. Cette conclusion est justifiée par les informations disponibles, indiquant que le capteur utilise des composants électroniques pour mesurer et transmettre les données.  
  
### 2- Caractéristiques Techniques  
Les caractéristiques techniques du capteur DHT11 incluent une résolution de 8 bits pour la température, couvrant la plage de 0 à +50°C, et une résolution pour l'humidité relative de 20 % à 90 %.  
  
### 3- Principe de Mesure de la Température  
Le DHT11 utilise une thermistance à coefficient négatif pour mesurer la température. Ce composant varie sa résistance en fonction de la température, et cette résistance est mesurée une fois par seconde.  
  
### 4- Principe de Mesure de l'Humidité  
La mesure de l'humidité du DHT11 repose sur l'utilisation d'un condensateur variable sensible à l'humidité. La variation de capacité de ce condensateur est mesurée pour obtenir le taux d'humidité.  
### 5- Schéma de Définition de la Trame Datas  
![[Pasted image 20231204094416.png]]
  
### 6- Précision du DHT11  
La précision du DHT11 est établie à 4 % pour l'humidité relative et à ±1°C pour la température.  
  
### 7- Protocole de Test  
Aucun protocole de test n'a été fourni.  
  
## Montage DHT11 / Arduino / LCD  
  
Pour réaliser le montage DHT11 / Arduino / LCD, veuillez suivre le schéma de câblage fourni. De plus, copiez le programme Arduino suivant dans l'interface de programmation :  
  
```cpp
#include "Wire.h"  
#include "LiquidCrystal_I2C.h"  
#include "DHT.h"  
  
LiquidCrystal_I2C LCD(0x27, 16, 2);  
DHT dht(2, DHT11);  
  
void setup() {  
   LCD.init();  
   LCD.backlight();  
   dht.begin();  
}  
  
void loop() {  
   float h = dht.readHumidity();  
   float t = dht.readTemperature();  
  
   LCD.setCursor(0, 0);  
   LCD.print("Humidity: ");  
   LCD.print(h);  
  
   LCD.setCursor(0, 1);  
   LCD.print("Temperature: ");  
   LCD.print(t);  
  
   delay(1000);  
   LCD.clear();  
}