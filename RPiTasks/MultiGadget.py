# -*- coding: utf-8 -*-
"""
MultiGadget()

Key grasp, precision grasp, power grasp. 
"""

# import all needed modules
import time, sys, os, pygame, random, spidev, gpiozero, pandas
from math import sin, pi


# Set the reset pins for the LSR 
reset = gpiozero.DigitalOutputDevice("GPIO22",active_high=False,initial_value=False)

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
    STATE_NOT_OVER: Cursor is not currently over the target
    STATE_OVER: Cursor is over the target
    STATE_READY_DISPENSE: success, collect your reward!
    STATE_BETWEEN_TRIAL: waiting between trials

'''

STATE_NOT_OVER = 0
STATE_OVER = 1
STATE_READY_DISPENSE = 2
STATE_BETWEEN_TRIAL = 3

state = STATE_NOT_OVER 


''' 
--- important variables ---
(could consider loading some of these from and external settings file)
    targets: location of all of the targets. Dictionary with location of centers and sizes of boxes 
    targetHoldTime: range of target hold times (in seconds). Set with two values
    dispenseTime: range of dispense hold times (in seconds). Set with two values
    interTrial: range of length between trials (in seconds). Set with two values

    cTargets: location of all of the targets. Likely a tuple, or array of some variety
    cTargetHoldTime: length of time to hold the target (in seconds)
    cDispenseTime: range of dispense hold times (in seconds)
    cInterTrial: range of length between trials (in seconds)

    gain: multiplier for the cursor -- tuple for the two cursors
    offset: offset for the cursor -- tuple for the two cursors

    cursorLocn: gain*force + offset  -- should we consider adding some filtering? maybe...
'''

''' just commenting this out so we can run through things without getting constant errors
    targets = {}
    targetHoldTime = [ ]
    dispenseTime = [ ]
    interTrial = [ ]

    cTargets = []
    cTargetHoldTime = []
    cDispenseTime = []
    cInterTrial = []

    gain = ()
    offset = ()

    cursorLocn = []
    force = []


boxLocation = []
locationHoldTime = []
dispenseTimeM = []
interTrialM = []
graspType = []
'''
#initialize some screen stuff
size = [400,300] #change this to whatever the right size is when you figure it out
screen = pygame.display.set_mode(size)
BLACK = (0,0,0)
WHITE = (255, 255, 255)

#define target 
class target():
    def __init__(self,x,y,width,height):
        self.color = BLACK
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        
    def draw(self, screen):
        pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))
        
    def isOver(self, pos):
        if pos[0] > self.x and pos[0]<self.x+self.width:
            if pos[1]>self.y and pos[1]<self.y+self.height:
                return True
            
        return False

def redrawWindow():
    screen.fill(WHITE)
    mainTarget.draw(screen)

# take in the device information along with gains, and return the cursor locations
def get_cursor_locn(devices,gain=[1,1],offset=[0,0]):
    
    x = 0
    y = 0
    
    cursor = {"x":x, "y":y}
    cursorLocn = {
            "cursorOne": cursor,
            "cursorTwo": cursor}
    
    forceXfsrOne = devices["buttonOne"]["FSROne"].value()
    
    
    cursorLocn["cursorOne"]["x"] = gain*(devices["buttonOne"]["FSROne"].value())
    cursorLocn["cursorOne"]




mainTarget = target(random.choice(tuple(targets)))

# let's get ready to loop

while True:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
    clock.tick(60)
    redrawWindow()
    pygame.display.flip
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
            
    if state == STATE_NOT_OVER:
        ''' we don't need different settings for different devices -- 
            They are all just FSRs connected to amplifiers. just make sure
            the offset and gain are appropriate on the board. '''
        # get the current forces for each device
        start_time = time.time()
        if mainTarget.isOver(cursorLocn):
            state = STATE_OVER
            
    if state == STATE_OVER:
        if mainTarget.isOver(cursorLocn):
            current_time = time.time()
            timer = current_time-start_time
            if timer > targetHoldTime:
                state = STATE_READY_DISPENSE
        else:
                state = STATE_NOT_OVER

        
    if state == STATE_READY_DISPENSE:
         if buttonReward.is_pressed():
            rewardSound.play() # beep!
            rewardControl.on() # turn on the solenoid
            time.sleep(dispenseTime) # dispense for x seconds
            rewardControl.off() # turn off solenoid
            state = STATE_BETWEEN_TRIAL
            
    if state == STATE_BETWEEN_TRIAL:
        time.sleep(interTrial)
        #change the target parameters
        state = STATE_NOT_OVER
