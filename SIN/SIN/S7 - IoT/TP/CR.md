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
