# -*- coding: utf-8 -*-
"""
MultiGadget()

Key grasp, precision grasp, power grasp. 
"""

# import all needed modules
import time, sys, os, pygame, random, spidev, gpiozero
from math import sin, pi


# Set the reset pins for the LSR 
rst = gpiozero.DigitalOutputDevice("GPIO22",active_high=False,initial_value=False)

# initialize all of the spi stuff for the LSR
LSR = spidev.SpiDev()
LSR.open(0,1)
LSR.max_speed_hz = 15600000

# Prep everything for the ADC -- MCP3004
buttonOne = {
        "FSROne": gpiozero.MCP3004(channel=0, device=0),
        "FSRTwo": gpiozero.MCP3004(channel=1, device=0)
}
buttonTwo = {
        "FSROne": gpiozero.MCP3004(channel=3, device=0),
        "FSRTwo": gpiozero.MCP3004(channel=4, device=0)
}


devices = {
        "buttonOne": buttonOne,
        "buttonTwo": buttonTwo
}




'''
State variables

states:
    STATE_CURSOR: Cursor is being controlled by manipulanda
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

STATE_CURSOR = 0
STATE_READY_DISPENSE = 1
STATE_BETWEEN_TRIAL = 2

state = STATE_CURSOR 


''' 
--- important variables ---
(could consider loading some of these from and external settings file)
    targets: location of all of the targets. Dictionary with location of centers and sizes of boxes 
    targetHoldTime: range of target hold times (in seconds). Set with two values
    dispenseTime: range of dispense hold times (in seconds). Set with two values
    interTrial: range of length between trials (in seconds). Set with two values

    current_targets: location of all of the targets. Likely a tuple, or array of some variety
    current_targetHoldTime: length of time to hold the target (in seconds)
    current_dispenseTime: range of dispense hold times (in seconds)
    current_interTrial: range of length between trials (in seconds)

    gain: multiplier for the cursor -- tuple for the two cursors
    offset: offset for the cursor -- tuple for the two cursors

    cursorLocn: gain*force + offset  -- should we consider adding some filtering? maybe...
'''

''' just commenting this out so we can run through things without getting constant errors
    targets = {}
    targetHoldTime: range of target hold times (in seconds)
    dispenseTime: range of dispense hold times (in seconds)
    interTrial: range of length between trials (in seconds)

    cTargets: current location of all of the targets. Likely a tuple, or array of some variety
    cTargetHoldTime: current length of time to hold the target (in seconds)
    cDispenseTime: current dispense hold (in seconds)
    cInterTrial: current length between trials (in seconds)

    gain: multiplier for the cursor -- tuple for the two cursors
    offset: offset for the cursor -- tuple for the two cursors

    cursorLocn: gain*force + offset  -- should we consider adding some filtering? maybe...
    force: what it sounds like -- will be a tuple for forces from each fsr
boxLocation = 
locationHoldTime = 
dispenseTimeM = [0.1, 0.2] # length of dispense time -- going to be short since they'll be in the cage all day
interTrialM = [1.0, 15.0] # time (in seconds) between trials
graspType = 
'''



def get_cursor_locn(devices,gain=[1,1],offset=[0,0]):
    
    cursor = {"x":x, "y",y}
    cursorLocn = {
            "cursorOne": cursor,
            "cursorTwo": cursor}
    
    forces = []
    forces.append(devices


# let's get ready to loop

while True:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
    
    
    if state == STATE_CURSOR: 
        ''' we don't need different settings for different devices -- 
            They are all just FSRs connected to amplifiers. just make sure
            the offset and gain are appropriate on the board. '''
        # get the current forces for each device
        




        
    if state = STATE_READY_DISPENSE:
         if buttonReward.is_pressed():
            rewardSound.play() # beep!
            rewardControl.on() # turn on the solenoid
            time.sleep(dispenseTime) # dispense for x seconds
            rewardControl.off() # turn off solenoid
            state = STATE_BETWEEN_TRIAL
            
    if state = STATE_BETWEEN_TRIAL:
        time.sleep(interTrial)
        
