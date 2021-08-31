/*
 * ***********************************************************************************
 * Copyright (c) 2020  M0KHZ - Kevin Wheatley
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or                                                                                                                                                                                                   
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * ***********************************************************************************
 * 
 * Libraries:
 *            Modified version of etherkit si5351.h to use the Teensy enhanced i2c_t3.h library from Teensy Forum memebr Brian (nox771).
 *            (this should be included with the distribution zip file, along with the accociated si5351.cpp file).
 *            
 *            Modified version of ILI9341_t3.h to use the Teensy enhanced i2c_t3.h library from Teensy Forum memebr Brian (nox771).
 *            (this should be included with the distribution zip file, along with the accociated ILI9341_t3.cpp & glcfont.c files).
 *            
 * **********************************************************************************************
 * 
 *  Included files:
 *    ILI9341.cpp             - Modified library for Teensy - DO NOT CHANGE - Just ignore, used when compliling
 *    ILI9341.h               - Modified library for Teensy - DO NOT CHANGE - Just ignore, used when compliling
 *    _fonts.c                - Font file - DO NOT CHANGE - Just ignore, used when compliling
 *    _fonts.h                - Font file - DO NOT CHANGE - Just ignore, used when compliling
 *    glcfont.c               - Font file - DO NOT CHANGE - Just ignore, used when compliling
 *    si5351.cpp              - Modified library for Teensy - DO NOT CHANGE - Just ignore, used when compliling
 *    si5351.h                - Modified library for Teensy - DO NOT CHANGE - Just ignore, used when compliling
 *    ---- include files that can be edited below ----
 *    Button_functions.h      - The button magic starts here - note switch bouncer is running in a seperate multi tasking thread
 *    encoder_functions.h     - The interrupt driven encoder magic starts here.
 *    display_co_ordinates.h  - Things to make the display look pretty :) and easier to manipulate. Edit to change colours etc.
 *    display_functions.h     - All the display routines.
 *    S_meter_functions.h     - All the S Meter stuff here.
 *    si5351_functions.h      - All the Si5351 stuff here.
 *    keyer.h                 - All the keyer stuff here.
 *    
 *    
 * ***********************************************************************************************
 * 
 * Hardware notes:
 *            - Teensy 3.2 module available from https://www.pjrc.com/store/teensy32.html 
 *            - I bought mine from eBay
 *                                               
 *            - tft module uses the ILI9341 driver there are different versions out there and the pinout changes,
 *            - the module currently being used includes a touch interface, this isn't being used at present.
 *            - I bought mine from eBay
 *                            
 * *********************************************************************************************
 *                            
 * Development environment:                           
 * 
 *            Teensyduino   version - 1.53  For instalation details see: https://www.pjrc.com/teensy/td_download.html           
 * 
 * *********************************************************************************************
 * 
 *  Version   - 0.1   - 15.01.2021 - Project start basic TFT, buttons and encoder structure                          
 *                                   - Pin assignments currently:
 *                                   - 0  - USB Comms / programming / debug 
 *                                   - 1  - UBS Comms / programming / debug 
 *                                   - 2  - VFO_SW
 *                                   - 3  - VFO_ENC_A
 *                                   - 4  - VFO_ENC_B
 *                                   - 5  - RIT_SW
 *                                   - 6  - RIT_ENC_A
 *                                   - 7  - RIT_ENC_B
 *                                   - 8  - VFO_STEP_UP
 *                                   - 9  - VFO_STEP_DN
 *                                   - 10 - Spare  
 *                                   - 11 - TFT_SDI/MOSI
 *                                   - 12 - TFT_SDO/MOSO
 *                                   - 13 - TFT_SCK
 *                                   - 14 - S_Meter
 *                                   - 15 - KEY_DOT
 *                                   - 16 - KEY_DASH
 *                                   - 17 - KEY_OUT
 *                                   - 18 - SDA0 - Si5351
 *                                   - 19 - SCL0 - Si5351
 *                                   - 20 - TFT_DC                            
 *                                   - 21 - TFT_CS                               
 *                                   - 22 - Spare
 *                                   - 23 - Spare
 *                                   - Other pins available check datasheet
 * Version    - 0.02  - 17.01.2021   - UI develpoment starts, basic interface defined.
 * Version    - 0.03  - 19.01.2021   - UI development continues
 *                                   - NEW Pin assignments:
 *                                   - 0  - MEM_1 
 *                                   - 1  - MEM_2 
 *                                   - 2  - MEM_3
 *                                   - 3  - VFO_SW
 *                                   - 4  - VFO_ENC_A
 *                                   - 5  - VFO_ENC_B
 *                                   - 6  - RIT_SW
 *                                   - 7  - RIT_ENC_A
 *                                   - 8  - RIT_ENC_B
 *                                   - 9  - VFO_STEP_UP
 *                                   - 10 - VFO_STEP_DN 
 *                                   - 11 - TFT_SDI/MOSI
 *                                   - 12 - TFT_SDO/MOSO
 *                                   - 13 - TFT_SCK
 *                                   - 14 - S_Meter
 *                                   - 15 - KEY_DOT
 *                                   - 16 - KEY_DASH
 *                                   - 17 - KEY_OUT
 *                                   - 18 - SDA0 - Si5351
 *                                   - 19 - SCL0 - Si5351
 *                                   - 20 - TFT_DC                            
 *                                   - 21 - TFT_CS                               
 *                                   - 22 - STATUS_LED
 *                                   - 23 - SIDE_TONE
 *                                   - Other pins available check datasheet
 * Version    - 0.04  - 20.01.2021   - UI development continues:                           
 *                                   - Added RIT encoder support
 * Version    - 0.05  - 21.01.2021   - UI development continues: 
 *                                   - Added Si5351 support
 * Version    - 0.06  - 22.01.2021   - UI development continues: 
 *                                   - Started to add Keyer support - NOTE In this version keyer is running in a seperate thread
 *                                   - NEW Pin assignments:
 *                                   - 0  - MEM_1 
 *                                   - 1  - MEM_2 
 *                                   - 2  - SPEED_TONE_CONTROL
 *                                   - 3  - VFO_SW
 *                                   - 4  - VFO_ENC_A
 *                                   - 5  - VFO_ENC_B
 *                                   - 6  - RIT_SW - toggles between VFO and Keyer help screens
 *                                   - 7  - RIT_ENC_A
 *                                   - 8  - RIT_ENC_B
 *                                   - 9  - VFO_STEP_UP
 *                                   - 10 - VFO_STEP_DN 
 *                                   - 11 - TFT_SDI/MOSI
 *                                   - 12 - TFT_SDO/MOSO
 *                                   - 13 - TFT_SCK
 *                                   - 14 - S_Meter
 *                                   - 15 - KEY_DOT
 *                                   - 16 - KEY_DASH
 *                                   - 17 - KEY_OUT
 *                                   - 18 - SDA0 - Si5351
 *                                   - 19 - SCL0 - Si5351
 *                                   - 20 - TFT_DC                            
 *                                   - 21 - TFT_CS                               
 *                                   - 22 - STATUS_LED
 *                                   - 23 - SIDE_TONE
 *                                   - A10 - SPARE
 *                                   - A11 - SPARE
 *                                   - Other pins available check datasheet
 * Version    - 0.07  - 22.01.2021   - Continued to add Keyer support : https://hoytech.com/articles/morse-code-keyer
 *                                   - NOTE In this version keyer is running in main loop
 * Version    - 0.08  - 24.01.2021   - Added Keyer help pages, access via RIT encoder switch, 
 *                                   - page navigation via RIT encoder.
 * Version    - 0.09  - 25.01.2021   - Added dynamic text for keyer mode & user ID                                  
 * Version    - 0.10  - 11.02.2021   - Added scalling to S meter input, user definable.
 * Version    - 0.11  - 24.03.2021   - Tx (clk0) is now enabled via key down. Rx now available on initial power on.
 * Version    - 0.12  - 26.03.2021   - Rx (clk2) now disabled during key down.
 *                                   - i.e. Full break-in or QSK operation.
 * Version    - 0.13  - 26.03.2021   - Corrected coding error in keyer.h - if (flag.vfo_B_active == true) si5351.set_freq((u.RIT_B_value * 100ULL), SI5351_CLK0); // was si5351.set_freq((u.RIT_A_value * 100ULL), SI5351_CLK0);
 *                                   
 *                            
 *                            
 *  Issues:
 *        
 *     -------------------------
 *     Seeing the occational display glitch, requiring and power cycle, at the moment I'm assuming it's a TFT SPI issue....
 *     So over clocking the Teensy has definately improved this issue, so >>>
 *          Tools-
 *                CPU Speed - 'set to- 96 Mhz (Overclock)
 *                
 *     This seems to increase the Display SPI refresh rate?
 *     -------------------------
 *     
 *     
*/

