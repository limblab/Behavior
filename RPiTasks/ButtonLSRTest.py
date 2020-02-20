
# -*- coding: utf-8 -*-
"""
Created on Fri Jan 31 11:13:18 2020

@author: kevin

Turning on and off each LED for on the button device. 
Testing to make sure that I'm using the LSR properly

These are all using the PCA9745 SPI linear shift register.
Refer
"""

import spidev, time, pygame, gpiozero

#initialize the ~reset pin for the LSR
resetLSR = gpiozero.DigitalOutputDevice("GPIO2",active_high=False,initial_value=False) # this sets GPIO2 to high

#initialize the spidev device for the button
spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 15600000 # LSR can handle up to 25MHz

#initialize the pymixer to play tones
pyMixer = pygame.mixer
pyMixer.init(frequency=163840,buffer=32000)
goSound = pyMixer.Sound(os.path.join("tones","go3_interp.wav"))


"""
notes for the spi comm:
 We're sending everything in two byte chunks because the pi isn't allowing me to change
 the number of bits sent per packet, even while running the script as SU. huh.
 
 


"""

while 1:
    for ii in range(0,2):
        
        MSB = ii<<1 # register value -- first 7 bits are the register value, then a read/write bit
        for jj in range(0,4):
            goSound.play()
            LSB = 1<<(2*jj) # == 0b00000001, 0b00000100, etc..
            print(hex((MSB<<8)+LSB))
            spi.xfer2([MSB,LSB]) # [MSB,LSB]
            time.sleep(2)
        
