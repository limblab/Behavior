#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
mcp3004_test.py

Making sure that my communication and the board are all working correctly


Created on Wed Feb 26 14:14:44 2020

@author: kevin
"""

import spidev, gpiozero, time

mcp0 = gpiozero.mcp3004(channel=0,differential=False,max_voltage=5,device=0)
mcp1 = gpiozero.mcp3004(channel=1,differential=False,max_voltage=5,device=0)
mcp2 = gpiozero.mcp3004(channel=2,differential=False,max_voltage=5,device=0)
mcp3 = gpiozero.mcp3004(channel=3,differential=False,max_voltage=5,device=0)

while True:
    print([mcp0.value(), mcp1.value(), mcp2.value(), mcp3.value()])
    time.sleep(.1)