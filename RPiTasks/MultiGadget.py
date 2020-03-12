# -*- coding: utf-8 -*-
"""
MultiGadget()

Key grasp, precision grasp, power grasp. 
"""

# import all needed modules
import time, sys, os, pygame, random, spidev, gpiozero, pandas
from math import sin, pi, cos
from pynput.mouse import Controller


# Set the reset pins for the LSR 
reset = gpiozero.DigitalOutputDevice("GPIO22",active_high=False,initial_value=False)

# initialize all of the spi stuff for the LSR
LSR = spidev.SpiDev()
LSR.open(0,1)
LSR.max_speed_hz = 15600000

# Prep everything for the ADC -- MCP3004
#devices = pandas.DataFrame(index=['deviceOne','deviceTwo'],cols=['FSROne','FSRTwo'])

'''

'''
devices = pandas.DataFrame(columns=['DeviceOne','DeviceTwo'],index=['FSROne','FSRTwo'])
devices.DeviceOne.FSROne = gpiozero.MCP3004(channel=0,device=0)
devices.DeviceOne.FSRTwo = gpiozero.MCP3004(channel=1,device=0)
devices.DeviceTwo.FSROne = gpiozero.MCP3004(channel=2,device=0)
devices.DeviceTwo.FSRTwo = gpiozero.MCP3004(channel=3,device=0)




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

    gain = ()
    offset = ()



locationHoldTime = []
dispenseTimeM = []
interTrialM = []
graspType = []
'''
#initialize some screen stuff
size = [800,480] #change this to whatever the right size is when you figure it out
screen = pygame.display.set_mode(size)
BLACK = (0,0,0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
targets = {(600,100, 100, 100)}
targetHoldTime = 1
dispenseTime = 0.1
interTrial = 1
gain = [50,50]
offset = [700, 360]


#define target 
class target():
    def __init__(self,x,y,width,height):
        self.color = RED
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        
    def draw(self, screen):
        pygame.draw.rect(screen, self.color, (self.x, self.y, self.width, self.height))
        
    def isOver(self, pos):
        self.color = RED
        if pos[0] > self.x and pos[0]<self.x+self.width:
            if pos[1]>self.y and pos[1]<self.y+self.height:
                self.color = GREEN
                return True
            
        return False



# defining modules

def redrawWindow():
    screen.fill(BLACK)
    mainTarget.draw(screen)

def get_cursor_locn(devices,gain=[1,1],offset=[0,0]):
    # take in the device information along with gains, and return the cursor locations
    cursorLocnCol = ['cursorOne','cursorTwo'];
    cursorLocn = pandas.DataFrame(columns=cursorLocnCol,index=['X','Y'])
    
    force = []
    force.append()
    
    
    cursorLocn.cursorOne.X = gain[0]*(force[0]*cos(3*pi/4)+force[1]*cos(pi/4))+offset[0]
    cursorLocn.cursorOne.Y = gain[0]*(force[0]*sin(3*pi/4)+force[1]*sin(pi/4))+offset[0]
    cursorLocn.cursorTwo.X = gain[1]*(force[2]*cos(3*pi/4)+force[3]*cos(pi/4))+offset[1]
    cursorLocn.cursorTwo.Y = gain[1]*(force[2]*sin(3*pi/4)+force[3]*sin(pi/4))+offset[1]

cursorImage = pygame.image.load('hiclipart.png')

def fakeCursorButton(button):
    if button.isPressed: #this is placeholder syntax, will be changed to whatever syntax the actual button uses to indicate pressed/not pressed
        pygame.draw.rect(screen, GREEN, (100, 100, 100, 100))
        screen.blit(cursorImage, (125, 125))
    if not button.isPressed:
        pygame.draw.rect(screen, RED, (100, 100, 100, 1000))
        screen.blit(cursorImage, (125, 225))
        
mainTarget = target(random.choice(tuple(targets)))

# let's get ready to loop
cont = True
clock = pygame.time.Clock()
mouse = Controller()


while cont:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
    clock.tick(60)
    redrawWindow()
 #   fakeCursorButton(button)
    pygame.display.flip
    mouse.position = (offset[0] + gain[0]*(FSROne.value*cos(3*pi/4)+FSRTwo*cos(pi/4)), offset[1] + gain[1]*(FSRTwo.value*sin(3*pi/4)+FSRTwo*sin(pi/4)))
    
    
    for event in pygame.event.get():
        cursorLocn = pygame.mouse.get_pos()
        if event.type == pygame.MOUSEBUTTONDOWN:
            cont = False
        if event.type == pygame.QUIT:
            cont = False
            
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
