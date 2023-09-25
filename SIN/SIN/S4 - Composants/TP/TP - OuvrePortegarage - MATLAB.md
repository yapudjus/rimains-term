## intro
le but du TP est l'etude d'un système Symulink MatLAB, afin de se familiariser avec le logiciel, et apprendre à tirer des conclusions
## etude du sysml
 - possibilitée de desolidariser la porte manuellement
 - eclairage lors de l'ouverture et fermeture + 2min après
 - ouverture fermeture et arret automatique
	 - acquérir les ordres de commande
		 - d'une télécommande
		 - serrure extérieur et bouton intérieur
	 - mise en mvmnt de la porte dans les 2 sens et arreter
		 - detecter la fin de course
	 - inverser mvmnt lors de detection d'obstacle // se libérer de l'obstacle | sécuritée
		 - détecter un obstacle

 - ordre
	- moteur>lumière
 - microcontroleur
	- PB4->lampe
	- PB5->moteur

## étude MatLAB
depuis le fichier [[SIN/SIN/S4 - Composants/4-TP_OuvrePorteDeGarageVersionMATLAB/Annexes/OuvrePorteGarage_elv.slx]]

### tableau etats ^etats
|état logique PB5|état logique PB4|exemple|
|----|----|----|
|0|0|seul la lampe active, durant les 2min suivant la coupure moteur|
|0|1|système entièrement à l'arret|
|1|0|moteur et lampe actifs, durant l'utilisation ouverture/fermeture|
|1|1|seul moteur actif, durna t les premiers instant car moteur actif en premier dans le code|

les combinaisons disponibles sont liés au fait que les ports sont distinct, et dans différents états, afin de permetre un contrôle complet des éléments

## exo
 Placer des instruments de mesure afin de pouvoir mesurer lors de la simulation :
- la tension VCE du transistor T3
- la tension VCE du transistor T4
- la tension UL1 aux bornes de la lampe L1

|état logique PB5|état logique PB4|Upb5 (v)|Upb4 (v)|Vce t3 (v)|Vce t4 (v)|Um1 (v)|vitesse rotat° moteur m1 (rad\*sec^-1)|Ul1 (v)|
|-|-|-|-|-|-|-|-|-|
|0|0|0v|0v|24V|24V|0v|0|0v|
|0|1|0v|5v|24v|25mv|0v|0|22.7v|
|1|0|5v|0v|25mV|24V|23.72v|~730|22.8v|
|1|1|5v|5v|25mv|24mv|23.96v|~740|22.7v|

*cf le tableau [[#^etats]] pour des examples de contexte*


|État logique PB5|État logique PB4|État de T3|État de T4|État du relais X1|État du relais X2|État du moteur M1|État de la lampe L1|
|-|-|-|-|-|-|-|-|
|0|0|0|1|non enclenché|enclenché|off|off|
|0|1|0|0|non enclenché|non enclenché|off|on|
|1|0|1|1|enclenché|enclenché|on|on|
|1|1|1|0|enclenché|non enclenché|on|on|

nous pouvons en conclure que:
- la lampe est active
	- si le moteur est actif
	- si le pin (PB4) de la lampe est actif
	- les 2
	- **donc modelisable par une porte logique *OR***
- le moteur est actif
	- seulement quand le pin moteur (TB5) est actif
- les 2 sont inactifs seulement quand les 2 pins sont à l'etat bas
- le pin NC du relai lampe (X2) est connécté 'en parallele' avec le moteur, et le pin NO est connéctè au 24v, permettant d'alimenter la lampe avec le moteur, quel que soitr l'etat du relai, mais aussi un contrôle de la lampe indépendant du moteur.

*version: DRAFT-1*