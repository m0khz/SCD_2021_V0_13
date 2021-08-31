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

void initialise_dds(){
    // Initialize the DDS
    si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
    si5351.set_correction(Si_Correction, SI5351_PLL_INPUT_XO);      // Set to specific Si5351 calibration number
    si5351.set_pll(SI5351_PLL_FIXED, SI5351_PLLA);
    si5351.drive_strength(SI5351_CLK0, SI5351_DRIVE_8MA);
    si5351.drive_strength(SI5351_CLK2, SI5351_DRIVE_8MA);
}

void update_si5351(){
 
  if(flag.vfo_A_active == true)
  {
    if(flag.freq_Changed==true){
      
      #ifdef DEBUG
          Serial.print("VFO A active - updating VFO    - value = ");
          Serial.println(u.vfo_A_value);
          Serial.println();
      #endif // DEBUG
      
      // From version 0.11 the Tx clk output (clk0) is enabled on key down - see keyer.h
       // si5351.set_freq((u.vfo_A_value * 100ULL), SI5351_CLK0);
    }
    if(flag.RIT_Changed==true){
      
      #ifdef DEBUG
          Serial.print("VFO A active - updating RIT    - value = ");
          Serial.println(u.RIT_A_value);
          Serial.println();
      #endif // DEBUG
       
      si5351.set_freq((u.RIT_A_value * 100ULL), SI5351_CLK2);
    }
  }
  
  if(flag.vfo_B_active == true)
  { 
    if(flag.freq_Changed==true){
      
       #ifdef DEBUG
          Serial.print("VFO B active - updating VFO    - value = ");
          Serial.println(u.vfo_B_value);
          Serial.println();
      #endif // DEBUG

      // From version 0.11 the Tx clk output (clk0) is enabled on key down - see keyer.h
      // si5351.set_freq((u.vfo_B_value * 100ULL), SI5351_CLK0);
    }
    if(flag.RIT_Changed==true){
      
      #ifdef DEBUG
          Serial.print("VFO B active - updating RIT    - value = ");
          Serial.println(u.RIT_B_value);
          Serial.println();
      #endif // DEBUG
      
      si5351.set_freq((u.RIT_B_value * 100ULL), SI5351_CLK2);
    }
  }
}

// ****** End of File
