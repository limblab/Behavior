
# -*- coding: utf-8 -*-
"""
Created on Fri Jan 31 11:13:18 2020

@author: kevin

Turning on and off each LED for on the button device. 
Testing to make sure that I'm using the LSR properly

These are all using the PCA9745 SPI linear shift register.
Refer
"""

import spidev, time, pygame, os

spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz = 15600000 # LSR can handle up to 25MHz

pyMixer = pygame.mixer
pyMixer.init(frequency=163840,buffer=32000)
goSound = pyMixer.Sound(os.path.join("tones","go3_interp.wav"))


while 1:
    # have to figure out a cleaner way to do this
    for ii in range(0,2):
        MSB = ii+2 # register value 
        for jj in range(0,4):
            LSB = 2**(2*jj) # == 0b00000001, 0b00000100, etc..
            print(hex((MSB<<8)+LSB))
            spi.xfer([MSB,LSB]) # [MSB,LSB]
            #spi.xfer([0x02,0x01])
            time.sleep(2)
            goSound.play()
        
