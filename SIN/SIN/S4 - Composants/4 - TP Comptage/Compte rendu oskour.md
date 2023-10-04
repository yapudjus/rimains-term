le premier qui me passe un café et un doliprane/ibuprofene, je l'embrasse

## act1
### base en electricitée

| Nom        | Description                                                | Unité de mesure       |
| ---------- | ---------------------------------------------------------- | --------------------- |
| Voltage    | différence de potentiel electrique dans un circuit         | mesuré en Volt (V)    |
| Courant    | correspond au nombre d'électrons circulant dans le circuit | mesuré en Ampères (A) |
| Résistance |      résistance électrique entre deux points d'un conducteur                                                      | Ohm (Omega\|Ω)        |

sources: https://en.wikipedia.org/wiki/Ohm; https://en.wikipedia.org/wiki/Ampere; https://en.wikipedia.org/wiki/Volt

## composants électroniques

| image des composants                 | schéma dessiné                       | nom du composant                | description brève                                |
| ------------------------------------ | ------------------------------------ | ------------------------------- | ------------------------------------------------ |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101708.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103126.png]] | bouton poussoir                 | bouton necessitant de rester enfoncé             |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101816.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103145.png]] | interupteur                     | interupteur conservant son etat, ouvert ou fermé |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101831.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103201.png]] | resistance                      | ralentir le flux de courant                                                 |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101850.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103305.png]] | condensateur                    |       stocker temporairement une charge electrique sous forme electromagnétique                                           |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101919.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103323.png]] | diode                           |   composant ne laissant circuler le flux que dans un sens                                               |
| ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004101933.png]] | ![[SIN/SIN/S4 - Composants/4 - TP Comptage/imgs/Pasted image 20231004103335.png]] | diode electroluminescente (DEL) |       diode emettant de la lumière quand traversée par un courant                                           |

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

| Schéma                               | Porte            | Symbole                              | équation booléenne                   |
| ------------------------------------ | ---------------- | ------------------------------------ | ------------------------------------ |
| ![[Pasted image 20231004111138.png]] | ET\|OR           | ∧ ou &                               | a.b                                  |
| ![[Pasted image 20231004111315.png]] | OU\|OR           | ∨                                    | a+b                                  |
| ![[Pasted image 20231004111509.png]] | NON\|NOT         | ¬                                    | a̅                                   |
| ![[Pasted image 20231004111957.png]] | NON OU\|NOR      | ![[Pasted image 20231004112048.png]] | ![[Pasted image 20231004112102.png]] |
| ![[Pasted image 20231004112121.png]] | OU-EXCLUSIF\|XOR | ⊻                                    | a⊕b                                  |
| ![[Pasted image 20231004112320.png]] | NON-ET\|NAND     | A ↑ B ou⌜ ( A ∧ B )  ou a ⋅ b ¯      | ![[Pasted image 20231004112439.png]] |

