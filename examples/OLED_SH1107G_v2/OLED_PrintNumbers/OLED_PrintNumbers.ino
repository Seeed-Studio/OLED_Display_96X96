/*
  The new OLED module drive IC has two version,
  1. SH1107G (Note: SH1107G does not support scroll, gray display)
  2. SSD1327
  
  Change the paramater of the drive IC name to init the module.
  **
  ** SeeedGrayOled.init(SSD1327);  // SSD1327 or SH1107G
  **

  Copyright - Seeedstudio
  Author - lambor
  Date - 4/24/2017
*/
#include <Wire.h>
#include <SeeedGrayOLED.h>


void setup()
{
  Wire.begin();	
  SeeedGrayOled.init(SH1107G);  //initialize SEEED Gray OLED display

  SeeedGrayOled.clearDisplay();           //clear the screen and set start position to top left corner
  SeeedGrayOled.setNormalDisplay();       //Set display to Normal mode
  SeeedGrayOled.setVerticalMode();        // Set to vertical mode for displaying text

  SeeedGrayOled.setTextXY(0,0);           //Set the cursor to 0th line, 0th Column  
  SeeedGrayOled.putNumber(123);           //Print number
  SeeedGrayOled.setTextXY(1,0);           //Set the cursor to 1st line, 0th Column  
  SeeedGrayOled.putNumber(0xFFFF);        //Print number
  SeeedGrayOled.setTextXY(2,0);           //Set the cursor to 2nd line, 0th Column  
  SeeedGrayOled.putNumber(0xFFFFFFFF);    //Print number
  SeeedGrayOled.setTextXY(3,0);           //Set the cursor to 3rd line, 0th Column  
  SeeedGrayOled.putNumber(-12345);        //Print number


}

void loop()
{
  
}


