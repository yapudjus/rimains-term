## à del (ou pas)
![](Pasted%20image%2020240208221006.png)
## table ARP
avant toute communication, et sur un reseau à 2 machines, le setup est le suivant <br>
![](Pasted%20image%2020240208221458.png) <br>
nous effectuons ensuite un ping depuis .1 vers .2, et constatons que l'@MAC correspondant à l'@IP de .2 est désormais dans la table ARP <br>
![](Pasted%20image%2020240208222055.png) <br>
en examinant le trafic reseau de la machine 1, on voit: <br>
![](Pasted%20image%2020240208222422.png) <br>
le paquet 1 est la machine 1 qui demande à tout le reseau (target @FF:FF:FF:FF:FF:FF) "EH QUI SAIT QUI C LE .2???" <br>
le paquet 2 est la réponse donnant l'@MAC correspondante
### un exemple sur un reseau domestique:
![](Pasted%20image%2020240208223521.png)
### conclusion sur ARP
nous pouvons déduire que le protocole ARP permet de lier les @MAC\[physiques] et les ports du switch\[logiques] sur un réseau
## CAM/SAT
nous constatons en 1er que la table cam/sat du switch est vide <br>
nous lancons ensuite un ping vers .2 <br>
![](Pasted%20image%2020240208225223.png) <br>
nous pouvons constater que les appareils ayant communiqué apparaissent désormais sur la table du switch <br>
![](Pasted%20image%2020240208225743.png) <br>
de plus, l'appareil .3 à reçu une reqt ARP, cependant, **elle n'y a pas rep** <br>
désormais, nous envoyons un ping vers .3, et pouvons constater que la table s'enrichie avec le port et l'@mac de la machine .3 <br>
![](Pasted%20image%2020240208230132.png) <br>
de+, .3 recoit un autre ARP req, y repondant cette fois car elle connait l'@mac demandée ~~(normal c'est elle)~~ <br>
![](Pasted%20image%2020240208230430.png) <br>
### conclusion?
la table CAM/SAT permet au switch de savoir "où est qui", afin de distribuer les paquets aux bons destinataires, et pas juste envoyer le paquet à tt le monde
## Routeur et passerelle
### sans configurer nôtre passerelle
depuis 192.168.0.1, les machines suivantes sont:
- 192.168.0.2 : **accessible**
- 192.168.0.3 : **accessible**
- 192.168.2.1 : non
- 192.168.2.2 : non
### en conf uniquement la passerelle
depuis 192.168.0.1, les machines suivantes sont:
- 192.168.0.2 : **accessible**
- 192.168.0.3 : **accessible**
- 192.168.2.1 : non
- 192.168.2.2 : non
### En configurant aussi les ordinateurs
depuis 192.168.0.1, les machines suivantes sont:
- 192.168.0.2 : **accessible**
- 192.168.0.3 : **accessible**
- 192.168.2.1 : **accessible**
- 192.168.2.2 : **accessible**
en tracant la route entre .0.1 et .2.1, on voit que la passerelle sert de... bah passerelle <br>
![](Pasted%20image%2020240208231632.png) <br>
### conclusion passerelle
dans ce TP, nous avons vu l'utilitée des passerelles qui permettent de faire communiquer des machines de différents réseaux entre elles, en servant de... ponts (yep j'arrête la blague)
## DNS
on configure un ordinateur sur le reseau comme un serveur DNS et on ajoute une entrée dans sa table de liaison <br>
![](Pasted%20image%2020240209074845.png) <br>
