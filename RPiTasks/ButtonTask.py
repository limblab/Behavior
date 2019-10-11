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
import time, sys, os, pygame, random

# initialize all of the buttons - using GPIO notation for clarity sake
buttonOne = Button("GPIO4") # pin 7
buttonTwo = Button("GPIO17") # pin 11
buttonThree = Button("GPIO27") # pin 13
buttonFour = Button("GPIO22") # pin 15
buttonTuple = (buttonOne, buttonTwo, buttonThree, buttonFour)

# initalize the mixer to create the sounds
# why is the sampling frequency so obnoxious? dunno...
pygame.mixer.init(frequency=8192,buffer=4096)
goSound = pygame.mixer.Sound(os.path.join("tones","go3.wav"))
rewardSound = pygame.mixer.Sound(os.path.join("tones","reward3.wav"))



''' 
initalize the state variables - wait time etc.

states:
    STATE_READY - ready to start the trial
    STATE_TOUCH - button is currently being touched (do we still need this?)
    STATE_READY_DISPENSE - success, collect your reward!
    STATE_DISPENSE - touched the button, go collect your reward!
    STATE_BETWEEN_TRIAL - wait time between trials; forces the monkey to do a lot of things
    
current status variables:
    state - the current state
    button - button or buttons we're currently using: set up a tuple holding button pointers
    touchTimeM - touch time max and min (how long to touch the buttons)
    dispenseTimeM - dispense time min and max
    interTrialM - inter trial min and max
    
'''
STATE_READY = 0
STATE_TOUCH = 1
STATE_READY_DISPENSE = 2
STATE_DISPENSE = 3
STATE_BETWEEN_TRIAL = 4

state = STATE_READY
random.seed
button = random.randrange()




# initialize the screen