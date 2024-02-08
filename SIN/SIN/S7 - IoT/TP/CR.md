## à del (ou pas)
![[Pasted image 20240208221006.png]]
## table ARP
avant toute communication, et sur un reseau à 2 machines, le setup est le suivant
![[Pasted image 20240208221458.png]]
nous effectuons ensuite un ping depuis .1 vers .2, et constatons que l'@MAC correspondant à l'@IP de .2 est désormais dans la table ARP
![[Pasted image 20240208222055.png]]
en examinant le trafic reseau de la machine 1, on voit:
![[Pasted image 20240208222422.png]]
le paquet 1 est la machine 1 qui demande à tout le reseau (target @FF:FF:FF:FF:FF:FF) "EH QUI SAIT QUI C LE .2???"
le paquet 2 est la réponse donnant l'@MAC correspondante
### un exemple sur un reseau domestique:
![[Pasted image 20240208223521.png]]
### conclusion sur ARP
nous pouvons déduire que le protocole ARP permet de lier les @MAC\[physiques] et les ports du switch\[logiques] sur un réseau
## CAM/SAT
nous constatons en 1er que la table cam/sat du switch est vide
nous lancons ensuite un ping vers .2
![[Pasted image 20240208225223.png]]
nous pouvons constater que les appareils ayant communiqué apparaissent désormais sur la table du switch
![[Pasted image 20240208225743.png]]
de plus, l'appareil .3 à reçu une reqt ARP, cependant, **elle n'y a pas rep**
désormais, nous envoyons un ping vers .3, et pouvons constater que la table s'enrichie avec le port et l'@mac de la machine .3
![[Pasted image 20240208230132.png]]
de+, .3 recoit un autre ARP req, y repondant cette fois car elle connait l'@mac demandée ~~(normal c'est elle)~~
![[Pasted image 20240208230430.png]]
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
en tracant la route entre .0.1 et .2.1, on voit que la passerelle sert de... bah passerelle
![[Pasted image 20240208231632.png]]
### conclusion passerelle
dans ce TP, nous avons vu l'utilitée des passerelles qui permettent de faire communiquer des machines de différents réseaux entre elles, en servant de... ponts (yep j'arrête la blague)