# Étude du Capteur de Luminosité  
  
## Introduction  
  
Dans le cadre de cette étude, nous examinerons en détail le capteur de luminosité, notamment sa nature (numérique ou analogique), ses caractéristiques, son principe de fonctionnement, ainsi que les composants qui le composent.  
  
### 1. Nature du Capteur  
  
Le capteur de luminosité est de nature **analogique**. Cette conclusion est basée sur l'indication "Analog value output" retrouvée dans les caractéristiques du capteur sur le site [Seeed Studio]([https://wiki.seeedstudio.com/Grove-Light_Sensor/#features](https://wiki.seeedstudio.com/Grove-Light_Sensor/#features)).  
  
### 2. Caractéristiques du Capteur  
  
- **Tension de fonctionnement:** 3~5V  
- **Courant de fonctionnement:** 0.5~3 mA  
- **Temps de réponse:** 20-30 millisecondes  
- **Longueur d'onde de crête:** 540 nm  
- **Poids:** 4 g  
  
### 3. Principe de Fonctionnement  
  
Le capteur acquiert les données en utilisant une photoresistance, puis renvoie ces données au microcontrôleur de manière analogique.  
  
### 4. Composants du Capteur  
  
- **Photoresistance LS06-S:** Capte la lumière.  
- **Double circuit amplificateur optique LM358:** Amplifie le signal lumineux.  
  
### 5. Caractéristiques des Composants  
  
**LM358:**  
- Référence: LM358AN/NOPB.  
- Type d'amplificateur: Compensé en fréquence.  
- Type de sortie: Différentielle.  
- Type d'alimentation: Simple ou double.  
- Slew Rate: 0.4v/µS.  
- Bandwidth: 700 Khz.  
  
**Photoresistance:**  
- Courant de collecte lumineuse: 25uA  
- Tension de rupture C-E: 70uA  
- Réponse: 450-1050nm  
- Demi-angle: 60 degrés  
  
## B. Montage Capteur Luminosité / Arduino / Led  
  
### Matériel  
  
- Capteur de luminosité  
- Arduino UNO  
- Résistance de 220 Ohm  
- LED  
  
### 1. Code Arduino  
  
Regarder la vidéo **Light sensor Grove module.mp4** et recopier le code en langage C sur l'IDE Arduino.  
  
### 2. Fonctionnement du Programme  
  
Le programme récupère la valeur du capteur, la compare à une valeur seuil, allume ou éteint une LED sur le pin D7 en fonction du résultat, envoie la valeur sur le port série, attend 200ms, puis recommence.  
  
### 3. Valeur de Seuil de Luminosité  
  
La LED s'allume lorsque la valeur du capteur est inférieure à 200.  
  
### 4. Téléversement et Mesures  
  
Téléversez le programme dans l'Arduino à l'aide du câble USB. Lancez le moniteur série pour visualiser les valeurs de luminosité. Faites varier manuellement la luminosité et effectuez 10 mesures en sortie du capteur.  
  
### 5. Courbe des Mesures  
  

  
### 6. Conclusion sur le Fonctionnement du Montage  
  
Le montage fonctionne en mesurant la tension par un convertisseur analogique-numérique (CAN) de la carte Arduino. Il compare ensuite cette valeur à un seuil pour allumer ou éteindre une LED, tout en renvoyant la valeur sur un port série. L'acquisition des données se fait par conversion analogique→numérique, utilisant un quantum qui correspond à la valeur analogique pour la valeur numérique la plus basse non nulle.