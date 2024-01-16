from math import exp
def resol(k:float, p:int):
	p_targ:float = 10/(10**p)
	print(p_targ)
	prec:float=0.1
	x:float=-1
	while prec > p_targ:
		while (2*(exp(x)<k)):
			x+=prec
		x-=prec
		prec:float=prec/10
	return(x)
