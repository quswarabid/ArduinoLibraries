/*
 * Handles the OLED display objects
 */

#include "Arduino.h"
#include "Pablo.h"

// See Fonts available here:
// https://github.com/olikraus/u8g2/wiki/fntlistall 

// Buffer for holding messages as Char array
char pablos_buf[40];
int stringLength;

void Pablo::setupDisplay(){

  if (_pabloVersion == PABLO_V2 ) {
    // turn screen upside down
    // Use U8G2_R2 to put it upside down
    OLEDScreen = new U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display    
  } else {
    // screen up same way as writing on screen
    OLEDScreen = new U8G2_SSD1306_128X64_NONAME_F_HW_I2C(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display  
  }

  // Initialise the OLED display
  OLEDScreen -> begin();
  OLEDScreen -> clearBuffer();

  // Draw large Pable name
  OLEDScreen -> setFont(u8g2_font_fub25_tr);
  _botName.toCharArray(pablos_buf, 40);
  stringLength = _botName.length();
  // work out indent of text string (centre it) and print out
  OLEDScreen -> drawStr( (122 - (stringLength * 17 )) / 2 , 35, pablos_buf);

  // Draw small Pablo message
  OLEDScreen -> setFont(u8g2_font_etl14thai_t);
  _botMessage.toCharArray(pablos_buf, 40);
  // work out indent of text string (centre it) and print out
  stringLength = _botMessage.length();
  OLEDScreen -> drawStr( (126 - (stringLength * 7 )) / 2  , 55, pablos_buf);

  // send to screen
  OLEDScreen -> sendBuffer();

  delay(1000);

}

/*
 *
 *  SCREEN HANDLING
 *
 */
void Pablo::report() {

  OLEDScreen -> clearBuffer();

  OLEDScreen -> setFont(u8g2_font_6x12_tr);

  OLEDScreen -> drawStr(36,10,"< speed >");
  OLEDScreen -> drawStr(38,28,"  dist  ");
  OLEDScreen -> drawStr(39,38,"/      \\");
  
  OLEDScreen -> setFont(u8g2_font_profont10_mf);
  OLEDScreen -> drawStr(50,38,"+");
  sprintf (pablos_buf, "%d", rotary_increment);
  OLEDScreen -> drawStr(55,38, pablos_buf );

  OLEDScreen -> setFont(u8g2_font_profont22_mn);
  
  sprintf (pablos_buf, "%ld", setting_right_wheel_distance);
  OLEDScreen -> drawStr(66, 60, pablos_buf) ;
  sprintf (pablos_buf, "%d", setting_right_wheel_speed);
  OLEDScreen -> drawStr(103, 17, pablos_buf) ;
  sprintf (pablos_buf, "%d", setting_left_wheel_speed);
  OLEDScreen -> drawStr(3, 17, pablos_buf) ;
  sprintf (pablos_buf, "%ld", setting_left_wheel_distance);
  OLEDScreen  -> drawStr(3, 60, pablos_buf) ;

  // mat working on mouse over for 1 encoder
  if (rotaryMode == 0) {
    OLEDScreen  -> drawFrame(64, 43, 63, 20);

  } else if (rotaryMode == 1) {
    OLEDScreen  -> drawFrame(100,0, 28, 20);

  } else if (rotaryMode == 2) {
    OLEDScreen  -> drawFrame(0,0,28,20);

  } else if (rotaryMode == 3) {
    OLEDScreen  -> drawFrame(0, 43 , 63, 20);
  }

  OLEDScreen -> sendBuffer();
}

void Pablo::message(String text) {

  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_profont12_mf);
  text.toCharArray(pablos_buf, 20);
  OLEDScreen -> drawStr(20,30, pablos_buf); //this copies some text to the screens memory
  OLEDScreen -> sendBuffer();

}

void Pablo::messageLarge(String text) {
 
  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_fub25_tr);
  text.toCharArray(pablos_buf, 20);
  OLEDScreen -> drawStr(10, 40, pablos_buf); //this copies some text to the screens memory
  OLEDScreen -> sendBuffer();

}

void Pablo::message(int text) {

  sprintf (pablos_buf, "%d", text);
  message(pablos_buf);

}

void Pablo::displayStartMessage() {
  displayCountDown(3);
  delay(1000);
  displayCountDown(2);
  delay(1000);
  displayCountDown(1);
  delay(1000);
}

void Pablo::displayCountDown(int count) {

  OLEDScreen -> clearBuffer();
  OLEDScreen -> setFont(u8g2_font_crox5h_tf);
  OLEDScreen -> drawStr(5 , 25, "Step back!");

  OLEDScreen -> setFont(u8g2_font_etl14thai_t);
  OLEDScreen -> drawStr(8 , 60, "Starting in: ");

  OLEDScreen -> setFont(u8g2_font_fub25_tr);
  sprintf (pablos_buf, "%d", count);
  OLEDScreen -> drawStr(96 , 60, pablos_buf);

  OLEDScreen -> sendBuffer();
}


