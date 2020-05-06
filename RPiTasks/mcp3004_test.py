#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
mcp3004_test.py

Making sure that my communication and the board are all working correctly


Created on Wed Feb 26 14:14:44 2020

@author: kevin
"""

import gpiozero, time
from matplotlib import pyplot as plt


plt.ion()


mcp0 = gpiozero.MCP3004(channel=0,differential=False,device=0)
mcp1 = gpiozero.MCP3004(channel=1,differential=False,device=0)
mcp2 = gpiozero.MCP3004(channel=2,differential=False,device=0)
mcp3 = gpiozero.MCP3004(channel=3,differential=False,device=0)


time.sleep(.5)


fig,ax = plt.subplots()
mcp0Val = list()
mcp1Val = list()
mcp2Val = list()
mcp3Val = list()

ii = 0


ln0, = ax.plot([], [], label='mcp0')
ln1, = ax.plot([], [], label='mcp1')
ln2, = ax.plot([], [], label='mcp2')
ln3, = ax.plot([], [], label='mcp3')
ax.legend()
ax.set_ylim(-0,1, 1.1)
ax.set_xlim(-5, 105)
ax.set_ylabel('Voltage (V)')
ax.set_xticks([])




while True:
    
    mcp0Val.append(mcp0.value)
    mcp1Val.append(mcp1.value)
    mcp2Val.append(mcp2.value)
    mcp3Val.append(mcp3.value)

    if ii > 100:
        ii = 100
        mcp0Val.pop(0)
        mcp1Val.pop(0)
        mcp2Val.pop(0)
        mcp3Val.pop(0)
        
    
    print(mcp0Val[ii],mcp1Val[ii],mcp2Val[ii],mcp3Val[ii],sep='\t',end='\n')

    

    # ax.plot(list(range(ii+1)),mcp0Val,label='mcp0')
    # ax.legend()
    ln0.set_data(list(range(ii+1)),[jj * 3.3 for jj in mcp0Val])
    ln1.set_data(list(range(ii+1)),[jj * 3.3 for jj in mcp1Val])
    ln2.set_data(list(range(ii+1)),[jj * 3.3 for jj in mcp2Val])
    ln3.set_data(list(range(ii+1)),[jj * 3.3 for jj in mcp3Val])




    fig.canvas.draw()
    fig.canvas.flush_events()

    ii += 1
    
    time.sleep(.05)
