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

//
//-----------------------------------------------------------------------------
//  Screensaver display
//-----------------------------------------------------------------------------
//
void splashscreen(void)
{
    tft.setCursor(50,50); 
    tft.setTextColor(ILI9341_YELLOW);
    tft.setFont(DroidSansMono_12);
    tft.println("Initial firmware release:");
    tft.setCursor(50,70);
    tft.println("SCD 2021 Project");
    tft.setCursor(50,90);
    tft.print("Version Number: ");
    tft.println(VERSION);
    tft.setCursor(50,110);
    tft.println(MY_CALLSIGN);
    tft.setCursor(50,130);
    tft.print(BANNER);
}

void rectangle(int x, int y, int w, int d, uint16_t color) 
{
  tft.drawRect(x, y, w, d, color);
}

void display_help_pages(void){

    tft.setCursor(50,50); 
    tft.setTextColor(ILI9341_YELLOW);
    tft.setFont(DroidSansMono_12);
   // tft.println("Initial start of help pages");
    switch (u.keyer_help_index){
      case 0:   // help page 0

        
        
        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,10);
        tft.println("Start-up:");
        
        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        tft.println(" ");
        tft.setCursor(10,50);
        tft.println("When the keyer is powered ON");
        tft.setCursor(10,70);
        tft.println("It will play the letter 'R'");
        tft.setCursor(10,90);
        tft.println("(for ready) over the sidetone");
        tft.setCursor(10,110);
        tft.println("speaker.");
        tft.setCursor(10,130);
        tft.println("");
        tft.setCursor(10,150);
        tft.println("This will NOT be transmitted");
        tft.setCursor(10,170);
        tft.println("");
        tft.setCursor(10,190);
        tft.println("");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 1 of 8");
        
        break;

      case 1:   // help page 1
        
        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Factory defaults:");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        tft.println("To restore factory defaults :");
        tft.setCursor(10,50);
        tft.println("Turn off the unit, & hold");
        tft.setCursor(10,70);
        tft.println("down Mem1 & Settings Buttons");
        tft.setCursor(10,90);
        tft.println("and then turn the unit back");
        tft.setCursor(10,110);
        tft.println("ON (while continuing to hold");
        tft.setCursor(10,130);
        tft.println("these two buttons.)");
        tft.setCursor(10,150);
        tft.println("A 3-tone sound will");
        tft.setCursor(10,170);
        tft.println("indicate a factory reset");
        tft.setCursor(10,190);
        tft.println("has occured.");
        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 2 of 8");
        
        break;

      case 2:   // help page 2

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Settings");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        //          "                              "
        tft.println("In the default mode, the keyer");
        tft.setCursor(10,50);
        tft.println("works as a normal iambic keyer.");
        tft.setCursor(10,70);
        tft.println("Holding the left paddle emits ");
        tft.setCursor(10,90);
        tft.println("a series of dits, holding the ");
        tft.setCursor(10,110);
        tft.println("right paddle emitts a series");
        tft.setCursor(10,130);
        tft.println("of dahs, & holding both emits");
        tft.setCursor(10,150);
        tft.println("alternating dits and dahs.");
        tft.setCursor(10,170);
        tft.println("");
        tft.setCursor(10,190);
        tft.println("");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 3 of 8");
        
        break;

       case 3:   // help page 3

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Change speed:");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        //          "                              "
        tft.setCursor(10,30);
        tft.println("Briefly press and release the");
        tft.setCursor(10,50);
        tft.println("'Settings' button. The keyer");
        tft.setCursor(10,70);
        tft.println("will be constantly emitting");
        tft.setCursor(10,90);
        tft.println("dits (these are NOT Tx'ed).");
        tft.setCursor(10,110);
        tft.println("Holding the left paddle");
        tft.setCursor(10,130);
        tft.println("increases speed, holding");
        tft.setCursor(10,150);
        tft.println("the right paddle decreases");
        tft.setCursor(10,170);
        tft.println("speed. Press the 'Setting'");
        tft.setCursor(10,190);
        tft.println("button to save setting.");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 4 of 8");
        
        break;

       case 4:   // help page 4

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Change Sidetone");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        //          "                              "
        tft.setCursor(10,30);
        tft.println("Hold the 'Settings' button");
        tft.setCursor(10,50);
        tft.println("until the 'Control' LED turns");
        tft.setCursor(10,70);
        tft.println("ON (1 sec) release the button");
        tft.setCursor(10,90);
        tft.println("The keyer will be constantly");
        tft.setCursor(10,110);
        tft.println("emitting dits (NOT Tx'ed)");
        tft.setCursor(10,130);
        tft.println("The pitch is changed by the");
        tft.setCursor(10,150);
        tft.println("paddles, Press the 'Settings'");
        tft.setCursor(10,170);
        tft.println("button to save setting.");
        tft.setCursor(10,190);
        tft.println("");


        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 5 of 8");
        break;

       case 5:   // help page 5

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Change Keyer mode:");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        tft.println("Hold the 'Settings' button");
        tft.setCursor(10,50);
        tft.println("& while held press one of");
        tft.setCursor(10,70);
        tft.println("the Memory buttons:");
        tft.setCursor(10,90);
        tft.println("Mem 1 = Iambic");
        tft.setCursor(10,110);
        tft.println("Mem 2 = Straight");
        tft.setCursor(10,130);
        tft.println("A tone will be emitted");
        tft.setCursor(10,150);
        tft.println("when set:");
        tft.setCursor(10,170);
        tft.println("'I' for Iambic.");
        tft.setCursor(10,190);
        tft.println("'S' for Straight.");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 6 of 8");
        
        break;

      case 6:   // help page 6

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Set Memory:");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        tft.println("Hold the Mem button until ");
        tft.setCursor(10,50);
        tft.println("the 'Control' LED turns ON");
        tft.setCursor(10,70);
        tft.println("Release the memory button.");
        tft.setCursor(10,90);
        tft.println("Send you message via key");
        tft.setCursor(10,110);
        tft.println("as if transmitting (Tx = OFF)");
        tft.setCursor(10,130);
        tft.println("When finished, press the same");
        tft.setCursor(10,150);
        tft.println("memory button again. A 3 tone");
        tft.setCursor(10,170);
        tft.println("sound will be emitted (saved)");
        tft.setCursor(10,190);
        tft.println("& the LED will blink.");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 7 of 8");
        
        break;

        case 7:   // help page 6

        tft.setTextColor(ILI9341_YELLOW);
        tft.setFont(DroidSansMono_12);

        tft.setCursor(10,10);
        tft.println("Replay Memory:");

        tft.setTextColor(ILI9341_WHITE);
        tft.setFont(DroidSansMono_12);
        
        tft.setCursor(10,30);
        tft.println("Press the memory key ");
        tft.setCursor(10,50);
        tft.println("quickly, making sure not to");
        tft.setCursor(10,70);
        tft.println("hold the button down for ");
        tft.setCursor(10,90);
        tft.println("longer than 1 second.");
        tft.setCursor(10,110);
        tft.println("The stored memory will play.");
        tft.setCursor(10,130);
        tft.println("If the memory is empty a ");
        tft.setCursor(10,150);
        tft.println("two tone 'empty' will be");
        tft.setCursor(10,170);
        tft.println("emitted ");
        tft.setCursor(10,190);
        tft.println("This is NOT transmitted.");

        tft.setCursor(200,220); 
        tft.setTextColor(ILI9341_GREEN);
        tft.setFont(DroidSansMono_12);
        tft.println("Page 8 of 8");
        
        break;
      
    }   
}

