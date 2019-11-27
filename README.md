# PCA9533
Arduino library for the PCA9533 4 port LED dimmer


# Added on 20/11/2019
 - Added the getReg method to read register
 - Added getAllReg method to read all register using AutoIncrement flag functionnality of the chip (can't start from INPUT reg, have to start from another register) <= STILL NEED THE PUBLIC METHOD
 - Rewrite getINPUTS method to get GPIO values (split the method in a public/private methods with using byte shifting and mask instead of switch/case)
 - Changed setMODE to read current register status before apply new port mode (instead of use port_setting which is hard coded at init stage)
 - Renamed some variables to make it more readable
  
  
# Added on 09/09/2019
- Method to read the input register

Test file (main.ino) is testing different prescaler frequencies :
 - PSC0 is 152Hz
 - PSC1 is 5Hz
 
LED1 is using PSC1 and blinking at 5Hz
LED2 is using PSC0 and dimming from 0% to 100%
LED3 is using PSC0 and dimming from 100% to 0%
LED4 is used as GPIO

All logs are sent through serial.


Datasheet:
https://www.nxp.com/docs/en/data-sheet/PCA9533.pdf
