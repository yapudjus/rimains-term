u:float=30
S:float=30
n:int=0
while S<=300.0:
    u*=0.97
    S+=u
    n+=1
print(2015+n)