void display_main_screen(void)
{
  // clear screen
  tft.fillScreen(ILI9341_BLACK);
  
  // draw boarder around full display
  rectangle(outline_boarder_x, outline_boarder_y, outline_boarder_w, outline_boarder_d, outline_boarder_colour);

  // draw rectangle around frequency display
 tft.drawRoundRect(VFO_A_freq_boarder_x,VFO_A_freq_boarder_y,VFO_A_freq_boarder_w,VFO_A_freq_boarder_d,3,ILI9341_DARKGREY);

  // clear frequency text area just incase there is something there!
  tft.fillRect((VFO_A_freq_boarder_x +1),(VFO_A_freq_boarder_y + 1), (VFO_A_freq_boarder_w - 3), (VFO_A_freq_boarder_d - 2), ILI9341_BLACK);

  // draw rectangle around frequency display
  tft.drawRoundRect(VFO_B_freq_boarder_x,VFO_B_freq_boarder_y,VFO_B_freq_boarder_w,VFO_B_freq_boarder_d,3,ILI9341_DARKGREY);

  // clear frequency text area just incase there is something there!
  tft.fillRect((VFO_B_freq_boarder_x +1),(VFO_B_freq_boarder_y + 1), (VFO_B_freq_boarder_w - 3), (VFO_B_freq_boarder_d - 2), ILI9341_BLACK);

   // draw rectangle around frequency display
   tft.drawRoundRect(info_boarder_x,info_boarder_y,info_boarder_w,info_boarder_d,3,ILI9341_DARKGREY);

// now display VFO A & B plus RIT text

  tft.setCursor(VFO_A_freq_cursor_pos_x - 50,VFO_A_freq_cursor_pos_y );
  tft.setFont(DroidSansMono_10);
  tft.setTextColor(ILI9341_DARKGREY);
  tft.print("VFO");
  tft.setCursor(VFO_A_freq_cursor_pos_x - 45,VFO_A_freq_cursor_pos_y + 15);
  tft.print("A");

  tft.setCursor(VFO_A_freq_cursor_pos_x - 50,VFO_A_freq_cursor_pos_y + 42);
  tft.setFont(DroidSansMono_10);
  tft.setTextColor(ILI9341_DARKGREY);
  tft.print("RIT");

  tft.setCursor(VFO_B_freq_cursor_pos_x - 50,VFO_B_freq_cursor_pos_y );
  tft.setFont(DroidSansMono_10);
  tft.setTextColor(ILI9341_DARKGREY);
  tft.print("VFO");
  tft.setCursor(VFO_B_freq_cursor_pos_x - 45,VFO_B_freq_cursor_pos_y + 15);
  tft.print("B");
  
  tft.setCursor(VFO_B_freq_cursor_pos_x - 50,VFO_B_freq_cursor_pos_y + 42);
  tft.setFont(DroidSansMono_10);
  tft.setTextColor(ILI9341_DARKGREY);
  tft.print("RIT");

/*
  // Now display a user message while system is initialising
  tft.fillRect((info_boarder_x +1),(info_boarder_y + 1), (info_boarder_w - 3), (info_boarder_d - 2), ILI9341_BLACK);
  tft.setCursor(info_cursor_pos_x  ,info_cursor_pos_y + 10); 
  tft.setTextColor(info_text_colour);
  // set frequency readout font size
  tft.setFont(DroidSansMono_12);
  //tft.print("Keyer : Iambic    - G5LOW");
  if(currKeyerMode==0){
    tft.print("Keyer : Iambic    - G5LOW");
  }
  if(currKeyerMode==2){
    tft.print("Keyer : Straight    - G5LOW");
  }
*/
}

