import os, sys
from microbit import *
uart.init(9600)

while 1: # main data send/receiv loop
    uart.write(str(temperature())+'\n')
    sleep(2000)
sys.exit()
