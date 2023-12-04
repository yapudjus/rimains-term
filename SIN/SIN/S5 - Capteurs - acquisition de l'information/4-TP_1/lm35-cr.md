# Amélioration de la Précision de la Mesure de Température avec un Capteur LM35 et un Arduino

## Introduction:
La mesure précise de la température est cruciale dans de nombreuses applications. Cet essai explore les calculs préliminaires et la réalisation d'un programme visant à améliorer la précision de la mesure de température en utilisant un capteur LM35 avec un Arduino.

### Calculs Préliminaires:

#### Type de capteur:
Le capteur est analogique, car sa sortie est linéaire à +10 mV/°C.
#### Tension à 25 °C:
La tension délivrée par le capteur à 25 °C est de 250 mV.
#### Précision à 25 °C: 
La précision à cette température est de +-0.2°C.
#### Quantum de l'Arduino: 
Le quantum de l'Arduino avec un CAN de 10 bits et une tension de référence de 5 V est de 0.0048828125 V.
#### Résolution en °C: 
La résolution du CAN de l'Arduino est de 0.4°C.
#### Précision en °C: 
La précision du CAN de l'Arduino est de ±0.6°C.
#### Précision totale: 
La précision attendue de l'association LM35 – Arduino est de ±0.8°C.
#### Nouveau quantum avec référence interne: 
En utilisant une référence interne de 1.1 V, le nouveau quantum de l'Arduino est de 0.00107421875 V.
#### Nouvelle résolution en °C: 
La nouvelle résolution est de 0.1°C.
#### Nouvelle précision en °C: 
La nouvelle précision attendue de l'association LM35 – Arduino est de ±0.35°C.
Réalisation du Programme:

## Algorithme pour afficher la température sur un écran LCD:
1. Mesurer la tension de sortie du LM35.
2. Convertir la tension en température en utilisant la formule de la sensibilité du LM35.
3. Afficher la température sur l'écran LCD.
4. Répéter toutes les secondes.
```cpp
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3f,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

const int pinTemp = A0;

void setup() {
// put your setup code here, to run once:

lcd.init(); // initialize the lcd 
lcd.backlight();
Serial.begin(115200);
analogReference(INTERNAL);
}

void loop() {
// put your main code here, to run repeatedly:
float sensorValue = analogRead(pinTemp);
float temp = sensorValue/1024*100;
lcd.setCursor(0,0);
lcd.print("Sensor = ");
lcd.print(temp);
Serial.print("Sensor = ");
Serial.println(sensorValue);
delay(1000);
}
```
## Réalisation de l'Alarme:

Montage pour une alarme à plus de 30°C avec un transducteur piézoélectrique:
1. Utiliser une condition dans le programme pour détecter si la température dépasse 30°C.
2. Si la condition est vraie, activer le transducteur piézoélectrique pour signaler l'alarme.
```cpp
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

const int pinTemp = A0;
const int pinBuzz = 13;

void setup() {
lcd.init(); // initialize the lcd 
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
```
## Conclusion:
L'amélioration de la précision de la mesure de température est essentielle dans de nombreuses applications. En combinant le capteur LM35 avec un Arduino et en ajustant la référence interne, il est possible d'obtenir des mesures plus précises, renforçant ainsi la fiabilité des systèmes de surveillance de la température.