// Draw frequency multiplier bar on display
void Freq_Multi_Bar (){

  if(flag.freq_multi_bar){
     
       if(u.tune_multi==1){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );
        
          if(flag.vfo_A_active==true){
            tft.fillRect(223,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(223,163,14,2,ILI9341_CYAN );
          }  
       }
       
       if(u.tune_multi==2){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );
        
          if(flag.vfo_A_active==true){
            tft.fillRect(202,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(202,163,14,2,ILI9341_CYAN );
          }
       }
       
       if(u.tune_multi==3){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );

           if(flag.vfo_A_active==true){
            tft.fillRect(181,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(181,163,14,2,ILI9341_CYAN );
          }
       }
       
       if(u.tune_multi==4){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );

            if(flag.vfo_A_active==true){
            tft.fillRect(145,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(145,163,14,2,ILI9341_CYAN );
          }    
       }
       
       if(u.tune_multi==5){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );

            if(flag.vfo_A_active==true){
            tft.fillRect(125,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(125,163,14,2,ILI9341_CYAN );
          }         
       }
       
       if(u.tune_multi==6){
        tft.fillRect(100,88,140,2,ILI9341_BLACK );
        tft.fillRect(100,163,140,2,ILI9341_BLACK );

            if(flag.vfo_A_active==true){
            tft.fillRect(103,88,14,2,ILI9341_CYAN );
          }
          if(flag.vfo_B_active==true){
            tft.fillRect(103,163,14,2,ILI9341_CYAN );
          }   
       }   
    }
}

