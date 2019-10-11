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
from gpiozero import LED, Button
import time, sys, os, pygame

# initialize all of the buttons - using GPIO notation for clarity sake
buttonOne = Button("GPIO4") # pin 7
buttonTwo = Button("GPIO17") # pin 11
buttonThree = Button("GPIO27") # pin 13
buttonFour = Button("GPIO22") # pin 15


# initalize the mixer to create the sounds
# why is the sampling frequency so obnoxious? dunno...
pygame.mixer.init(frequency=8192,buffer=4096)
goSound = pygame.mixer.Sound(os.path.join("tones","go3.wav"))
rewardSound = pygame.mixer.Sound(os.path.join("tones","reward3.wav"))

# initalize the state variables - wait time etc.



# initialize the screen