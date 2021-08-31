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


// define encoder pins
// So this project has two encoders so ....
#define encoder_VFO_PinA  5
#define encoder_VFO_PinB  4

#define encoder_RIT_PinA  8
#define encoder_RIT_PinB  7


// ******** Encoder routines ****************************************************************************
volatile int encState = 0;

const uint8_t encTableHalfStep[6][4] =
{
    {0x3, 0x2, 0x1, 0x0},
    {0x23, 0x0, 0x1, 0x0},
    {0x13, 0x2, 0x0, 0x0},
    {0x3, 0x5, 0x4, 0x0},
    {0x3, 0x3, 0x4, 0x10},
    {0x3, 0x5, 0x3, 0x20},
};

const uint8_t encTableFullStep[7][4] =
{
    {0x0, 0x2, 0x4,  0x0},
    {0x3, 0x0, 0x1, 0x10},
    {0x3, 0x2, 0x0,  0x0},
    {0x3, 0x2, 0x1,  0x0},
    {0x6, 0x0, 0x4,  0x0},
    {0x6, 0x5, 0x0, 0x20},
    {0x6, 0x5, 0x4,  0x0},
};

void VFO_RotEncHalfStep()
{
  if(flag.keyer_help==false){
      if(flag.vfo_A_active == true){
          encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder_VFO_PinB) << 1) | digitalRead(encoder_VFO_PinA)];
    
          int result = encState & 0x30;
          int temp;
          
          if (result){
            
            if(result == 0x10){
              temp = -1;
            }
            if(result == 0x20){
              temp = 1;
            }   
            // -------------- now for frequency multipliers
    
            if((u.tune_multi)==1){
                u.vfo_A_value += temp;
            }
            if((u.tune_multi)==2){
                u.vfo_A_value += (temp * 10);
            }
            if((u.tune_multi)==3){
                u.vfo_A_value += (temp * 100);
            }
            if((u.tune_multi)==4){
                u.vfo_A_value += (temp * 1000);
            }
            if((u.tune_multi)==5){
                u.vfo_A_value += (temp * 10000);
            }
            if((u.tune_multi)==6){
                u.vfo_A_value += (temp * 100000);
            }
    // --------------- end of frequency multipliers 
         
            flag.freq_Changed=true;      
           }
        }
      if(flag.vfo_B_active == true){
          encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder_VFO_PinB) << 1) | digitalRead(encoder_VFO_PinA)];
    
          int result = encState & 0x30;
          int temp;
          
          if (result){ 
               
            if(result == 0x10){
              temp = -1;
            }
            if(result == 0x20){
              temp = 1;
            }
    // -------------- now for frequency multipliers
    
            if((u.tune_multi)==1){
                u.vfo_B_value += temp;
            }
            if((u.tune_multi)==2){
                u.vfo_B_value += (temp * 10);
            }
            if((u.tune_multi)==3){
                u.vfo_B_value += (temp * 100);
            }
            if((u.tune_multi)==4){
                u.vfo_B_value += (temp * 1000);
            }
            if((u.tune_multi)==5){
                u.vfo_B_value += (temp * 10000);
            }
            if((u.tune_multi)==6){
                u.vfo_B_value += (temp * 100000);
            }
    // --------------- end of frequency multipliers 
         
            flag.freq_Changed=true;
          }
        }   
     }
}


void VFO_RotEncFullStep()
{
  if(flag.keyer_help==false){
      if(flag.vfo_A_active == true){
          encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_VFO_PinB) << 1) | digitalRead(encoder_VFO_PinA)];
    
          int result = encState & 0x30;
          int temp;
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }   
            // -------------- now for frequency multipliers
    
            if((u.tune_multi)==1){
                u.vfo_A_value += temp;
            }
            if((u.tune_multi)==2){
                u.vfo_A_value += (temp * 10);
            }
            if((u.tune_multi)==3){
                u.vfo_A_value += (temp * 100);
            }
            if((u.tune_multi)==4){
                u.vfo_A_value += (temp * 1000);
            }
            if((u.tune_multi)==5){
                u.vfo_A_value += (temp * 10000);
            }
            if((u.tune_multi)==6){
                u.vfo_A_value += (temp * 100000);
            }
            // --------------- end of frequency multipliers 
         
            flag.freq_Changed=true;
          }
        }
    
          if(flag.vfo_B_active == true){
          encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_VFO_PinB) << 1) | digitalRead(encoder_VFO_PinA)];
    
          int result = encState & 0x30;
          int temp;
          
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }
    // -------------- now for frequency multipliers
    
            if((u.tune_multi)==1){
                u.vfo_B_value += temp;
            }
            if((u.tune_multi)==2){
                u.vfo_B_value += (temp * 10);
            }
            if((u.tune_multi)==3){
                u.vfo_B_value += (temp * 100);
            }
            if((u.tune_multi)==4){
                u.vfo_B_value += (temp * 1000);
            }
            if((u.tune_multi)==5){
                u.vfo_B_value += (temp * 10000);
            }
            if((u.tune_multi)==6){
                u.vfo_B_value += (temp * 100000);
            }
    // --------------- end of frequency multipliers 
         
            flag.freq_Changed=true;
          }
       }   
    }
}

   


void RIT_RotEncHalfStep()
{
  if(flag.keyer_help == false){
      if(flag.vfo_A_active == true){
          encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
         
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }   
            
            u.RIT_A += temp;
            u.RIT_A=constrain(u.RIT_A,-40,40);
            flag.RIT_Changed=true;
            
           }
       }
    
       if(flag.vfo_B_active == true){
          encState = encTableHalfStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
         
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }   
           
            u.RIT_B += temp;
            u.RIT_B=constrain(u.RIT_B,-40,40); 
            flag.RIT_Changed=true;
            
           }
       }
  }
  if(flag.keyer_help == true){

       encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
        
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }
               
                u.keyer_help_index += temp;
                u.keyer_help_index=constrain(u.keyer_help_index,0,7); 
                flag.keyer_page_reDraw=true;
                
            }
    
  }
  
}


void RIT_RotEncFullStep()
{
  if(flag.keyer_help == false){
      if(flag.vfo_A_active == true){
          encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
        
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }
              
                u.RIT_A += temp; 
                u.RIT_A=constrain(u.RIT_A,-40,40);                  // this works
                flag.RIT_Changed=true;   
            }
      }
    
      if(flag.vfo_B_active == true){
          encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
        
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }
               
                u.RIT_B += temp;
                u.RIT_B=constrain(u.RIT_B,-40,40); 
                flag.RIT_Changed=true;   
                
            }
      } 
  }
  if(flag.keyer_help == true){

       encState = encTableFullStep[encState & 0xF][(digitalRead(encoder_RIT_PinB) << 1) | digitalRead(encoder_RIT_PinA)];
    
          int result = encState & 0x30;
          int temp;
        
          if (result){
            
            if(result == 0x10){
              temp = 1;
            }
            if(result == 0x20){
              temp = -1;
            }
               
                u.keyer_help_index += temp;
                u.keyer_help_index=constrain(u.keyer_help_index,0,7); 
               flag.keyer_page_reDraw=true;
                
            }
    
  }
}

// ****** End of File
