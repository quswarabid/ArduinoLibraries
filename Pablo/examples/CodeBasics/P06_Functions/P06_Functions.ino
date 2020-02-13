#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  /*
   * The below command 'drawSpike' is a custom command.
   * By creating a function, you can create as many custom commands as you like
   * See below for the function definition
   */
  drawSpike(); 

}

/*
 * This is a function. You can write as many as you like.
 * Functions are very useful for organising your code.
 * This particular function uses 2 variables and a bunch of operators
 * to draw a spike.
 */

void drawSpike() {
  
  int leftDistance = 30;
  int rightDistance = 60;

  pablo.turn_wheels_mm(leftDistance, rightDistance);
  pablo.turn_wheels_mm(leftDistance * -1, (rightDistance - 10) * -1);

}