// ****************   User options    *******************************
#define MY_CALLSIGN "G5LOW"                // displayed on bottom text banner
#define BANNER "GQRP Club - SCD VFO"       // at the moment just on the startup display

// QRP Internationall Calling Frequencies:
// un-comment the band of interest
//unsigned int band = 1836000;
//unsigned int band =  3536000;
//unsigned int band =  5262000;
unsigned int band =  7030000;
//unsigned int band = 10116000;
//unsigned int band = 14060000;
//unsigned int band = 18086000;
//unsigned int band = 21060000;
//unsigned int band = 24906000;
//unsigned int band = 28060000;

unsigned int RIT_Tune_Rate  = 50;       // Hz
// number of 'clicks' above or below the Tx frequency now hard coded in encoder_functions.h - i.e. u.RIT_A=constrain(u.RIT_A,-40,40);
unsigned int RIT_Initial_Offset = 600;  // Hz

unsigned int Si_Correction = 31830;     // Set to specific Si5351 calibration number. See File -> Examples -> Etherkit Si5153 -> si5351_calibration
                                        // Allthough a modified version of the library is distributed with this code, to have access
                                        // to the examples you will need to install the Etherkit Si5351 library.

// ----- S Meter input scaling -----
// depending on your hardware you will want to change this value, the values below should give you a good starting place
// there is also some adjustment via the RV1 on the VFO PCB, uncomment to suit your hardware
                                       
