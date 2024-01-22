# intro
le but de ce tp est de découvrir un environement linux ainsi que la gestion simple d'un réseau de cluster, içi sur un ensemble de raspberry, ainsi que l'usage de commandes et protocoles de base, tels que
- le ssh pour gérer la connexion à distance
- l'usage du gestionnaire de paquets aptitude
- la création de canaux sécurisés ainsi que leur accès par clé privées
- la gestion de communication directe entre plusieurs appareils connéctés en ethernet
- un usage basique de python et de mpich
# installation du rpi
 - on flash l'image 
	 - ![[Pasted image 20240110103933.png]]
 - on trouve l'ip du rpi
	 - ![[Pasted image 20240110104011.png]]
 - on se connecte en sse et mets à jours les dépots
	 - ![[Pasted image 20240110104102.png]]
 - on mets à jours touts les packages
	 - ![[Pasted image 20240110104159.png]]
 - on configure l'accès ssh par clé
	 - on gen une paire de clés pub/priv, sur linux la commande est `ssh-keygen`
		 - on obtiens deux fichiers se trouvant dans `~/.ssh/`
		 - `id_rsa  id_rsa.pub`, le .pub est nôtre clé publique à renseiger sur les appareils, celui sans extension est nôtre clé pà onserver secrete et ne pas partager
	 - j'ajoute mes clé publiques au fichier `~/.ssh/authorized_keys` du rpi
	 - une clé ressemble à ça: ```ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC0/RBZALbslBlUM4Olx6+J48wU8ReRPgrCjzLrSVTaDsJLzz8mXgJhKjMEtU4UmJzI/eUBUcR7Ia9AUcW2RBpfcgyL12yDCro6OWoXyzcMNR3Sj9Yf8lHa+xEqpU9+tETmLX2LBMshz/djtRbV2zIEIRiyFwys72cpJf5BiNZCXqSzsv9Gfo7K8Tlx/YRe5M7l9MNXsXu+/vjmT+2fIfgZlHnyMEEJOD83gQ9H9Pf/2QuLEr5N96yelrkVunW1dat6AcQ7yxIQQy9aTdG0ZNCGYYWdyQtwSbIeHPMbGkLONwItTphWAr+ZxqjSW/ogh+cQ/VN6bKXCqGiggEI8j2nqiM32pJYXIy1hYf1IXeIxb+SDan36HK3+GIjMIYPoHc7+WG5vfiuzuFzhwxZAmRbTz+0jtst6CAlDa8rY90b758asX9h2aa+LBGAL7oDgY7DYcAg5pKi77tqQii7BB9eLFDNU6VQAs2o+1Fyg6+rfKB6z62gUl/O+gMzevNLxAos= yapudjus@thickpad```
 - quand fini on reboot
# on clone la carte via balena etcher
## on connecte le maitre aux autres
**cette config n'est pas apliquée au démarrage**
### en direct
on tape la commande `sudo ip addr add dev eth0 10.0.1.1/30` sur le maitre (le /30 permets 2 hotes utilisables, pour une connection entre 2 appareils)
![[Pasted image 20240115103116.png]]
sur l'esclave on tape  `sudo ip addr add dev eth0 10.0.1.2/30` 
### avec un switch
#### sur le maitre
 `sudo ip addr add dev eth0 10.0.1.1/24` 
 
#### sur les travailleurs
 `sudo ip addr add dev eth0 10.0.1.{num}/24`  avec num etant l'identifiant de l'appareil, de 2 à 254
 on les branchent sur un même switch, en théorie aucun routeur n'est nécessaire mais je n'ai pas pu le tester
 