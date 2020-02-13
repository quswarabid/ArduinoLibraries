#include "Arduino.h"
#include "Pablo.h"

void Pablo::default_mode(){

  if (!isDrawing) {
    readRotaryEncoders();

    // Choose parameter. This controls which value will be modified by the knob
    if (digitalRead(rotaryEncoder1_set_btnPin) == LOW) {
      rotaryMode = (rotaryMode + 1) % 4;
      report();
      delay(300);
    }

    // Choose drawingMode
    readModeButton();

    // Change increment.
    if (digitalRead(buttonIncThousands) == LOW) {
      rotary_increment = 1000; report();
      // cycleRotaryIncrement();
    } else if (digitalRead(buttonIncHundreds) == LOW){
      rotary_increment = 100; report();
    } else if (digitalRead(buttonIncTens) == LOW){
      rotary_increment = 10; report();
    } else if (digitalRead(buttonIncOnes) == LOW){
      rotary_increment = 1; report();
    }

    // Choose preset
    if (digitalRead(buttonPresets) == LOW) {
      // increment preset_index
      preset_index = preset_index + 1;

      // check if at end of preset length, wrap
      if (preset_index >= (sizeof (pablo_presets) / sizeof (*pablo_presets)) ){
        preset_index = 0;
      }

      // make sure preset values are captured
      setting_left_wheel_distance = pablo_presets[preset_index][0]; 
      setting_left_wheel_speed = pablo_presets[preset_index][1];   // in mm
      setting_right_wheel_speed = pablo_presets[preset_index][2];  // arbitrary scale
      setting_right_wheel_distance = pablo_presets[preset_index][3]; // in mm

      report();
      delay(200);
    }

    // Push to start
    if (digitalRead(buttonStart) == LOW) {
      isDrawing = true;

      // engage the motors
      enablePowerToMotors();
      
      displayStartMessage();
      captureSettings();
      report();
    }

  } else {

    // Bounce the right wheel direction
    if (stepper_r -> distanceToGo() == 0) {
      stepper_r -> moveTo( -stepper_r -> currentPosition() );
    }

    // Bounce the left wheel direction
    if (stepper_l -> distanceToGo() == 0) {
      stepper_l -> moveTo( -stepper_l -> currentPosition() );
    }

    // Look for stop button
    if (digitalRead(buttonStart) == LOW) {
      messageLarge("Stop!");
      stopAndResetSteppers();
      report();
    }

    // Go!
    stepper_r -> run();
    stepper_l -> run();

  }
}