//unsigned int S_meter_Scale = 350;         // full scale 13V8 input on IDC pin header pins 5 or 6
unsigned int S_meter_Scale = 300;         // full scale 9 Volts input on IDC pin header pins 5 or 6
//unsigned int S_meter_Scale = 250;         // full scale 6 Volts input on IDC pin header pins 5 or 6
//unsigned int S_meter_Scale = 200;         // full scale 4V6 Volts input on IDC pin header pins 5 or 6
//unsigned int S_meter_Scale = 150;         // full scale 3V3 Volts input on IDC pin header pins 5 or 6
//unsigned int S_meter_Scale = 100;         // full scale 2V2 Volts input on IDC pin header pins 5 or 6
//unsigned int S_meter_Scale = 50;          // full scale 1V1 Volts input on IDC pin header pins 5 or 6
                                     

// comment out if not required
//#define DEBUG

// ****************   End of User options    *******************************

char VERSION[6] = "0.13";

// used for S meter update timing
#include <Metro.h>
// Instantiate a metro object and set the interval to 250 milliseconds (0.25 seconds).
Metro metroSGragh = Metro(200); 

// add the libraries to support multitasking
#include <Arduino.h>
#include "TeensyThreads.h"

// add the libraries to support the display
#include "SPI.h"
#include "ILI9341_t3.h"

// tft display definitions
#define TFT_DC 20
#define TFT_CS 21
ILI9341_t3 tft = ILI9341_t3(TFT_CS, TFT_DC);

// to make the display look nice
#include "_fonts.h"

// Things to make the display look pretty :)
#include "display_co_ordinates.h"

// used for button debounce etc.
#include <Bounce.h>

// add the library for the interrupt handler timer
#include <TimerOne.h>

// Modified version of etherkit for Teensy, included in distrbution
#include "si5351.h"
#include <i2c_t3.h>

// Instantiate a si5351 object
Si5351 si5351;
#include "si5351_functions.h"

// Encoder functions
#include "encoder_functions.h"

// EEPROM required for Keyer memories
#include <EEPROM.h>

// Button assignments:
#define VFO_SW                 3  // Switch between VFO's
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_SW = Bounce(VFO_SW, 50);   // Toggles VFO

#define RIT_SW                  6  // Switch between RIT and Keyer speed select
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_RIT_SW = Bounce(RIT_SW, 50);   // Toggles RIT and Keyer speed select

#define VFO_STEP_UP             9  // Increases VFO Tuning rate
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_STEP_UP = Bounce(VFO_STEP_UP, 50);   // VFO Tuning rate +

#define VFO_STEP_DN             10  // Decreases VFO Tuning rate
// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce bouncer_VFO_STEP_DN = Bounce(VFO_STEP_DN, 50);   // VFO Tuning rate -

// Button functions
#include "Button_functions.h"

// Keyer implementation
#include "keyer.h"

// S meter functions
#include "S_meter_functions.h"

// Display drawing / refresh functions
#include "display_functions.h"



