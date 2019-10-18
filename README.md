# PCA9533
Arduino library for the PCA9533 4 port LED dimmer

# Added on 09/09/2019
Function to read the input register

Test file (main.cpp) is testing different prescaler frequencies :
 - PSC0 is 152Hz
 - PSC1 is 5Hz
 
LED1 is using PSC1 and blinking at 5Hz
LED2 is using PSC0 and dimming from 0% to 100%
LED3 is using PSC0 and dimming from 100% to 0%
LED4 is used as GPIO

All logs are sent through serial.


Datasheet:
https://www.nxp.com/docs/en/data-sheet/PCA9533.pdf