void display_update_vfo(){
  
      // ------ variables used for vfo uodates etc.
      String freqt=String(u.vfo_A_value);    // Text frquency convertrd
      char F100m,F10m,Fmega,F100k,F10k,F1k,F100,F10,F1; //EachdDigit for VFO A
      char f100m,f10m,fmega,f100k,f10k,f1k,f100,f10,f1; //EachdDigit for VFO B
      int freqMulti;
      int freqlength;

      // clear frequency text area just incase there is something there!
  if(((flag.vfo_A_active==true) && (flag.freq_Changed=true))  || (flag.vfo_A_B_changed==true))
    
  {      
      // set frequency readout font size
      tft.setFont(DroidSansMono_24);
      if(flag.vfo_A_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      if(flag.vfo_A_active==true)
      {
          tft.setTextColor(VFO_A_freq_text_colour); 
      }
      tft.setCursor(VFO_A_freq_cursor_pos_x,VFO_A_freq_cursor_pos_y);
      
      // ------ Display VFO A frequency

      freqt=String(u.vfo_A_value);
      freqlength=(freqt.length());

      if(F1 !=(freqt.charAt(freqlength-1))){

          int F1_OffSet = 159;
          int F1_x = VFO_A_freq_cursor_pos_x + F1_OffSet;
          int F1_y = VFO_A_freq_cursor_pos_y ;

          tft.fillRect(F1_x,F1_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F1_x,F1_y);
          tft.print(freqt.charAt(freqlength-1)); 
          F1 = (freqt.charAt(freqlength-1)); 
          tft.print(" Hz"); 
      }
    
      if(F10 !=(freqt.charAt(freqlength-2))){
      
          int F10_OffSet = 138;
          int F10_x = VFO_A_freq_cursor_pos_x + F10_OffSet;
          int F10_y = VFO_A_freq_cursor_pos_y ;
    
          tft.fillRect(F10_x,F10_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10_x,F10_y);
          tft.print(freqt.charAt(freqlength-2)); 
          F10 = (freqt.charAt(freqlength-2));
      }
     
      if(F100 !=(freqt.charAt(freqlength-3))){
      
          int F100_OffSet = 117;
          int F100_x = VFO_A_freq_cursor_pos_x + F100_OffSet;
          int F100_y = VFO_A_freq_cursor_pos_y ;
    
          tft.fillRect(F100_x,F100_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100_x,F100_y);
          tft.print(freqt.charAt(freqlength-3));
          F100 = (freqt.charAt(freqlength-3));
      }
     
      if(F1k !=(freqt.charAt(freqlength-4))){
      
          int F1k_OffSet = 82;
          int F1k_x = VFO_A_freq_cursor_pos_x + F1k_OffSet;
          int F1k_y = VFO_A_freq_cursor_pos_y ;
    
          tft.fillRect(F1k_x,F1k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F1k_x,F1k_y);
          tft.print(freqt.charAt(freqlength-4));
          // now print seperator
          tft.print(".");  
          F1k = (freqt.charAt(freqlength-4));
      }
     
      if(F10k !=(freqt.charAt(freqlength-5))){
      
          int F10k_OffSet = 61;
          int F10k_x = VFO_A_freq_cursor_pos_x + F10k_OffSet;
          int F10k_y = VFO_A_freq_cursor_pos_y ;
    
          tft.fillRect(F10k_x,F10k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10k_x,F10k_y);
          tft.print(freqt.charAt(freqlength-5)); 
          F10k = (freqt.charAt(freqlength-5));
      }
     
       if(F100k !=(freqt.charAt(freqlength-6))){
        
          int F100k_OffSet = 40;
          int F100k_x = VFO_A_freq_cursor_pos_x + F100k_OffSet;
          int F100k_y = VFO_A_freq_cursor_pos_y ;
      
          tft.fillRect(F100k_x,F100k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100k_x,F100k_y);
          tft.print(freqt.charAt(freqlength-6)); 
          F100k = (freqt.charAt(freqlength-6));
       }
     
       if(Fmega !=(freqt.charAt(freqlength-7))){
        
          int Fmega_OffSet = 5;
          int Fmega_x = VFO_A_freq_cursor_pos_x + Fmega_OffSet;
          int Fmega_y = VFO_A_freq_cursor_pos_y ;
      
          tft.fillRect(Fmega_x,Fmega_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(Fmega_x,Fmega_y);
          tft.print(freqt.charAt(freqlength-7));
          // now print seperator
          tft.print(".");
          Fmega = (freqt.charAt(freqlength-7));
       }
     
       if(F10m !=(freqt.charAt(freqlength-8))){
        
          int F10m_OffSet = -16;
          int F10m_x = VFO_A_freq_cursor_pos_x + F10m_OffSet;
          int F10m_y = VFO_A_freq_cursor_pos_y ;
      
          tft.fillRect(F10m_x,F10m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F10m_x,F10m_y);
          tft.print(freqt.charAt(freqlength-8)); 
          F10m = (freqt.charAt(freqlength-8));
       }
     
       if(F100m !=(freqt.charAt(freqlength-9))){
        
          int F100m_OffSet = -37;
          int F100m_x = VFO_A_freq_cursor_pos_x + F100m_OffSet;
          int F100m_y = VFO_A_freq_cursor_pos_y ;
      
          tft.fillRect(F100m_x,F100m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(F100m_x,F100m_y);
          tft.print(freqt.charAt(freqlength-9)); 
          F100m = (freqt.charAt(freqlength-9));
       }
  }

  if((((flag.vfo_B_active==true) && (flag.freq_Changed=true)) || (flag.ReDraw_Screen==true))  || (flag.vfo_A_B_changed==true))
  {
       // set frequency readout colour & font size
      tft.setFont(DroidSansMono_24);

      if(flag.vfo_B_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      if(flag.vfo_B_active==true)
      {
          tft.setTextColor(VFO_A_freq_text_colour); 
      }

      tft.setCursor(VFO_B_freq_cursor_pos_x,VFO_A_freq_cursor_pos_y);
      
      // ------ Display VFO B frequency

      freqt=String(u.vfo_B_value);
      freqlength=(freqt.length());

      if(f1 !=(freqt.charAt(freqlength-1))){

          int f1_OffSet = 159;
          int f1_x = VFO_B_freq_cursor_pos_x + f1_OffSet;
          int f1_y = VFO_B_freq_cursor_pos_y ;

          tft.fillRect(f1_x,f1_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f1_x,f1_y);
          tft.print(freqt.charAt(freqlength-1)); 
          f1 = (freqt.charAt(freqlength-1)); 
          tft.print(" Hz"); 
      }
    
      if(f10 !=(freqt.charAt(freqlength-2))){
      
          int f10_OffSet = 138;
          int f10_x = VFO_B_freq_cursor_pos_x + f10_OffSet;
          int f10_y = VFO_B_freq_cursor_pos_y ;
    
          tft.fillRect(f10_x,f10_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10_x,f10_y);
          tft.print(freqt.charAt(freqlength-2)); 
          f10 = (freqt.charAt(freqlength-2));
      }
     
      if(f100 !=(freqt.charAt(freqlength-3))){
      
          int f100_OffSet = 117;
          int f100_x = VFO_B_freq_cursor_pos_x + f100_OffSet;
          int f100_y = VFO_B_freq_cursor_pos_y ;
    
          tft.fillRect(f100_x,f100_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100_x,f100_y);
          tft.print(freqt.charAt(freqlength-3));
          f100 = (freqt.charAt(freqlength-3));
      }
     
      if(f1k !=(freqt.charAt(freqlength-4))){
      
          int f1k_OffSet = 82;
          int f1k_x = VFO_B_freq_cursor_pos_x + f1k_OffSet;
          int f1k_y = VFO_B_freq_cursor_pos_y ;
    
          tft.fillRect(f1k_x,f1k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f1k_x,f1k_y);
          tft.print(freqt.charAt(freqlength-4));
          // now print seperator
          tft.print(".");  
          f1k = (freqt.charAt(freqlength-4));
      }
     
      if(f10k !=(freqt.charAt(freqlength-5))){
      
          int f10k_OffSet = 61;
          int f10k_x = VFO_B_freq_cursor_pos_x + f10k_OffSet;
          int f10k_y = VFO_B_freq_cursor_pos_y ;
    
          tft.fillRect(f10k_x,f10k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10k_x,f10k_y);
          tft.print(freqt.charAt(freqlength-5)); 
          f10k = (freqt.charAt(freqlength-5));
      }
     
       if(f100k !=(freqt.charAt(freqlength-6))){
        
          int f100k_OffSet = 40;
          int f100k_x = VFO_B_freq_cursor_pos_x + f100k_OffSet;
          int f100k_y = VFO_B_freq_cursor_pos_y ;
      
          tft.fillRect(f100k_x,f100k_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100k_x,f100k_y);
          tft.print(freqt.charAt(freqlength-6)); 
          f100k = (freqt.charAt(freqlength-6));
       }
     
       if(fmega !=(freqt.charAt(freqlength-7))){
        
          int fmega_OffSet = 5;
          int fmega_x = VFO_B_freq_cursor_pos_x + fmega_OffSet;
          int fmega_y = VFO_B_freq_cursor_pos_y ;
      
          tft.fillRect(fmega_x,fmega_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(fmega_x,fmega_y);
          tft.print(freqt.charAt(freqlength-7));
          // now print seperator
          tft.print(".");
          fmega = (freqt.charAt(freqlength-7));
       }
     
       if(f10m !=(freqt.charAt(freqlength-8))){
        
          int f10m_OffSet = -16;
          int f10m_x = VFO_B_freq_cursor_pos_x + f10m_OffSet;
          int f10m_y = VFO_B_freq_cursor_pos_y ;
      
          tft.fillRect(f10m_x,f10m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f10m_x,f10m_y);
          tft.print(freqt.charAt(freqlength-8)); 
          f10m = (freqt.charAt(freqlength-8));
       }
     
       if(f100m !=(freqt.charAt(freqlength-9))){
        
          int f100m_OffSet = -37;
          int f100m_x = VFO_B_freq_cursor_pos_x + f100m_OffSet;
          int f100m_y = VFO_B_freq_cursor_pos_y ;
      
          tft.fillRect(f100m_x,f100m_y - 2,20,28,ILI9341_BLACK);
          tft.setCursor(f100m_x,f100m_y);
          tft.print(freqt.charAt(freqlength-9)); 
          f100m = (freqt.charAt(freqlength-9));
       }
// --------- test code ----------
      //tft.setCursor(RIT_A_freq_cursor_pos_x,RIT_A_freq_cursor_pos_y);
      //tft.setFont(DroidSansMono_18);
     // tft.setTextColor(ILI9341_DARKGREY);
      //tft.print("7.035.600 Hz");
      
      //tft.setCursor(RIT_B_freq_cursor_pos_x,RIT_B_freq_cursor_pos_y);
      //tft.setFont(DroidSansMono_18);
      //tft.setTextColor(ILI9341_DARKGREY);
      //tft.print("7.030.600 Hz");
// -------- end of test code -------
       
      flag.ReDraw_Screen= false;
      flag.vfo_A_B_changed=false;
      flag.RIT_Changed=true;
      
  }
}

void display_update_rit(){

    // ------ variables used for vfo uodates etc.
      int RIT_A_val = u.RIT_A * u.RIT_TR;
      int RIT_B_val = u.RIT_B * u.RIT_TR;
      
      u.RIT_A_value = u.RIT_Offset + u.vfo_A_value + RIT_A_val;
      u.RIT_B_value = u.RIT_Offset + u.vfo_B_value + RIT_B_val;
      
      String freqtA=String(u.RIT_A_value);    // Text frquency convertrd
      char F100m,F10m,Fmega,F100k,F10k,F1k,F100,F10,F1; //EachdDigit for VFO A
      char f100m,f10m,fmega,f100k,f10k,f1k,f100,f10,f1; //EachdDigit for VFO B
      int freqMulti;
      int freqlength;

      // clear frequency text area just incase there is something there!
  if(((((flag.vfo_A_active==true) && (flag.freq_Changed==true)) || (flag.vfo_A_B_changed==true)) || (flag.RIT_Changed==true)) || (flag.freq_Changed==true))
    
  {    

 // --------- RIT A ------------
      // set frequency readout font size
      tft.setFont(DroidSansMono_18);
      if(flag.vfo_A_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      if(flag.vfo_A_active==true)
      {
          tft.setTextColor(RIT_A_freq_text_colour); 
      } 

      tft.fillRect(RIT_A_freq_cursor_pos_x,RIT_A_freq_cursor_pos_y,106,20,ILI9341_BLACK);
      tft.setCursor(RIT_A_freq_cursor_pos_x,RIT_A_freq_cursor_pos_y);
      
      // ------ Display RIT for VFO A frequency
      //String freqtA=String(u.RIT_A_value);    // Text frquency convertrd
      //tft.print(freqtA);
      tft.print(u.RIT_A_value);
      tft.print("  Hz");

      tft.setFont(DroidSansMono_10);
      tft.fillRect(VFO_A_freq_cursor_pos_x - 20,VFO_A_freq_cursor_pos_y + 42,60,18,ILI9341_BLACK);
      tft.setTextColor(ILI9341_DARKGREY);
      tft.setCursor(VFO_A_freq_cursor_pos_x - 20,VFO_A_freq_cursor_pos_y + 42);

      tft.print(u.RIT_A);
      //flag.RIT_Changed=false;
      
// -------- now RIT B ----------
      // set frequency readout font size
      tft.setFont(DroidSansMono_18);
      if(flag.vfo_B_active==false)
      {
          tft.setTextColor(ILI9341_DARKGREY);
      }
      
      if(flag.vfo_B_active==true)
      {
          tft.setTextColor(RIT_B_freq_text_colour); 
      } 

      tft.fillRect(RIT_B_freq_cursor_pos_x,RIT_B_freq_cursor_pos_y,106,20,ILI9341_BLACK);
      tft.setCursor(RIT_B_freq_cursor_pos_x,RIT_B_freq_cursor_pos_y);
      
      // ------ Display RIT for VFO B frequency
      //String freqtB=String(u.RIT_B_value);    // Text frquency convertrd
      //tft.print(freqtB);
      tft.print(u.RIT_B_value);
      tft.print("  Hz");
      

      tft.setFont(DroidSansMono_10);
      tft.fillRect(VFO_B_freq_cursor_pos_x - 20,VFO_B_freq_cursor_pos_y + 42,60,18,ILI9341_BLACK);
      tft.setTextColor(ILI9341_DARKGREY);
      tft.setCursor(VFO_B_freq_cursor_pos_x - 20,VFO_B_freq_cursor_pos_y + 42);
      
      tft.print(u.RIT_B);
      //flag.RIT_Changed=false;
  }
  
}

// ****** End of File
