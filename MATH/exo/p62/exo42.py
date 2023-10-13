def resol(k:float):
    x:float=-20
    while ((1.5**x)<k):
        x+=0.1
    return x

def resol2(k:float):
    x:float=-20
    while (((0.8**x)*2)>k):
        x+=0.1
    return x
