u:float=1.82
k=0
while u<4.84:
    u*=1.026
    k+=1
    print(f'{k + 2015}: {u}')