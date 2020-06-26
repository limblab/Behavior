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
import time, sys, os, pygame, random, spidev, gpiozero, pandas, csv
from datetime import datetime as dt
from math import sin, pi, cos
# from pynput.mouse import Controller


# set up gpiozero pins for the task and reward buttons -- gave up on the linear shift register
taskButtons = [gpiozero.Button(2), gpiozero.Button(14)]  # Button0: GPIO2; Button1: GPIO14
taskLEDs = [gpiozero.LED(3), gpiozero.LED(15)] # Button0LED: GPIO3; Button1LED: GPIO15
rewardButtons = [gpiozero.Button(18), gpiozero.Button(23)] # Reward0Button: GPIO18; Reward1Button: GPIO23
rewardLEDs = [gpiozero.LED(17), gpiozero.LED(22)] # Reward0LED: GPIO17; Reward1LED: GPIO22



''' Prep everything for the ADC -- MCP3004
Just using the MCP3004 predefined device from gpiozero. Thanks gpiozero!
'''
devices = pandas.DataFrame(columns=['DeviceZero','DeviceOne'],index=['FSROne','FSRTwo','LED'])
devices.DeviceZero.FSROne = gpiozero.MCP3004(channel=0,device=0)
devices.DeviceZero.FSRTwo = gpiozero.MCP3004(channel=1,device=0)
devices.DeviceZero.LED = gpiozero.LED(16)
devices.DeviceOne.FSROne = gpiozero.MCP3004(channel=2,device=0)
devices.DeviceOne.FSRTwo = gpiozero.MCP3004(channel=3,device=0)
devices.DeviceOne.LED = gpiozero.LED(12)


#cursors = pandas.DataFrame(columns=['CursorOne','CursorTwo'],index=['X','Y'])


'''
State variables

states:
    STATE_START_TRIAL
    STATE_MOVEMENT
    STATE_REWARD
    STATE_BETWEEN_TRIALS

'''

STATE_START_TRIAL = 0
STATE_MOVEMENT = 1
STATE_REWARD = 2
STATE_BETWEEN_TRIALS = 3

state = STATE_BETWEEN_TRIALS

''' 
Word codes

These are the same words that we have defined in all of the xpc stuff. This way
we can just use all of the previous code on the analysis side.
'''
WORD_START_TRIAL = 0x16 # generic trial start: 0x10; MG: 0x06
WORD_END_TRIAL = 0x20 
WORD_REWARD = 0x00 | WORD_END_TRIAL
WORD_ABORT = 0x01 | WORD_END_TRIAL
WORD_FAIL = 0x02 | WORD_END_TRIAL
WORD_INCOMPLETE = 0x03 | WORD_END_TRIAL

WORD_GO_CUE = 0x31
WORD_CATCH = 0x32



''' 
storage of the words and cursor locations
'''
wordFile = 'home/pi/Documents/taskOutput/' + dt.now().strftime('%Y%m%d_%H:%M:%S') + '_cage_word_file.csv'
wordWriter = csv.writer(open(wordFile))


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



def get_cursor_locn(devices,gain=[1,1],offset=[-1,-1]):
    cursors = pandas.DataFrame(columns=['CursorOne','CursorTwo'],index=['X','Y'])
    
    
    # take in the device information along with gains, and return the cursor locations (in inch coordinates)
    cursors.CursorOne.X = (devices.DeviceZero.FSROne.value * .5 - devices.DeviceZero.FSRTwo.value * .5) * gain[0] - 1.5
    cursors.CursorOne.Y = (devices.DeviceZero.FSROne.value * .5 + devices.DeviceZero.FSRTwo.value * .5) * gain[0] + offset[0]
    cursors.CursorTwo.X = (devices.DeviceOne.FSROne.value * .5 - devices.DeviceOne.FSRTwo.value * .5) * gain[0] + 1.5
    cursors.CursorTwo.Y = (devices.DeviceOne.FSROne.value * .5 + devices.DeviceOne.FSRTwo.value * .5) * gain[0] + offset[0]
    
    return cursors



def cursor_to_screen(X,Y): # converts the cursor XY coordinates to screen XY coordinates. 
    # screen is approx 6W x 3.25H, 480H x 800W pixels
    Y = (-480/3.25)*Y + 240 # flip the direction of incrementing for Y
    X = (800/6)*X + 400
    return [X, Y] # return the converted versions








# let's get ready to loop
cont = True
clock = pygame.time.Clock()
# mouse = Controller()


tInit = time.perf_counter_ns()
tCurrState = time.perf_couter_ns()
while cont:
    pygame.event.get() # clears the pygame queue to prevent queue buildup
 
    
    if state = STATE_START_TRIAL: # if we're starting a new trial, mark it and let us know
        iTarget = random.randint(0,len(targets.columns)-1)
        tgt = target(targets.iloc[0,iTarget],targets.iloc[1,iTarget],targets.iloc[2,iTarget],targets.iloc[3,iTarget])
        iDevice = random.randint(0,len(devices.columns)-1)
        cDevice = 
        wordWriter.writerow([time.perf_counter_ns-tInit,WORD_START_TRIAL]
        state = STATE_MOVEMENT
        tCurrState = time.perf_couter_ns()
        
    elif state = STATE_MOVEMENT
            
        # get the current cursor location 
        cursors = get_cursor_locn(devices,cursors)
        cursRect[0].center = cursor_to_screen(cursors.CursorOne.X, cursors.CursorOne.Y)
        cursRect[1].center = cursor_to_screen(cursors.CursorTwo.X, cursors.CursorTwo.Y)
        for ii in cursRect:
            ii.
     
     
     
     
     
 #   clock.tick(60)
    redrawWindow()
 #   fakeCursorButton(button)
    pygame.display.flip
    
    
    # for event in pygame.event.get():
    #     cursorLocn = pygame.mouse.get_pos()
    #     if event.type == pygame.MOUSEBUTTONDOWN:
    #         cont = False
    #     if event.type == pygame.QUIT:
    #         cont = False
            
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
