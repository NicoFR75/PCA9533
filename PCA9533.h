/*
  PCA9533 - Library for esp8266
  Copyright (c) 2017 Max Schmid. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Edited by NicoFR75 (November 2019):
  - Added getReg method to read register
  - Added getAllReg method to read all register using AutoIncrement flag functionnality of the chip (can't start from INPUT reg, have to start from another register)
  - Added getINPUTS method to get GPIO values
  - Changed setMODE to read current register status before apply new port mode (instead of use port_setting which is hard coded at init stage)
  - Renamed some variables to make it more readable
  
*/

#if 1
__asm volatile ("nop");
#endif

#ifndef PCA9533_h
#define PCA9533_h
//#endif

//#if !defined(ARDUINO_ARCH_AVR)
//#error “The PCA9533 library only supports AVR processors.”
//#endif

#include <Arduino.h>
#include "Wire.h"

namespace Pca9533 {
    const byte DEV_ADDR         = 0x62;
    const byte COM_SUCCESS      = 0x00;

    typedef enum:byte {
        REG_INPUT   = 0x00,     // Default :: INPUT REGISTER
        REG_PSC0    = 0x01,     // FREQUENCY PRESCALER 0
        REG_PWM0    = 0x02,     // PWM REGISTER 0
        REG_PSC1    = 0x03,     // FREQUENCY PRESCALER 1
        REG_PWM1    = 0x04,     // PWM REGISTER 1
        REG_LED     = 0x05,     // LED SELECTOR
        REG_AUTO    = 0x11      // FOR READING ALL RESGITER, STARTING FROM PSC0
    } reg_ptr_t;

    typedef enum:byte {
        LED_MODE_OFF  = 0,  // 00 - Output is set Hi-Z (LED off – default)
        LED_MODE_ON   = 1,  // 01 - Output is set LOW (LED on)
        LED_MODE_PWM0 = 2,  // 10 - Output blinks at PWM0 rate
        LED_MODE_PWM1 = 3   // 11 - Output blinks at PWM1 rate
    } led_out_mode_t;

    typedef enum:byte {
        IO0 = 0,
        IO1 = 2,
        IO2 = 4,
        IO3 = 6
    } pin_t;

    typedef enum:byte {
        IO_LOW  = 0,
        IO_HIGH = 1
    } state_t;

    typedef enum:byte {
        IO_PWM0  = 0x12,
        IO_PWM1  = 0x14
    } pwm_t;

   
    
    class PCA9533 {
         public:
            PCA9533();
            ~PCA9533();
            byte port_init = 0x00;
            byte ping();
            bool init();
            void setMODE(pin_t pin, led_out_mode_t newMode);
            void setPWM(reg_ptr_t pwmPort, int pwmValue);
            void setPSC(reg_ptr_t pscPort, int pscValue);
            state_t getINPUT(pin_t pin);
            
         private:
            byte _comBuffer;
            void initCall(reg_ptr_t regPtr);
            void setReg(reg_ptr_t ptr, byte newSetting);  
            byte getReg(reg_ptr_t regPtr);
            void getAllReg(byte (&reg)[6]);
            void endCall();     
    };
}

using namespace Pca9533;

#endif
