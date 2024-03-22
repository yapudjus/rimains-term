# Langage: Python 3
# Debut
# SOMME <- Ent 0
SOMME:int = 0
# run <- Bool True
RUN:bool = True
# TantQue run
while RUN:
    # lire INP
    INP:str = str(input("Entrez un nombre: "))
    # Si INP == '' (vide) RUN <- Bool False
    if INP == '': RUN = False
    # Sinon SOMME <- SOMME + INP
    else: SOMME = SOMME + int(INP)
    # Fin Si
# Fin TantQue
# Afficher SOMME sur ecran
print(SOMME)
# Fin