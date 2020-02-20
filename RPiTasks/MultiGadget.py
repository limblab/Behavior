# -*- coding: utf-8 -*-
"""
MultiGadget()

Key grasp, precision grasp, power grasp. 
"""

# import all needed modules
import time, sys, os, pygame, random, spidev



# initialize all of the spi stuff
LSR = spidev.SpiDev()
LSR.open(0,0)
LSR.max_speed_hz = 15600000






'''
State variables

states:
    STATE_READY: ready to start trial
    STATE_TOUCH: grasp device is currently being touched
    STATE_READY_DISPENSE: success, collect your reward!
    STATE_BETWEEN_TRIAL: waiting between trials

status variables:
    state: the current state
    boxLocation: where the cursor needs to be moved to
    locationHoldTime: how long the cursor needs to be held in the box
    dispenseTimeM: dispense time min and max
    interTrialM: inter trial min and max
    graspType: which grasp device is being used. will activate different subfunction for each different device
'''

STATE_READY = 0
STATE_TOUCH = 1
STATE_READY_DISPENSE = 2
STATE_BETWEEN_TRIAL = 3

state = STATE_READY 

boxLocation = 
locationHoldTime = 
dispenseTimeM = [0.1, 0.2] # length of dispense time -- going to be short since they'll be in the cage all day
interTrialM = [1.0, 15.0] # time (in seconds) between trials
graspType = 

# let's get ready to loop

while True:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
    
    if state == STATE_READY:
        if # the grasp device is touched
            goSound.play() # beep
            state = STATE_READY_DISPENSE 
            
            
            
            
    if state == STATE_TOUCH: #for all graspTypes, start the designated task with the task parameters. If it succeeds, go to STATE_READY_DISPENSE, if it fails, go to STATE_READY
        if graspType = keyGrasp:
            
            
        if graspType = powerGrasp:
            
            
        if graspType = precisionGrasp:
            
            
       
        
    if state = STATE_READY_DISPENSE:
         if buttonReward.is_pressed():
            rewardSound.play() # beep!
            rewardControl.on() # turn on the solenoid
            time.sleep(dispenseTime) # dispense for x seconds
            rewardControl.off() # turn off solenoid
            state = STATE_BETWEEN_TRIAL
            
    if state = STATE_BETWEEN_TRIAL:
        time.sleep(interTrial)
        