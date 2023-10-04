import math

v:list[int] = [800]; q:float = 1.14; 
su = v[-1]
for n in range(1, 16) : # de 1 à 15
    v.append(math.ceil(v[-1]*q**n))
    su += v[-1]
    print(f'avec [italic green]n = {n} [/] on a [bold red]{v[-1]}[/], la somme totale est de [red]{su}[/]')