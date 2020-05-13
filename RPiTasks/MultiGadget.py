# -*- coding: utf-8 -*-
"""
MultiGadget()

Key grasp, precision grasp, power grasp. 


Notes on working with the cursors and printing to the screen:
    pygame works on a coordinate system that starts in the top left corner and
    goes down (Y) and to the right (X). By comparison, we will want to store
    the cursor location using the *real* coordinates (in inches) from the center
    of the screen. This means we will need to do a conversion between internal
    coordinates and screen coordinates.
    
    We will also want to split the screen into two if we want to run two 
    devices at once. Either that or control the cursor with the two devices 
    together.... hmmm....
    

Notes on storage of task performance:
    For the time being we'll plan to store everything on the SD card, with 
    the plan of using the cbsdk or someother method to store to the cerebus 
    through comments in the future.

"""

# import all needed modules
import time, sys, os, pygame, random, spidev, gpiozero, pandas
from math import sin, pi, cos
from pynput.mouse import Controller


# set up gpiozero pins for the task and reward buttons -- gave up on the linear shift register
taskButtons = [gpiozero.Button(2), gpiozero.Button(14)]  # Button0: GPIO2; Button1: GPIO14
taskLEDs = [gpiozero.LED(3), gpiozero(15)] # Button0LED: GPIO3; Button1LED: GPIO15
rewardButtons = [gpiozero.Button(18), gpiozero.Button(23)] # Reward0Button: GPIO18; Reward1Button: GPIO23
rewardLEDs = [gpiozero.LED(17), gpiozero.LED(22)] # Reward0LED: GPIO17; Reward1LED: GPIO22



''' Prep everything for the ADC -- MCP3004
Just using the MCP3004 predefined device from gpiozero. Thanks gpiozero!
'''
devices = pandas.DataFrame(columns=['DeviceOne','DeviceTwo'],index=['FSROne','FSRTwo'])
devices.DeviceOne.FSROne = gpiozero.MCP3004(channel=0,device=0)
devices.DeviceOne.FSRTwo = gpiozero.MCP3004(channel=1,device=0)
devices.DeviceTwo.FSROne = gpiozero.MCP3004(channel=2,device=0)
devices.DeviceTwo.FSRTwo = gpiozero.MCP3004(channel=3,device=0)


cursors = pandas.DataFrame(columns=['CursorOne','CursorTwo'],index=['X','Y'])


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
    targets: location of all of the targets. Dataframe with location of centers and sizes of boxes 
    targetHoldTime: range of target hold times (in seconds). Set with two values
    dispenseTime: range of dispense hold times (in seconds). Set with two values
    interTrial: range of length between trials (in seconds). Set with two values

    target: location of current target; it's a class with associated color etc defined below
    cTargetHoldTime: current length of time to hold the target (in seconds)
    cDispenseTime: current range of dispense hold times (in seconds)
    cInterTrial: current range of length between trials (in seconds)

    gain: multiplier for the cursor -- tuple for the two cursors
    offset: offset for the cursor -- tuple for the two cursors

    cursorLocn: gain*force + offset  -- should we consider adding some filtering? maybe...
'''


targets = pandas.DataFrame(columns=['one','two','three'],index=['x','y','width','height'])
targetHoldTime = [.01 * ii for ii in range(25,75)]
dispenseTime = [.01 * ii for ii in range(5,15)]
interTrial = [.1 * ii for ii in range(15, 50)]

gain = (10)
offset = (-5)

graspType = [] # this will need to be filled out by the user -- figure out some good way to have a settings file


#initialize some screen stuff
size = [800,480] # size of the 7" pi screen
screen = pygame.display.set_mode(size)
BLACK = (0,0,0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
cursImage = [pygame.image.load('./textures/face.tga'), pygame.image.load('./textures/face.tga')]
cursRect = [jj.get_rect() for jj in cursImage]




#define target 
class target():
    def __init__(self,x,y,width,height):
        self.color = RED
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        
    def draw(self, screen):
        # pygame draws rectangular sprites from the top left corner, but we 
        # want to keep track of things by the center hence the offsets
        pygame.draw.rect(screen, self.color, (self.x + self.width/2, self.y + self.height/2, self.width, self.height))
        
    def isOver(self, cursRect):
        self.color = RED
        if self.contains(cursRect):
            self.color = GREEN
            return True
        # if (pos[0] > (self.x - self.width/2)) and ( pos[0] < (self.x+self.width/2)) :
        #     if (pos[1] > (self.y-self.height/2)) and (pos[1] < (self.y+self.height/2)):
        #         self.color = GREEN
        #         return True                            
        return False



# defining modules

def redrawWindow(): # redraws the window as black
    screen.fill(BLACK)
    mainTarget.draw(screen)



def get_cursor_locn(devices,cursors,gain=[1,1],offset=[-1,-1]):
    # take in the device information along with gains, and return the cursor locations
    cursors.CursorOne.X = (devices.DeviceOne.FSROne.value * .5 - devices.DeviceOne.FSRTwo.value * .5) * gain[0] - 1.5
    cursors.CursorOne.Y = (devices.DeviceOne.FSROne.value * .5 + devices.DeviceOne.FSRTwo.value * .5) * gain[0] + offset[0]
    cursors.CursorTwo.X = (devices.DeviceTwo.FSROne.value * .5 - devices.DeviceTwo.FSRTwo.value * .5) * gain[0] + 1.5
    cursors.CursorOne.Y = (devices.DeviceTwo.FSROne.value * .5 + devices.DeviceTwo.FSRTwo.value * .5) * gain[0] + offset[0]
    
    return cursors



def cursor_to_screen(X,Y): # converts the cursor XY coordinates to screen XY coordinates. 
    # screen is approx 6W x 3.25H, 480H x 800W pixels
    Y = (-480/3.25)*Y + 240 # flip the direction of incrementing for Y
    X = (800/6)*X + 400
    return [X, Y] # return the converted versions








# let's get ready to loop
cont = True
clock = pygame.time.Clock()
mouse = Controller()


while cont:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
 
    
     # get the current cursor location 
     cursors = get_cursor_locn(devices,cursors)
     [cursRect[0].centerx, cursRect[0].centery] = cursor_to_screen(cursors.CursorOne.X, cursors.CursorOne.Y)
     [cursRect[1].centerx, cursRect[1].centery] = cursor_to_screen(cursors.CursorOne.X, cursors.CursorOne.Y)
     for ii in cursRect:
         ii.
     
     
     
     
     
 #   clock.tick(60)
    redrawWindow()
 #   fakeCursorButton(button)
    pygame.display.flip
    
    
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
