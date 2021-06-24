# -*- coding: utf-8 -*-
"""
Created on Thu Mar 11 14:27:25 2021

@author: benja
"""

"""
FSR calibration code for Ben. 
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
        width = self.width*(800/6) # width to pixels
        height = self.height*(480/3.25) # height to pixels
        X = (800/6)*self.x + 400 - width/2 # screen is 6 in wide, 800 pixels -- switch from inches to pixels
        Y = (-480/3.25)*self.y + 240 - height/2 # screen is 3.25 in tall, 480 pixels -- inches to pixels and flip direction
        self.rect = pygame.draw.rect(screen, self.color, (X, Y, width, height))
        
    def isOver(self, cursRect):
        self.color = RED
        if self.rect.contains(cursRect): # thanks pygame for handling this
            self.color = GREEN
            return True
                         
        return False

# ----------------------------------------------------------------------------

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
        self.activated = False # turn off the device whenever we're not using it

    # update the cursor location and display
    def update_cursor(self,screen):
        
        if self.activated:
            cursX = (self.FSR[1].value - self.FSR[0].value) * self.gain
            cursY = (self.FSR[0].value + self.FSR[1].value) * self.gain + self.offset
            X = (800/6)*cursX + 400 # screen is 6 in wide, 800 pixels -- switch from inches to pixels
            Y = (-480/3.25)*cursY + 240 # screen is 3.25 in tall, 480 pixels -- inches to pixels and flip direction
            self.cursRect.center = [(.1*X)+(.9*self.cursRect.center[0]),(.1*Y)+(.9*self.cursRect.center[1])]
            screen.blit(self.cursImage,self.cursRect)
            print(X,' ',Y)
            
        
    def activate_device(self):
        self.activated = True
        self.cursRect.center = [100,100]
        for led in self.LED:
            led.on() # turn the LED on
        
    def deactivate_device(self):
        self.activated = False
        self.cursRect.center = [100,100]
        for led in self.LED:
            led.off()




# ----------------------------------------------------------------------------
### random delay generators -- so that it's a little cleaner in the main loop
class delayGenerator():
    def __init__(self,min,max):
        self.min = min
        self.max = max
        self.current = (random.random() * (max-min)) + min
        
    def reroll(self):
        self.current = (random.random() * (self.max-self.min)) + self.min



''' ##########################################################################
### Defining submodules
###########################################################################'''
### redraw the window
def blank_screen(screen): # redraws the window as black
    screen.fill(BLACK)
    pygame.display.flip()


### choose new device and target
def restart_task(devDict,tgtDict):
    # choose the device
    dev = devDict[random.choice(list(devDict.keys()))]
    tgt = tgtDict[random.choice(list(tgtDict.keys()))]

    return dev,tgt

    

'''###########################################################################
### initializing the devices and targets
###########################################################################'''
### Devices 
# devices.DeviceZero.FSROne = gpiozero.MCP3004(channel=0,device=0)
# devices.DeviceZero.FSRTwo = gpiozero.MCP3004(channel=1,device=0)
# devices.DeviceZero.LED = gpiozero.LED(16)
# devices.DeviceOne.FSROne = gpiozero.MCP3004(channel=2,device=0)
# devices.DeviceOne.FSRTwo = gpiozero.MCP3004(channel=3,device=0)
# devices.DeviceOne.LED = gpiozero.LED(12)
devDict = {'Powergrasp': device('Powergrasp',gpiozero.MCP3004(channel=0,device=0),
                                gpiozero.MCP3004(channel=1,device=0),
                                1.1,-0.25,gpiozero.LED(16),'./textures/face.tga')}



### initialize the targets with desired locations (in inches)
tgtDict = {1: target(0, 1,   4,   0.5),
           2: target(0, 0.85,   4,   0.5),
           3: target(0, 0.75,   4,   0.5)}


### initialize all of the wait times
targetHoldTime = delayGenerator(.55, .75) # how long do they have to be in the target?
dispenseTime = delayGenerator(.25, 0.5) # time to receive the reward
interTrialTime = delayGenerator(2.5, 5) # time between trials


'''###########################################################################
### Initialize pygame -- display, sounds etc
###########################################################################'''

### initialize some screen stuff
pygame.init()
screen = pygame.display.set_mode(SIZE,(pygame.FULLSCREEN|pygame.NOFRAME))
blank_screen(screen)
pygame.mouse.set_visible(False)
pygame.event.clear()


font = pygame.font.SysFont(None, 25)
def message_to_screen(msg, color):
    screen_text = font.render(msg, True, color)
    gameDisplay.blit(screen_text, [800*2/3, 480*2/3])

### initialize the sound stuff
pygame.mixer.init(frequency=163840,buffer=32000) # mister owl, why are these sampling frequencies so weird?
goSound = pygame.mixer.Sound(os.path.join("tones","go3_interp.wav"))
rewardSound = pygame.mixer.Sound(os.path.join("tones","reward3_interp.wav"))




 
### storage of the words and cursor locations
'''
wordFile = 'home/pi/Documents/taskOutput/' + dt.now().strftime('%Y%m%d_%H:%M:%S') + '_cage_word_file.csv'
wordPID = open(wordFile,'w')
wordWriter = csv.writer(wordPID)
''' # we'll get this going later


# let's get ready to loop

while True:
    for ev in pygame.event.get():
        if ev.type == pygame.KEYDOWN:
            if ev.key == pygame.K_q:
                pygame.mouse.set_visible(True)
                pygame.display.quit()
                print('Closing task')
                sleep(1)
                sys.exit()
            if (ev.key == pygame.K_f) | (ev.key == pygame.K_F12):
                pygame.display.toggle_fullscreen()
 
    
    if state == STATE_MOVEMENT:
        screen.fill(BLACK) # clear the screen
        dev.update_cursor(screen) # draw cursor
        pygame.display.flip() # turn the display on
        message_to_screen('Value of FSR0 is '+str(dev.FSR[0].value)+', value of FSR1 is '+str(dev.FSR[1].value), WHITE) #tell me what the FSR values are

        
        
    elif state == STATE_BETWEEN_TRIALS:
        blank_screen(screen) # clear the screen
        sleep(interTrialTime.current) # wait for the intertrial time
        interTrialTime.reroll() # trial timing
        targetHoldTime.reroll()
        dispenseTime.reroll()
        dev,tgt = restart_task(devDict,tgtDict) # new devices and targets
        goSound.play()
        dev.activate_device()
        state = STATE_MOVEMENT
