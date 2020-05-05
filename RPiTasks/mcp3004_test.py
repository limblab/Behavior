#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
mcp3004_test.py

Making sure that my communication and the board are all working correctly


Created on Wed Feb 26 14:14:44 2020

@author: kevin
"""

import spidev, gpiozero, time
import matplotlib as plt
import pandas as pd

mcp0 = gpiozero.mcp3004(channel=0,differential=False,max_voltage=5,device=0)
mcp1 = gpiozero.mcp3004(channel=1,differential=False,max_voltage=5,device=0)
mcp2 = gpiozero.mcp3004(channel=2,differential=False,max_voltage=5,device=0)
mcp3 = gpiozero.mcp3004(channel=3,differential=False,max_voltage=5,device=0)

fig,ax = plt.subplots()
mcp0Val = list()
mcp1Val = list()
mcp2Val = list()
mcp3Val = list()

ii = 0

while True:
    ii = ii + 1
    
    mcp0Val = mcp0Val.append(mcp0.value())
    mcp1Val = mcp1Val.append(mcp1.value())
    mcp2Val = mcp2Val.append(mcp2.value())
    mcp3Val = mcp3Val.append(mcp3.value())

    if ii > 100:
        mcp0Val.pop(0)
        mcp1Val.pop(0)
        mcp2Val.pop(0)
        mcp3Val.pop(0)
        
        
    ax.plot([mcp0Val,mcp1Val,mcp2Val,mcp3Val],list(range(ii)),label=['mcp0','mcp1','mcp2','mcp3'])
    ax.legend()
    
    
    
    time.sleep(.1)