void setup() {
  // put your setup code here, to run once:
  // init display
  tft.begin();
  tft.setRotation(3); // will need to change this to 1 for panel mounting in case
  tft.fillScreen(ILI9341_BLACK);
  delay(50);
  // display welcome message
  splashscreen();             // in display_functions.h
  

  // small delay before clearing screen
  delay(4000); // increasing above this value causes problems - need to understand this?
  // now clear the display
  tft.fillScreen(ILI9341_BLACK);
  delay(50);

// just incase we need some diagnostics
  Serial.begin(9600);
  // and comms to gps module

  #ifdef DEBUG
      Serial.print("Version Number: ");
      Serial.println(VERSION);
  #endif //DEBUG   

// Setup buttons
  pinMode(VFO_SW, INPUT_PULLUP);
  pinMode(RIT_SW, INPUT_PULLUP);
  pinMode(VFO_STEP_UP, INPUT_PULLUP);
  pinMode(VFO_STEP_DN, INPUT_PULLUP);
  pinMode(pinMem1, INPUT_PULLUP);
  pinMode(pinMem2, INPUT_PULLUP);
  pinMode(pinSpeedToneControl, INPUT_PULLUP);
  pinMode(pinKeyDit, INPUT_PULLUP);
  pinMode(pinKeyDah, INPUT_PULLUP);
  
  pinMode(pinStatusLed, OUTPUT);
  pinMode(pinMosfet, OUTPUT);
  pinMode(pinSpeaker, OUTPUT);

  // Setup encoder pins with internal pullups enabled.
  pinMode (encoder_VFO_PinA,INPUT_PULLUP);
  pinMode (encoder_VFO_PinB,INPUT_PULLUP);
  
  pinMode (encoder_RIT_PinA,INPUT_PULLUP);
  pinMode (encoder_RIT_PinB,INPUT_PULLUP);


  // Multitasking thread initialisation below
  threads.addThread(switch_bouncer);

  // Initialise I2C Communications
  Wire.begin();

  // So for this sort of project, i.e. where the user will expect instant response to a change on the frequency or RIT encoders,
  // we have chosen to make the encoder routine interrupt driven, so if the interrupt is triggered
  // irrespective of where the main loop is, the interrupt 'handler' is actioned.
  //
  // Two methods are available below, select the one most suitable for your type of encoder, 
  // note some cheap encoders tend to double count, choosing the right interrupt routine below should help.

  // Setup interrupt handling for the encoder half- or full-step
  attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinA), VFO_RotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinA), VFO_RotEncHalfStep, CHANGE);

  attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinB), VFO_RotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinB), VFO_RotEncHalfStep, CHANGE);
  
  attachInterrupt(digitalPinToInterrupt(encoder_RIT_PinA), RIT_RotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinA), RIT_RotEncHalfStep, CHANGE);

  attachInterrupt(digitalPinToInterrupt(encoder_RIT_PinB), RIT_RotEncFullStep, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(encoder_VFO_PinB), RIT_RotEncHalfStep, CHANGE);

  // now setup Si5351 module
  initialise_dds();

  //Load default start frequency
  u.vfo_A_value = u.vfo_default;
  u.vfo_B_value = u.vfo_default;
      
  u.RIT_A_value = u.vfo_A_value + u.RIT_Offset;
  u.RIT_B_value = u.vfo_B_value + u.RIT_Offset;


  loadStorage();

  playSym(symDit, 0);
  playSym(symDah, 0);
  playSym(symDit, 0);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

    // redraw display only if "flag.ReDraw_Screen==true" - this stop screen flicker and only changes the display when requested.
    if(flag.ReDraw_Screen==true)
    {
      display_main_screen(); 
      // OK we've drawn the display or redrawn if we requeted it
      
      // draw S meter background
      //Serial.println("I'm here");
      meter();
    }
    
     if(flag.freq_Changed==true)
    {
      // call function to update the VFO
      display_update_vfo();
      // force an update of RIT frequency to keep syncronised
      flag.RIT_Changed=true;
 
      // call function to update the Si5351 output
      update_si5351();
      flag.freq_Changed=false;
    }

    if(flag.RIT_Changed==true)
    {
        display_update_rit();
        // call function to update the Si5351 output
        update_si5351();
        flag.RIT_Changed=false;
    }
    
    //display_update_vfo();
    // update S meter this runs on each loop through of code
    if(flag.keyer_help==false){
        SmeterBarGragh();
    }

    // temp position for this function
    if(flag.freq_multi_bar == true){
      Freq_Multi_Bar ();
      flag.freq_multi_bar = false;
    }

    if(flag.keyer_help==true){
      if(flag.keyer_page_reDraw==true){
          // clear screen and display help pages
          tft.fillScreen(ILI9341_BLACK);
          // draw boarder around full display
          rectangle(outline_boarder_x, outline_boarder_y, outline_boarder_w, outline_boarder_d, outline_boarder_colour);
          // now display help page associated with current u.keyer_help_index
          display_help_pages();
          flag.keyer_page_reDraw=false;
      }    
    }

  if(flag.keyer_mode_changed==true){
    if(currKeyerMode==0){
        tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
        tft.setCursor(info_cursor_pos_x  ,info_cursor_pos_y + 10); 
        tft.setTextColor(info_text_colour);    
        tft.setFont(DroidSansMono_12);
        tft.print("Mode: Iambic    - ");
        tft.print(MY_CALLSIGN);
    }
  if(currKeyerMode==2){
        tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
        tft.setCursor(info_cursor_pos_x  ,info_cursor_pos_y + 10); 
        tft.setTextColor(info_text_colour);    
        tft.setFont(DroidSansMono_12);
        tft.print("Mode: Straight   - ");
        tft.print(MY_CALLSIGN);
    }
    flag.keyer_mode_changed=false;
  }
  
