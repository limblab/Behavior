#!/bin/bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libatlas-base-dev
sudo apt-get install vim

sudo pip3 install numpy pandas gpiozero pygame pynput spidev
sudo apt-get install cowsay


sudo cat ./cageHDMIscreen.txt >> /boot/config.txt
