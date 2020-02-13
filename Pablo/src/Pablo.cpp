#include "Arduino.h"
#include "Pablo.h"

Pablo::Pablo()
{
  _pabloVersion = PABLO_V1;
}

Pablo::Pablo(int pabloVersion){
  _pabloVersion = pabloVersion;
}

void Pablo::init(String botName, String botMessage){
  _botMessage = botMessage;
  _botName = botName;
  init();
}

void Pablo::init(String botName){
  _botName = botName;
  init();
}

void Pablo::init(){

  // Use different button position based on whether old or new Pablo
  // This is because the button key pad may be upside down
  if (_pabloVersion == PABLO_V2 ) {

    buttonIncThousands= 22; // K0: 22
    buttonIncHundreds = 23; // K1: 23
    buttonIncTens     = 24; // K2: 24
    buttonIncOnes    = 25;  // K3: 25

    buttonDrawingMode = 29; // K4: 26
    buttonUnused = 27;      // K5: 27
    buttonPresets = 28;     // K6: 28
    buttonStart = 26;       // K7: 29

  } else {

    buttonIncThousands= 22;  // K0: 22
    buttonIncHundreds = 23;  // K1: 23
    buttonIncTens     = 24;  // K2: 24
    buttonIncOnes     = 25;  // K3: 25

    buttonDrawingMode = 26;  // K4: 26
    buttonUnused = 27;       // K5: 27
    buttonPresets = 28;      // K6: 28
    buttonStart = 29;        // K7: 29

  }

  setupMotors();
  setupDisplay();
  setupRotaryEncoder();
  setupButtons();

}

void Pablo::run(){

  // stay here as long as we are not in custom mode
  while ( drawingMode == 0 ) {
    default_mode();
  } 
  
}

/*
 * Waits for start button to be pressed
 */
bool Pablo::waitForStartButton(){

  // dis-engage the motors;
  disablePowerToMotors();

  while ( digitalRead(buttonStart) == HIGH ) {
    delay(100);
  }

  // engage the motors;
  enablePowerToMotors();

  return true;
}

void Pablo::readModeButton(){
  
  if ( digitalRead(buttonDrawingMode) == LOW ) {
    // mode button pressed

    if ( buttonDrawingMode_state == 0) {
      // if we get here then it is a fresh push
      
      buttonDrawingMode_state = 1;
      drawingMode ++;
      if (drawingMode > 1) drawingMode = 0;
    } 

  } else {
    // mode button unpressed, 
    buttonDrawingMode_state = 0;
  }
  
}