// -----Keyer code --------

      int ditPressed = (digitalRead(pinKeyDit) == LOW);
      int dahPressed = (digitalRead(pinKeyDah) == LOW);
    
      if (currState == stateIdle) {
        if (currKeyerMode == keyerModeIambic && ditPressed && dahPressed) {
          if (prevSymbol == symDah) playSym(symDit, 1);
          else playSym(symDah, 1);
        } else if (dahPressed && currKeyerMode != keyerModeStraight) {
          if (currKeyerMode == keyerModeIambic) {
            playSym(symDah, 1);
          } else if (currKeyerMode == keyerModeVibroplex) {
            playStraightKey(pinKeyDah);
          }
        } else if (ditPressed) {  
          if (currKeyerMode == keyerModeStraight) playStraightKey(pinKeyDit);
          else playSym(symDit, 1);
        } else {
          prevSymbol = 0;
        }
    
        if (digitalRead(pinSpeedToneControl) == LOW) {
          unsigned long whenStartedPress = millis();
          int nextState = stateSettingSpeed;
          //Serial.println("I'm here");
          delay(5);
            
          while (digitalRead(pinSpeedToneControl) == LOW) {
            if (millis() > whenStartedPress + 1000) {
              digitalWrite(pinStatusLed, HIGH);
              nextState = stateSettingTone;
            }
            
            if (digitalRead(pinMem1) == LOW) {
              playSym(symDit, 0);
              playSym(symDit, 0);
              currKeyerMode = keyerModeIambic;
              saveStorageEmptyPacket(packetTypeKeyerModeIambic);
              waitPin(pinSpeedToneControl, HIGH);
              nextState = stateIdle;
              break;
            }
    
            if ((PINMEM2_INVERTED && digitalRead(pinMem2) == HIGH) || (!PINMEM2_INVERTED && digitalRead(pinMem2) == LOW)) {
              playSym(symDit, 0);
              playSym(symDit, 0);
              playSym(symDit, 0);
              currKeyerMode = keyerModeStraight;
              saveStorageEmptyPacket(packetTypeKeyerModeStraight);
              waitPin(pinSpeedToneControl, HIGH);
              nextState = stateIdle;
              break;
            }
            flag.keyer_mode_changed=true;
          }
    
          digitalWrite(pinStatusLed, LOW);
          currState = nextState;
            
          delay(50);
        }
    
        checkMemoryPin(0, pinMem1, 0);
        checkMemoryPin(1, pinMem2, PINMEM2_INVERTED);
        //checkMemoryPin(2, pinMem3, 0);

        
      } else if (currState == stateSettingSpeed) {
        if (playSymInterruptable(symDit, 0, pinSpeedToneControl, LOW) != -1) {
          currState = stateIdle;
          waitPin(pinSpeedToneControl, HIGH);
          return;
        }
        if (ditPressed) ditMillis = scaleDown(ditMillis, 1/1.05, 20);
        if (dahPressed) ditMillis = scaleUp(ditMillis, 1.05, 800);
        saveStorageInt(packetTypeSpeed, ditMillis);
      } else if (currState == stateSettingTone) {
        if (playSymInterruptable(symDit, 0, pinSpeedToneControl, LOW) != -1) {
          currState = stateIdle;
          waitPin(pinSpeedToneControl, HIGH);
          return;
        }
        if (ditPressed) toneFreq = scaleDown(toneFreq, 1/1.1, 30);
        if (dahPressed) toneFreq = scaleUp(toneFreq, 1.1, 12500);
        saveStorageInt(packetTypeFreq, toneFreq);
      }
   // ---- end of Keyer code -------
   

  
}
// ------------- End of Main Loop ---------------------------------
// ------------- End of file --------------------------------------
