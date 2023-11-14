import math, shutil

def f(x: float) -> float:
    # generate a function that is only increasing
    return math.sqrt(x)+1

def integral_apprx(a: float, b: float, func, samples:int) -> float:
    delta_x:float = (b - a) / samples
    total:float = 0
    total_aera_rect_inf:float = 0
    total_aera_rect_sup:float = 0
    for i in range(samples):
        # print a progress bar of the computation that is n char wide, n is the max size of the console - the message length
        # n = shutil.get_terminal_size().columns - len(f'computing {i}th sample, [{i}/{samples}] ||')
        # {"#"*int((i//samples)*n)}{"-"*int(samples-(i//samples))*n}
        print(f'computing {i}th sample, [{i}/{samples}]', end='\r')
        total_aera_rect_inf += func(a + i*delta_x) * delta_x
        total_aera_rect_sup += func(a + (i+1)*delta_x) * delta_x
    total_average:float = (total_aera_rect_inf + total_aera_rect_sup) / 2
    return total_average, total_aera_rect_inf, total_aera_rect_sup

print(integral_apprx(0, 10, f, 10000))
