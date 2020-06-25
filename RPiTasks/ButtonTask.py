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
import time, sys, os, pygame, random
import numpy as np
from pandas import DataFrame as df
import gpiozero as gp


# ---------------------------------------------------------------------------------------------#
# initialize all of the spi stuff

# task buttons
buttonsDict = {
        'signal': [gp.Button(2,hold_time=.5),gp.Button(14,pull_up=False,hold_time=.5)],
        'LED': [gp.LED(3),gp.LED(15)]}
buttons = df(buttonsDict)

# reward buttons
rButtonDict = {
        'signal': [gp.Button(18,pull_up=False,hold_time=.1),gp.Button(10,pull_up=False,hold_time=.1)],
        'LED': [gp.LED(17),gp.LED(22)],
        'sol': [gp.DigitalOutputDevice(20),gp.DigitalOutputDevice(21)]}
rButtons = df(rButtonDict)



# ---------------------------------------------------------------------------------------------#
''' 
defining all of the subfunctions 

there are going to be functions for each of the states, and a function to 
figure out wait times etc when we start a new trial.
'''
# button press function
def bPressFn(button,buttons,rButtons):
    buttons['LED'][:].off() 
    buttons['signal'][:].when_held = None
    rButtons['LED'][:].on()
    rButtons['signal'][:].when_held = rewardFn()


def rewardFn(button,rButtons,dispTime):
    # turn off the leds and the reward buttons
    rButtons['LED'][:].off()
    rButtons['signal'][:].when_held = None
    
    # dispense the appropriate solenoid
    if button.pin == 'GPIO18':
        rButtons['sol'][0].on()
    elif button.pin == 'GPIO10':
        rButtons['sol'][1].on()
    
    # dispense for X time, then turn the rewards off
    time.sleep(dispTime)
    rButtons['sol'][:].off()







# setup required times for each trial
def setupTrial(touchTimeM,dispenseTimeM,interTrialM,numButtons):
    ''' 
    touchTime -- amount of time to touch the button
    dispenseTime -- amount of time to dispense the reward
    interTrial -- time to wait between trials
    buttonNumber -- which button do we want to use for the next trial?
    '''
    
    touchTime = random.uniform(touchTimeM[0],touchTimeM[1])
    dispenseTime = random.uniform(dispenseTimeM[0],dispenseTimeM[1])
    interTrial = random.uniform(interTrialM[0],interTrialM[1])
    buttonNumber = random.choices(range(0,2),k=numButtons)
    
    return [touchTime, dispenseTime, interTrial, buttonNumber]





# ---------------------------------------------------------------------------------------------#
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

'''
STATE_READY = 0
STATE_TOUCH = 1
STATE_READY_DISPENSE = 2
STATE_DISPENSE = 3
STATE_BETWEEN_TRIAL = 4

state = STATE_READY # initial state
random.seed
numButtons = 1 # the number of buttons that we want simultaneously pressed. gonna be max 2
touchTimeM = [0.25, 0.5] # range of time they have to hold the buttons
dispenseTimeM = [0.1, 0.2] # length of dispense time -- going to be short since they'll be in the cage all day
interTrialM = [1.0, 15.0] # time (in seconds) between trials

'''


random.seed
numButtons = 1 # the number of buttons that we want simultaneously pressed. gonna be max 2
touchTimeM = [0.25, 0.5] # range of time they have to hold the buttons
dispenseTimeM = [0.1, 0.2] # length of dispense time -- going to be short since they'll be in the cage all day
interTrialM = [1.0, 15.0] # time (in seconds) between trials



# ---------------------------------------------------------------------------------------------#
# start the infinite loop
while True:
    # pygame.event.get() # clears the pygame queue to prevent queue buildup
     
    [touchTime, dispenseTime, interTrial, buttonNumber] = setupTrial(touchTimeM, dispenseTimeM, interTrialM, numButtons)
    

    # set up the press function for the buttons, then wait until they're pressed
    buttons['LED'][numButtons].on() # turn on some buttonz
    goSound.play() # beep
    buttons['signal'][numButtons].hold_time = touchTime
    buttons['signal'][numButtons].when_pressed = bPressFn(button,buttons,rButtons)
    buttons['signal'][numButtons].wait_for_active()
    
    # set up the reward function for the buttons, then wait until they aren't pressed 
    goSound.play() # beep
    rButtons['LED'][:].on()
    rButtons['signal'][:].when_pressed = rewardFn(button,rButtons,dispenseTime)
    rButtons['signal'][:].wait_for_active()
    rewardSound.play()

    # test it out
    time.sleep(interTrial)

    
    
    
    
    ''' 
    if state == STATE_READY:
        if ready(button, touchTime): 
            goSound.play() # beep
            state = STATE_READY_DISPENSE # shift the state
            ledTuple(buttonNumber).off() # turn off the buttons
            ledReward.on() # turn on the LEDs
            
    if state == STATE_READY_DISPENSE:
        if buttonReward.is_pressed():
            rewardSound.play() # beep!
            rewardControl.on() # turn on the solenoid
            time.sleep(dispenseTime) # dispense for x seconds
            rewardControl.off() # turn off solenoid
            state = STATE_BETWEEN_TRIAL

    if state == STATE_BETWEEN_TRIAL:
        time.sleep(interTrial)
        [touchTime, dispenseTime, interTrial, buttonNumber] = setupTrial(touchTimeM, dispenseTimeM, interTrialM, numButtons)

    '''        
        





