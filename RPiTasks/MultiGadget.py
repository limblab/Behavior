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
import sys, os, pygame, random, gpiozero, csv
from datetime import datetime as dt
from time import sleep


""" ##########################################################################
### Define 'constants'
###########################################################################"""
# screen and color values
BLACK = (0,0,0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
SIZE = [800, 400]

# word codes -- the same as our XPC defined word codes, just to make life easy
WORD_START_TRIAL = 0x16 # generic trial start: 0x10; MG: 0x06
WORD_END_TRIAL = 0x20 
WORD_REWARD = 0x00 | WORD_END_TRIAL
WORD_ABORT = 0x01 | WORD_END_TRIAL
WORD_FAIL = 0x02 | WORD_END_TRIAL
WORD_INCOMPLETE = 0x03 | WORD_END_TRIAL

WORD_GO_CUE = 0x31
WORD_CATCH = 0x32


# state machine
STATE_START_TRIAL = 0
STATE_MOVEMENT = 1
STATE_REWARD = 2
STATE_BETWEEN_TRIALS = 3

state = STATE_BETWEEN_TRIALS




""" ##########################################################################
### Define all classes and submodules
###########################################################################"""

### define target 
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
        X = (800/6)*cursX + 400 # screen is 6 in wide, 800 pixels -- switch from inches to pixels
        Y = (-480/3.25)*cursY + 240 # screen is 3.25 in tall, 480 pixels -- inches to pixels and flip direction
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

### Define devices -- this is only for ADC devices that use FSRs for now
class device():
    # initialize
    def __init__(self,name,FSR0,FSR1,gain,offset,LED,imagePath):
        self.name = name # device name. Usually just power grasp etc
        self.FSR = [FSR0, FSR1] # these need to be two instances of MCP devices -- from the gpiozero library
        self.gain = gain # plan on this being an int for now
        self.offset = offset # plan on this being an int for now -- vertical gain from center. This should be negative
        self.LED = [LED] # allow for multiple LEDs
        self.cursImage = pygame.image.load(imagePath) # the image for our cursor
        self.cursRect = self.cursImage.get_rect() # the pygame rect object for our cursor
        self.cursRect.center = [0,offset]

    # update the cursor location and display
    def update_cursor(self,screen):
        cursX = (self.FSR[1].value - self.FSR[0].value) * self.gain
        cursY = (self.FSR[0].value + self.FSR[1].value) * self.gain + offset
        X = (800/6)*cursX + 400 # screen is 6 in wide, 800 pixels -- switch from inches to pixels
        Y = (-480/3.25)*cursY + 240 # screen is 3.25 in tall, 480 pixels -- inches to pixels and flip direction
        self.cursRect.center = [X,Y]
        screen.fill(BLACK)
        screen.blit(self.cursImage,self.cursRect)
        pygame.display.flip()
        
    def activate_device(self):
        for led in self.LED:
            led.on() # turn the LED on
        
    def deactivate_device(self):
        for led in self.LED:
            led.off()



### defining modules
# redraw the window
def blank_screen(screen): # redraws the window as black
    screen.fill(BLACK)
    pygame.display.flip()


### choose new device and target
def restart_task(devDict,tgtDict):
    # choose the device
    dev = devDict[random.choice(list(devices.keys()))]
    tgt = tgtDict[random.choice(list(targets.keys()))]

    return dev,tgt

### random delay generators -- so that it's a little cleaner in the main loop
class delayGenerator():
    def __init__(self,min,max):
        self.min = min
        self.max = max
        self.current = (random.random() * (max-min)) + min
        
    def reroll(self):
        self.current = (random.random() * (self.max-self.min)) + self.min


"""##############################################################################
### Device and button list initialization
##############################################################################"""
# set up gpiozero pins for the task and reward buttons -- gave up on the linear shift register
# button 0: button is gpio2, LED is gpio3. button 0 doesn't allow a PD resistor! whoops!
# button1: button is gpio14, LED is gpio15
# rewardButton 0: button is gpio18, LED is gpio17
# rewardButton 1: button is gpio23, LED is gpio22
taskButtons = {'ProximitySensor': 
               {'Button': gpiozero.Button(14),
                'LED': gpiozero.LED(15)}}

rewardButtons = {'Water':
                 {'Button': gpiozero.Button(18),
                  'LED': gpiozero.LED(17)}}
    

### Initialize the devices, put them in a dictionary together
# Just using the MCP3004 predefined device from gpiozero. Thanks gpiozero!
# devices.DeviceZero.FSROne = gpiozero.MCP3004(channel=0,device=0)
# devices.DeviceZero.FSRTwo = gpiozero.MCP3004(channel=1,device=0)
# devices.DeviceZero.LED = gpiozero.LED(16)
# devices.DeviceOne.FSROne = gpiozero.MCP3004(channel=2,device=0)
# devices.DeviceOne.FSRTwo = gpiozero.MCP3004(channel=3,device=0)
# devices.DeviceOne.LED = gpiozero.LED(12)

devDict = {'Powergrasp': device('Powergrasp',gpiozero.mcp3004(channel=0,device=0),
                                gpiozero.mcp3004(channel=0,device=1),
                                10,-2,gpiozero.LED(16),'./textures/face.tga')}


### initialize the targets with desired locations (in inches)
tgtDict = {1: target(0,1,4,.5),
           2: target(0,2,4,.5),
           3: target(0,2.5,4,.5)}


### initialize all of the wait times
targetHoldTime = delayGenerator(.25, .75) # how long do they have to be in the target?
dispenseTime = delayGenerator(.5, 1) # time to receive the reward
interTrialTime = delayGenerator(1.5, 5) # time between trials




'''###########################################################################
### Initialize pygame -- display, sounds etc
###########################################################################'''

### initialize some screen stuff
pygame.init()
screen = pygame.display.set_mode(size=SIZE,flags=(pygame.FULLSCREEN|pygame.NOFRAME))
blank_screen(screen)
pygame.event.clear()

### initialize the sound stuff
pygame.mixer.init(frequency=163840,buffer=32000) # mister owl, why are these sampling frequencies so weird?
goSound = pygame.mixer.Sound(os.path.join("tones","go3_interp.wav"))
rewardSound = pygame.mixer.Sound(os.path.join("tones","reward3_interp.wav"))




''' 
storage of the words and cursor locations
'''
wordFile = 'home/pi/Documents/taskOutput/' + dt.now().strftime('%Y%m%d_%H:%M:%S') + '_cage_word_file.csv'
wordWriter = csv.writer(open(wordFile))



# let's get ready to loop



while cont:
    for ev in pygame.event.get():
        if event.type == pygame.quit:
            sys.exit()
    
 
    
    if state = STATE_START_TRIAL: # if we're starting a new trial, mark it and let us know
        
        
        
    elif state = STATE_MOVEMENT
            
        # get the current cursor location 
        cursors = get_cursor_locn(devices,cursors)
        cursRect[0].center = cursor_to_screen(cursors.CursorOne.X, cursors.CursorOne.Y)
        cursRect[1].center = cursor_to_screen(cursors.CursorTwo.X, cursors.CursorTwo.Y)
        for ii in cursRect:
            ii.
     
    elif state = STATE_REWARD:
        
        rewardSound.play()
        
        
    elif state = STATE_BETWEEN_TRIALS:
        blank_screen(screen)
        sleep(interTrialTime.current)
        interTrialTime.reroll()
        targetHoldTime.reroll()
        dispenseTime.reroll()
        dev,tgt = restart_task(devDict,tgtDict)
        goSound.play()

