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
*/


 // Colours to choose from:
 // ILI9341_BLACK       
 // LI9341_NAVY        
 // ILI9341_DARKGREEN    
 // ILI9341_DARKCYAN     
 // ILI9341_MAROON      
 // ILI9341_PURPLE      
 // ILI9341_OLIVE       
 // ILI9341_LIGHTGREY   
 // ILI9341_DARKGREY   
 // ILI9341_BLUE       
 // ILI9341_GREEN        
 // ILI9341_CYAN       
 // ILI9341_RED         
 // ILI9341_MAGENTA    
 // ILI9341_YELLOW      
 // ILI9341_WHITE      
 // ILI9341_ORANGE      
 // ILI9341_GREENYELLOW 
 // ILI9341_PINK       

// ---------------------------------------------------
// Structure to make handling program control 'flags' easier to work with
struct flags
{
  bool ReDraw_Screen      = true;      // this will force the screen to be updated on first loop
  bool freq_Changed       = true;      // set within the encoder interrupt routine.
  bool vfo_A_active       = true;      // No real reason to add a comment here as the variable name says it all!
  bool vfo_B_active       = false;     // No real reason to add a comment here as the variable name says it all!
  bool vfo_A_B_changed    = false;     // used when VFO changed
  bool RIT_Changed        = true;      // set within the encoder interrupt routine
  bool Smeter             = false;     // used to update S meter
  bool SmeterBarGragh     = false;     // used to update the SmeterBarGragh
  bool GraphUpdate        = false;     // used to update S meter Graph
  bool freq_multi_bar     = true;      // used to indicated VFO Tuning rate on display
  bool keyer_help         = false;     // used to toggle between VFO & Keyer help screens
  bool keyer_page_reDraw  = false;   //
  bool keyer_mode_changed = true;   // used to redraw keyer mode : Iambic or Straight
};
struct flags flag;
// ---------------------------------------------------

struct userparameters
{
  unsigned int vfo_default            = band;               // default start frequency - defined in user defines SCD_2021_Vx.xx.INO
  unsigned int tune_multi             = 2;                  // Frequency multiplier reference
  long vfo_A_value                    = 0;                  // variable to store current VFO_A frequency value
  long vfo_B_value                    = 0;                  // variable to store current VFO_B frequency value
  long RIT_A_value                    = 0;                  // variable to store current RIT_A frequency value
  long RIT_B_value                    = 0;                  // variable to store current RIT_B frequency value
  unsigned int RIT_TR                 = RIT_Tune_Rate;      // In Hz defined in user defines SCD_2021_Vx.xx.INO
  unsigned int RIT_Offset             = RIT_Initial_Offset; // In Hz defined in user defines SCD_2021_Vx.xx.INO
  signed int RIT_A                    = 0;                  // Number of 'clicks' +/- from initial 0 position
  signed int RIT_B                    = 0;                  // Number of 'clicks' +/- from initial 0 position
  signed int keyer_help_index         = 0;                  // used to scroll through Keyer help pages
};
struct userparameters u;


// variables for screen layout
// outline boarder
int outline_boarder_x = 0;        // position for top left  
int outline_boarder_y = 0;        // position for top left 
int outline_boarder_w = 320;      // width of boarder
int outline_boarder_d = 240;      // depth of boarder
int outline_boarder_colour = ILI9341_YELLOW;

//when we clear the display to re-write anything we don't want to re-draw the outline boarder
// so these variables define the are we'll call upon in the code, when required.
int clearscreen_x = 5;
int clearscreen_y = 5;             // position for top left 
int clearscreen_w = 315;           // width of boarder
int clearscreen_d = 215;           // depth of boarder
int clearscreen_colour = ILI9341_BLACK;

int vanity_boarder_x = 5;           // position for top left 
int vanity_boarder_y = 5;           // position for top left
int vanity_boarder_w = 310;         // width of boarder
int vanity_boarder_d = 38;          // depth of boarder
int vanity_boarder_colour = ILI9341_GREEN;

int vanity_cursor_pos_x = 40;       // position for top left
int vanity_cursor_pos_y = 13;       // position for top left
int vanity_text_colour = ILI9341_WHITE;
// ------------------------------------

int VFO_A_freq_boarder_x = 5;        // position for top left 
int VFO_A_freq_boarder_y = 55;       // position for top left
int VFO_A_freq_boarder_w = 310;      // width of boarder
int VFO_A_freq_boarder_d = 70;       // depth of boarder
int VFO_A_freq_boarder_colour = ILI9341_GREEN;

int VFO_A_freq_cursor_pos_x = 60;    // position for top left
int VFO_A_freq_cursor_pos_y = 62;    // position for top left

int RIT_A_freq_cursor_pos_x = 125;    // position for top left
int RIT_A_freq_cursor_pos_y = 98;    // position for top left
int RIT_A_freq_text_colour = ILI9341_WHITE;

int VFO_A_freq_text_colour = ILI9341_MAGENTA;
int VFO_A_mhz_cursor_pos_x = 185;    // position for top left
int VFO_A_mhz_cursor_pos_y = 60;     // position for top left


// -------------------------------------

int VFO_B_freq_boarder_x = 5;         // position for top left 
int VFO_B_freq_boarder_y = 129;       // position for top left
int VFO_B_freq_boarder_w = 310;       // width of boarder
int VFO_B_freq_boarder_d = 69;        // depth of boarder
int VFO_B_freq_boarder_colour = ILI9341_GREEN;

int VFO_B_freq_cursor_pos_x = 60;     // position for top left
int VFO_B_freq_cursor_pos_y = 137;    // position for top left

int RIT_B_freq_cursor_pos_x = 125;    // position for top left
int RIT_B_freq_cursor_pos_y = 170;    // position for top left
int RIT_B_freq_text_colour = ILI9341_WHITE;

int VFO_B_freq_text_colour = ILI9341_MAGENTA;
int VFO_B_mhz_cursor_pos_x = 185;     // position for top left
int VFO_B_mhz_cursor_pos_y = 148;     // position for top left
// -------------------------------------

int info_boarder_x = 5;             // position for top left 
int info_boarder_y = 202;           // position for top left
int info_boarder_w = 310;           // width of boarder
int info_boarder_d = 35;            // depth of boarder
int info_boarder_colour = ILI9341_GREEN;

int info_cursor_pos_x = 35;         // position for top left
int info_cursor_pos_y = 203;        // position for top left
int info_text_colour = ILI9341_YELLOW;
// --------------------------------------

// ****** End of File
