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
nous pouvons déduire que le protocole ARP permet de lier les @MAC\[physiques] et les ports du switch sur un réseau
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
en effectuant un ping vers `www.nsi.fr` depuis .0.3, on remarque deux échanges DNS <br>
![](Pasted%20image%2020240212082733.png)<br>
## WEB
en ayant un srvweb sur .2.2 {www.nsi.fr} <br>
![](Pasted%20image%2020240212085359.png)<br>
les paquets sont les suivants:
- 1&2: resolution du domaine via le dns
- 6: requete de la page parent du site (/)
- 8: reponse du site et retour de la page parent (/)
- 10&{12,14,16,18,20,22}: requete et reponse de l'image du site
## http vs https
en http, on voit que tout est transmi en clair, par exemple (en local):<br>
![](Pasted%20image%2020240212090313.png)<br>
tandis qu'en https, en prenant l'exemple de parcoursup, aucun trafic n'est lisible<br>
![](Pasted%20image%2020240212091327.png)<br>
cependant, ce système est (difficilement) contournable par une attaque par mitm, ainsi qu'un contournement de certificat ou une injection de certificat auprès du client, nous donnant accès au traffic<br>
![](Pasted%20image%2020240212091633.png)<br>
(içi, le certificat d'autoritée unique à mon proxy d'ecoute a été ajoutté en confiance sur firefox, seulement sur un conteneur d'ecoute)<br>
### conclusion http,s
l'usage du protocole https est à priviligier car il permet une "sécuritée" dans l'echange de données, tandis qu'une communication http classique est visible de tous, cependant, d'autres mesures sécurité sont à prendre, comme les classiques "ne pas cliquer sur tout les liens", "ne pas entrer ses info partout" et "retaper le lien à la main pour éviter des remplacements de lettres (ex: remplacer le a de amazon.fr avec un symbole russe ressemblant à un a)"