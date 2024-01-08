
```table-of-contents
````
## 1

### b. 
1ms = 1/1000sec
### c. on genere deux sorties différentes 
- une sortie pseudo-aléatoire - 1ms/bit
- une sortie periodique - 5ms/bit
les deux sont des signaux carrés
### d. 
on passe le champs `pulse width` à 1 et `period` à 2, nus donnant un débit binaire de 1000bps pour celui du haut
### e. celui du haut est pseudo-aléatiore
ce qui représente mieux un signal "du monde réel", tandis que celui du bas est periodique et "trop parfait" pour être représentateur
### f. 
| quiz                                    | Vrai | Faux |
	| --------------------------------------- | ---- | ---- |
	| on observe des raies discrètes?         | X    |      |
	| on observe une infinitée de raies?      |      | X    |
	| on observe un spéctre continu de raies? |      | X    |
	| on observe plusieures lobes?            | X    |      |
### g. 
il sagit du 3 car les autres sont à une puissance d'ordre 10e-4
### h. 
la frequence de la fondamentale est de 1kHz, et la largeur de bande est de 1kHz, donnant une bande passante de 1kbps
### j. la frequence diminue par 2
passant à 500Hz, donnant donc 500bps

| affirmation                                               | 1         | 2          |
| --------------------------------------------------------- | --------- | ---------- |
| Plus la fréquence est petite et plus le débit binaire est | ~~grand~~ | **petit**  |
| Plus le débit binaire diminue et plus le spectre est      | ~~large~~ | **étroit** |
| Plus le débit est important et plus la bande passante est | **large** | ~~étroite~~           |

### Pourquoi générer des séquences pseudo aléatoires plutôt qu’un signal carré ?
 car une séquence pseudo-aléatoire sera plus representative d'un signal du monde réel (ex: la voix sur radio), plutot qu'un signal carré
## 2.
![[Pasted image 20231213094723.png]]

| Analyse des différents types d’encodage proposés                                                                                                                                                                        | VRAI | FAUX |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---- | ---- |
| L’inconvénient du code NRZ polaire est qu’il ne permet pas la création de transition lors de longues séquences de 0 et de 1 d’où le risque de perte de synchronisation et donc de données lors de la phase de décodage. | X    |      |
| Le code RZ unipolaire permet de s’affranchir de la problématique constatée pour le code NRZ polaire lors de l’émission d’une longue séquence de 1.                                                                      | X    |      |
| L’inconvénient du code RZ unipolaire, comme le code NRZ polaire, ne permet pas la création de transition lors de longues séquences de 0.                                                                                |      | X    |
| Le code MANCHESTER, de part sa bipolarité, permet de s’affranchir des problèmes constatés dans les 2 codes précédents. La synchronisation de l’horloge du récepteur sur l’émetteur est facilitée.                       | X    |      |

1. **Affirmation sur le code NRZ polaire :**
   - **Justesse :** Vrai.
   - **Explication :** Le code NRZ polaire ne change pas de niveau pendant la transmission d'un bit à 0 ou à 1, ce qui peut entraîner des difficultés de synchronisation, surtout lors de longues séquences de bits identiques. L'absence de transitions fréquentes peut compliquer la détection du début et de la fin des bits.

2. **Affirmation sur le code RZ unipolaire :**
   - **Justesse :** Vrai.
   - **Explication :** Le code RZ unipolaire résout en partie le problème du NRZ polaire en introduisant des transitions au milieu de chaque bit. Cela aide à la synchronisation et réduit le risque de perte de synchronisation lors de l'émission de longues séquences de bits identiques.

3. **Affirmation sur le code RZ unipolaire :**
   - **Justesse :** Faux.
   - **Explication :** Contrairement au NRZ polaire, le code RZ unipolaire introduit des transitions au milieu de chaque bit, même lors de longues séquences de 0. Cela aide à maintenir la synchronisation et évite le problème de perte de synchronisation rencontré par le NRZ polaire.

4. **Affirmation sur le code MANCHESTER :**
   - **Justesse :** Vrai.
   - **Explication :** Le code Manchester, en raison de sa bipolarité (transition à mi-bit), facilite la synchronisation de l'horloge du récepteur sur l'émetteur. Il surmonte les problèmes de synchronisation associés au NRZ polaire et au RZ unipolaire, offrant ainsi une meilleure fiabilité dans la détection des bits et la synchronisation des horloges.

| Code NRZ polaire                                                                                                                                                                                                                                                                                                                          | Code RZ unipolaire                                                                                                                                                            | Code MANCHESTER                                                                                              |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ |
| ![[Pasted image 20231211103558.png]]                                                                                                                                                                                                                                                                                                      | ![[Pasted image 20231211103612.png]]                                                                                                                                          | ![[Pasted image 20231211103627.png]]                                                                         |
| Avantage : le spectre est plus étroit que pour les 2 autres codes                                                                                                                                                                                                                                                                         | Avantage : Au spectre continu s’ajoute des raies discrètes pour chaque lobe. Ces raie vont donc faciliter, coté réception, la reconstitution du rythme de l’horloge.          | Avantage : A la différence des 2 autres spectres, il n’y a pas d’énergie à fréquence nulle.                  |
| Inconvénient : On est en présence d’énergie à fréquence nulle. Autrement dit, le signal numérique présente une composante continue non nulle qui, par définition, ne transporte aucune information et ne fait que provoquer des échauffements liés aux pertes par effet Joule dans les composants. Il convient donc de diminuer sa valeur | Inconvénient : la durée des variations est 2 fois plus courte donc le spectre est 2 fois plus large Inconvénient : idem que pour le code NRZ polaire du point de vue énergie. | Inconvénient : A la différence du code NRZ polaire, la largeur du lobe est également 2 fois plus importante. |

### PROBLEME : En quoi la logique d’encodage limite les risques de perte de données à la réception ?
car cela répond à des problèmes de perte de données tel que la perte de synchronisation durant l'envoi d'une suite répétée du même bit, ainsi qu'une resistance aux interférences et pertes de signal
## 3.
### a. Déduire des 2 relevés suivants : 
Quelle voie de l’oscilloscope représente le signal en bande de base => 1
Quelle voie de l’oscilloscope représente le signal modulé => 2
La durée d’un bit : 1 secondes
En déduire le débit binaire : 1/1 = 1bps
La fréquence de la porteuse : en 1 sec on a 5 fois la porteuse, donnant 5Hz
### b.
la première est la bande de base, avant modulation, tandis que sur le 2eme, le pic se situe sur la porteuse, à 5Hz, ce qui peut nous indiquer que la transmission a été modulée afin de transmettre sur le canal

## 4
### b
![[Pasted image 20231213093827.png]]
en vert: la partie emétrice
en rouge: la partie réceptrice
en bleu clair: le démodulateur
en violet: détecteur d’enveloppe
en bleu foncé: le filtre numérique
### c
![[Pasted image 20231213095044.png]]
en vert: le signal d'origine; en rose le signal modulé, en gris, les courbes du signal démodulé, avant (bleu) et après (jaune) l'application d'un filtre
### d
les signaux sont équivalent, avec cependant un léger décalage qui peut être justifié par le delai de traitement de chaques opérations
### e
![[Pasted image 20231213102244.png]]
il sagit d'un filtre passe-bas réglé à 200Hz, laissant une transition de 3Hz, d'aténuation de 40dB
### f
#### signal 1
![[Pasted image 20231213103512.png]]
il sagit d'une bande de base de largeur de 1Hz
#### signal 2
![[Pasted image 20231213103935.png]]
il sagit d'une bande transposée de largeur de bande de 2Hz, situé sur une porteuse de 5Hz
#### signal 3
![[Pasted image 20231213104202.png]]
il sagit d'un signal modulé de bande passante 2Hz de porteuse 5Hz et harmonique 10Hz
#### signal 4
![[Pasted image 20231213104843.png]]
il sagit du signal redréssé par la diode
### h
| Rapport de puissance signal / bruit Eb/No (dB) | Nombre de bits émis | Nombre d’erreurs binaires pour le nombre de bits émis | Taux d’erreur binaire |
| ---------------------------------------------- | ------------------- | ----------------------------------------------------- | --------------------- |
| 30 dB (signal peu ou pas bruité)               | 5001                | 0                                                     | 0%                     |
| 20 dB (signal bruité)                          | 5001                | 528                                                   | 10.56%                |
### i
![[Pasted image 20231213110106.png]]
aucunes erreurs
![[Pasted image 20231213110456.png]]
5 erreurs sur 20 bits (25% d'erreur) (le signal n'est pas traitable par la suite)
### PROBLEME : Quelles sont les limites d’une modulation/démodulation ASK ?
la modulation par amplitude est très sensible au bruit car il viens s'ajouter au signal, ce qui rend la lecture impossible
## 5
### a
le débit binaire est de 10bps (100ms/bit), la frequence f0 est de 70Hz et la frequence f1 est de 140Hz
### b
![[Pasted image 20231213112722.png]]
(oui c'est environ mais bon...)
vert: 20bps
rouge: 40bps
bleue: 100bps
l'aire sous la courbe semble constante, quand la hauteur augmente la largeur diminue
### PROBLEME : Quels sont les avantages et inconvénients d’une modulation FSK ?
les avantages par rapport à la modulation ASK est une meilleure resistance au bruit, ainsi qu'une synchronisation à chaques bits, lié à la modification de la porteuse. de plus, il a une bonne efficacitée energétique quel que soit la vitesse à emmetre, cependant, son efficacitée spectrale n'est pas des meilleures car son spectre est très étalé.


### Compte-rendu de Travaux Pratiques

#### Titre du TP: Génération de Signaux et Modulation Numérique

### Introduction
L'objectif de ces travaux pratiques était de comprendre les principes fondamentaux de la génération de signaux et de la modulation numérique. Nous avons exploré les avantages des séquences pseudo-aléatoires par rapport aux signaux carrés, examiné comment la logique d'encodage limite les risques de perte de données, utilisé MATLAB pour créer un signal modulé en amplitude, évalué les limites de la modulation/démodulation ASK, et analysé les avantages et inconvénients de la modulation FSK.

### Génération de Signaux et Logique d'Encodage
1. **Pourquoi générer des séquences pseudo-aléatoires plutôt qu'un signal carré ?**
   - La génération de séquences pseudo-aléatoires est privilégiée car elle représente mieux un signal du monde réel, comme la voix sur la radio, contrairement à un signal carré. Les séquences pseudo-aléatoires sont plus représentatives des fluctuations naturelles observées dans les signaux réels.

2. **En quoi la logique d'encodage limite les risques de perte de données à la réception ?**
   - La logique d'encodage, telle que le NRZ polaire, le RZ unipolaire, ou le Manchester, limite les risques de perte de données en introduisant des transitions régulières, facilitant ainsi la synchronisation et la détection des bits. Chaque type d'encodage résout spécifiquement les problèmes de perte de synchronisation associés à certaines séquences de bits.

### Création d'un Signal Modulé en Amplitude avec MATLAB
3. **Comment créer un signal modulé en amplitude avec MATLAB ?**
   - Pour répondre à cette question, nous avons utilisé MATLAB pour moduler un signal en amplitude. Nous avons suivi une démarche précise en utilisant les fonctions appropriées pour générer et moduler le signal, soulignant ainsi le lien entre la théorie et la pratique.

### Limites de la Modulation/Démodulation ASK
4. **Quelles sont les limites de la modulation/démodulation ASK ?**
   - La modulation par amplitude (ASK) présente des limites, notamment une sensibilité accrue au bruit, entraînant une difficulté de lecture du signal modulé. Ces limites doivent être prises en compte lors de l'utilisation de la modulation/démodulation ASK dans des environnements sujets à des niveaux élevés de bruit.

### Avantages et Inconvénients de la Modulation FSK
5. **Quels sont les avantages et inconvénients d'une modulation FSK ?**
   - La modulation FSK offre des avantages tels qu'une meilleure résistance au bruit, une synchronisation facilitée à chaque bit, et une efficacité énergétique constante. Cependant, son efficacité spectrale peut être limitée en raison d'un spectre étalé. Il est crucial de peser ces avantages et inconvénients en fonction des exigences spécifiques de la communication.

### Conclusion
Ce compte-rendu met en lumière l'importance de la génération de signaux et de la modulation numérique dans les communications. Les séquences pseudo-aléatoires, la logique d'encodage, l'utilisation de MATLAB, les limites de l'ASK, et les caractéristiques de la FSK ont été explorées. Ces travaux pratiques ont renforcé notre compréhension des concepts théoriques associés à la pratique de la génération et de la modulation des signaux.