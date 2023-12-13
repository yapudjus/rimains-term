# Compte Rendu sur le Module HC-SR04  
  
## 1) Présentation du module HC-SR04 :  
  
Les caractéristiques techniques du module HC-SR04, telles qu'indiquées dans sa datasheet, sont les suivantes :  
  
- **Alimentation :** 5v  
- **Consommation en utilisation :** 15mA  
- **Gamme de distance :** 2cm-400cm  
- **Résolution :** 3cm  
- **Précision :** 3cm  
- **Angle de mesure :** 15°  
  
**Principe de fonctionnement :** Le capteur émet un signal en ultrason, puis attend le retour du signal réfléchi sur l’obstacle. La séquence de fonctionnement est illustrée graphiquement.  
  
### Questions :  
  
1. **Pourquoi l’obstacle est-il signalé au milieu de l’impulsion Echo ?**  
   Le signal Echo est déclenché au moment où le capteur détecte que l'onde réfléchie atteint le capteur. Cela se produit au milieu de l'impulsion Echo car le capteur mesure le temps écoulé depuis l'émission du signal ultrasonore jusqu'à la détection de son écho.  
  
2. **Quelle est la célérité des ultrasons dans l’air à une température de 25 °C ?**  
   La célérité du son dans l'air à 25 °C est de 346.375 m/s.  
  
3. **Exprimer la formule donnant la distance \(d\) en cm pour une durée \(\Delta T\) en µs de l’impulsion Echo.**  
   \(\frac{\Delta T}{58} = d\)  
  
4. **Application Numérique pour \(\Delta T1 = 150 \mu s\), \(\Delta T2 = 1 ms\), \(\Delta T3 = 60 ms\).**  

| \(\Delta T\) | Distance (\(d\))                |
| ------------ | ------------------------------- |
| 150 µs       | 2.5 cm                          |
| 1 ms         | 17.24 cm                        |
| 60 ms        | Hors distance car 60 ms > 38 ms |

## 2) Mise en œuvre du module HC-SR04, premières mesures  
  
**Montage :** 
  ![[IMG_20231206_103400.jpg]]
Pour utiliser le module HC-SR04, le programme suit la séquence suivante :  
  
1. Créer une impulsion de 20 µs (>10 µs) sur la patte Trig  
2. Mesurer la durée \(\Delta T\) de l’impulsion Echo en µs  
3. Calculer la distance \(d\) en cm correspondante  
4. Afficher sur le moniteur série la durée \(\Delta T\) et la distance \(d\)  
5. Attendre 200 ms avant de réaliser une nouvelle mesure  
  
### Algorithme :  
  
```cpp  
float Temp = 25; // température en °C  
int Echo = 2;  
int Trig = 5;  
unsigned long dt;  
float d, c;  
  
void setup() {  
    pinMode(Trig, OUTPUT);  
    pinMode(Echo, INPUT);  
    Serial.begin(9600);  
}  
  
void loop() {  
    digitalWrite(Trig, HIGH);  
    delayMicroseconds(20);  
    digitalWrite(Trig, LOW);  
    dt = pulseIn(Echo, HIGH);  
     
    if (dt == 0) Serial.println("Mesure hors limite");  
    else {  
        c = 331.2 + 0.607 * Temp;  
        d = c / 2 * dt / 10000;  
        Serial.print("dt = "); Serial.print(dt); Serial.println(" µs");  
        Serial.print("d = "); Serial.print(d, 1); Serial.println(" cm");  
    }  
    delay(200);  
}  
```  
  
**Visualisation sur l'oscilloscope :** (Inclure les captures d'écran des signaux Trig et Echo)  
 ![[IMG_20231206_103338.jpg]] ![[IMG_20231206_103341.jpg]]![[IMG_20231206_103332.jpg]]
**Réponses aux questions 8 et 9 :**  
- Width trig : 200µs  
- Width echo @140cm : 8.4ms  
- La mesure est correspondante à environ 1cm  
  
## 3) Etape 2 : Afficher la distance sur un écran LCD  
  
  
## 4) Précision du capteur  
  
**Tableau des mesures :**  

| **Distance en mm** | **Mesure affichée** | **Erreur en mm** | **Erreur en %**   |
| ------------------ | ------------------- | ---------------- | ----------------- |
| 10                 | 28                  | 18               | 180               |
| 20                 | 27                  | 7                | 35                |
| 30                 | 38                  | 8                | 26.6666666666667  |
| 40                 | 44                  | 4                | 10                |
| 50                 | 52                  | 2                | 4                 |
| 60                 | 63                  | 3                | 5                 |
| 70                 | 69                  | -1               | -1.42857142857143 |
| 80                 | 82                  | 2                | 2.5               |
| 90                 | 96                  | 6                | 6.66666666666667  |
| 100                | 106                 | 6                | 6                 |
| 150                | 165                 | 15               | 10                |
| 200                | 239                 | 39               | 19.5              |
| 250                | 253                 | 3                | 1.2               |
| 300                | 317                 | 17               | 5.66666666666667  |
  
**Graphiques :**  
  ![[Pasted image 20231206114518.png]]
**Analyse :** Le pourcentage d’erreur diminue avec la distance.