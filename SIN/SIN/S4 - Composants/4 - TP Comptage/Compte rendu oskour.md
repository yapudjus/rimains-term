le premier qui me passe un café et un doliprane/ibuprofene, je l'embrasse

## act1
### base en electricitée

| Nom        | Description                                                  | Unité de mesure       |
| ---------- | ------------------------------------------------------------ | --------------------- |
| Voltage    | différence de potentiel electrique dans un circuit           | mesuré en Volt (V)    |
| Courant    | correspond au nombre d'électrons circulant dans le circuit   | mesuré en Ampères (A) |
| Résistance | résistance électrique entre deux points d'un conducteur      | Ohm (Omega\|Ω)        |

sources: https://en.wikipedia.org/wiki/Ohm; https://en.wikipedia.org/wiki/Ampere; https://en.wikipedia.org/wiki/Volt

## composants électroniques

| image des composants                 | schéma dessiné                       | nom du composant                | description brève                                |
| ------------------------------------ | ------------------------------------ | ------------------------------- | ------------------------------------------------ |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101708.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103126.png]] | bouton poussoir                 | bouton necessitant de rester enfoncé |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101816.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103145.png]] | interupteur                     | interupteur conservant son etat, ouvert ou fermé |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101831.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103201.png]] | resistance                      | ralentir le flux de courant |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101850.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103305.png]] | condensateur                    | stocker temporairement une charge electrique sous forme electromagnétique |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101919.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103323.png]] | diode                           | composant ne laissant circuler le flux que dans un sens |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101933.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103335.png]] | diode electroluminescente (DEL) | diode emettant de la lumière quand traversée par un courant |

### conclusion
nous aprenons içi les bases de différents composants
## act2
### circuit 2
![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004104749.png]]
ce circuit controle une led à partir d'un bouton poussoir et limite l'intensitée avec une resistance
### circuit 3
![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004104934.png]]
comme le circuit 2, mais controlé par un interrupteur
## act3
rappels
 - 1= Vrai | Haut
 - 0= Faux | Bas
La logique booléenne est utilisée dans presque touts les aspects de **l'electronique**
Durant le **XIXe siècle**, ***George Bool*** a développé une nouvelle forme d'algèbre, aujourd'hui appelée algèbre booléenne en son honneur.
Les équations booléennes utilisent le système des nombres **binaires** pour fournir un moyen très précis d'illustrer la logique des **portes logiques**.
Une porte est l'endroit où un flux circule. La porte prende **une entrée** (généralement A et/ou B) et donne une **sortie** (Y et/ou X)

| Schéma                                                                            | Porte            | Symbole                                                                           | équation booléenne                                                                |
| --------------------------------------------------------------------------------- | ---------------- | --------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004111138.png]] | ET\|OR           | ∧ ou &                                                                            | a.b                                                                               |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004111315.png]] | OU\|OR           | ∨                                                                                 | a+b                                                                               |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004111509.png]] | NON\|NOT         | ¬                                                                                 | a̅                                                                                |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004111957.png]] | NON OU\|NOR      | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004112048.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004112102.png]] |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004112121.png]] | OU-EXCLUSIF\|XOR | ⊻                                                                                 | a⊕b                                                                               |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004112320.png]] | NON-ET\|NAND     | A ↑ B ou⌜ ( A ∧ B )  ou a ⋅ b ¯                                                   | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004112439.png]] |


Table de vérité NON-ET (_NAND_)

| Entrées |Entrées| Sortie |
| ------- | ----- | ------ |
| **a**   | **b** | **L**  |
| 0       | 0     | 1      |
| 0       | 1     | 1      |
| 1       | 0     | 1      |
| 1       | 1     | 0      |


Table de vérité ET (AND)

| Entrées | Entrées | Sortie |
| ------- | ------- | ------ |
| **a**   | **b**   | **L**  |
| 0       | 0       | 0      |
| 0       | 1       | 0      |
| 1       | 0       | 0      |
| 1       | 1       | 1      |


Table de vérité OU (OR)

| Entrées | Entrées | Sortie |
| ------- | ------- | ------ |
| **a**   | **b**   | **L**  |
| 0       | 0       | 0      |
| 0       | 1       | 1      |
| 1       | 0       | 1      |
| 1       | 1       | 1      |

Table NOT

| Entrées | Sortie |
| ------- | ------ |
| **a**   | **L**  |
| 0       | 1      |
| 1       | 1      |

Table de vérité NON-OU (NOR)

| Entrées | Entrées | Sortie |
| ------- | ------- | ------ |
| **a**   | **b**   | **L**  |
| 0       | 0       | 1      |
| 0       | 1       | 0      |
| 1       | 0       | 0      |
| 1       | 1       | 0      |

Table de vérité OU-EXCLUSIF (XOR)

| Entrées | Entrées | Sortie |
| ------- | ------- | ------ |
| **a**   | **b**   | **L**  |
| 0       | 0       | 0      |
| 0       | 1       | 1      |
| 1       | 0       | 1      |
| 1       | 1       | 0      |

## act4
en modelisant le circuit sur proteus:
![[Pasted image 20231011112513.png]]
nous pouvons modifier la valeur de la resistance *R2*

et obptenir ce tableau

| Valeur de *R2* | capture de l'oscilloscope            | frequence de sortie |
| -------------- | ------------------------------------ | ------------------- |
| 10k Ohm        | ![[Pasted image 20231011113145.png]] |33.6ms => **29.7Hz**|
| 100k Ohm       |![[Pasted image 20231011113717.png]]|309.19ms => **3.23Hz**|
| 510k Ohm       |![[Pasted image 20231011114109.png]]|**1.52sec** => 0.657Hz|
| 1M Ohm         |![[Pasted image 20231011114512.png]]|**3.08sec**|
| 1.5M Ohm       |![[Pasted image 20231011114919.png]]|**4.6sec**|

***nous pouvons en déduire que plus la resistance est élévée, plus la periode augmente, et la frequence diminue (F = 1/T), et vice versa***

pour avoir une periode de 1sec, la resistance R2 est de environ 330k Ohm
![[Pasted image 20231011115733.png]]
***nous pourions deduire qu'une resistance 5x plus haute (1.65M Omh) donnerait une periode 5x plus élevée***, de même pour 10sec => 3.3M Ohm

avec le condensateur à 1uF et R2 à 100k Ohm, une periode de 140ms est atteinte, contre 330ms avec le condensateur à 2.2uF
![[Pasted image 20231011120430.png]]
***nous pouvons en deduire que plus la capacitée du condensateur est faible, plus la frequence est élevée, et vis versa***

#### en conclusion:
 - plus la resistance R2 est élevée, plus la frequence baisse
 - plus la capacitée du condensateur est élevée, plus la frequence baisse

