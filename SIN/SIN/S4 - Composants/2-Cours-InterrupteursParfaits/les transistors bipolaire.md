3 bornes
 - base
 - collecteur
 - emetteur
se comporte comme un intérupteur

***Ie = Ic + Ib***
si pas d'alimentation sur la **base**, le transistor agit comme un **interrupteur ouvert**, si il y 
a du courant, il se comporte comme un **interrupteur fermé**
si Ib > 0 alors on a une tension Vbe qui s'applique, on peut effectuer la loi des mailles

## definitions

![[Pasted image 20231006102959.png]]
- ***iB*** : courant de base
- ***iC*** : courant de collecteur
- ***iE*** : courant d'émetteur
- ***VCE*** : tension collecteur émetteur pour un transistor NPN (VEC pour un transistor PNP)
- ***VBE*** : tension base émetteur pour un transistor NPN (V EB pour un transistor PNP)

## différence NPN et PNP
***NPN***: le courant rentre dans la base, sens du courant ***Ic ->Ie***, tension **Vce** **Vbe**
***PNP***: le courant sort de la base, sens du courant ***Ie -> Ic***, tension **Vec** **Veb**

## modes de fonctionements:
### régime linéaire:
agit en potentiometre, amplification du courant

En régime linéaire, le transistor est passant : il réalise une amplification du courant
d'entrée **iB**.
***iC = β . iB***
**β** est appelé *gain en courant* du transistor ou coefficient d'amplification en courant
(*β est parfois noté hFE*)

### régime de commutation:

comme un interrupteur (*entre C et E*) ***commandé*** par le *courant de base*.
#### Règles de fonctionnement :

Si ***iB = 0*** => ***iC = 0*** => Le transistor est ***bloqué***, il se comporte comme un ***interrupteur ouvert***

Si ***iB > 0*** => ***iC = iCsat*** => Le transistor est ***saturé***, il se comporte comme un ***interrupteur fermé***
