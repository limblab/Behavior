# -*- coding: utf-8 -*-
"""
ButtonTask()

Multi-button task for the cage. Basic layout is a square with a bunch of 
different buttons. Press a button (or two) when it lights up. After a certain
number of successful button presses, turn on the reward panel.

This is implemented for Raspberry Pi. Go ahead and try to get it to work on 
other systems -- using the GPIO libraries will be kind of funny.
"""

# import all needed modules
import pygame, random, os
from time import sleep
from pandas import DataFrame as df
import gpiozero as gp

pygame.init()

# ---------------------------------------------------------------------------------------------#
# initialize manipulanda stuff

# task buttons
proxDict = {
        'signal': gp.LineSensor(14,pull_up=False),
        'irLED': gp.LED(15)}
prox = df(proxDict,index=[0])
prox['irLED'][0].on()


# reward buttons
rButtonDict = {
        'signal': [gp.Button(18,pull_up=False,hold_time=.1)],
        'LED': [gp.LED(17)],
        'sol': [gp.DigitalOutputDevice(20)]}
rButton = df(rButtonDict)




# ---------------------------------------------------------------------------------------------#
# initalize the mixer to create the sounds
# why is the sampling frequency so obnoxious? dunno...
pygame.mixer.init(frequency=163840,buffer=32000)
#pygame.mixer.init(frequency=16840,buffer=32000)
goSound = pygame.mixer.Sound(os.path.join("tones","go3_interp.wav"))
rewardSound = pygame.mixer.Sound(os.path.join("tones","reward3_interp.wav"))

'''

# ---------------------------------------------------------------------------------------------#
# intialize the screen so we can have colors etc
size = [800, 400]
screen = pygame.display.set_mode(size)
BLACK = (0,0,0)
WHITE = (255,255,255)
YELLOW = (255,255,0)
BLUE = (0,0,255)
GREEN = (0,255,0) 


screen.fill(BLACK)

'''
# ---------------------------------------------------------------------------------------------#
# start the infinite loop
while True:
    # pygame.event.get() # clears the pygame queue to prevent queue buildup
   
    # screen.fill(BLUE) 
    # pygame.display.update() 
   
    goSound.play()
    prox['signal'][0].wait_for_active()
    print('Monkey in the corner!')
    # screen.fill(YELLOW)
    # pygame.display.update()
    rewardSound.play()

    rButton['LED'][0].on()
    rButton['signal'][0].wait_for_press()
    sleep(.1)
    rButton['sol'][0].on()
    sleep(.25)
    rButton['sol'][0].off()

    rButton['LED'][0].off()





    # screen.fill(GREEN)
    # pygame.display.update()

    print('reward given')

