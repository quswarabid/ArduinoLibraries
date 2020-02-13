#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

/* A Variable is a value that you can vary!
 * In the below line, I am creating a new variable called "distance"
 * This variable could be called anything!
 * I am also telling the computer that it is of type int, that is: an integer, a whole number
 * Lastly, I am also setting it to 30.
 * 
 */
int distance = 30;


void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  /*
   * Note how I can use the variable 'distance' to define how far the Pablo wheels will travel.
   * This is the power of variables: you can use them anywhere.
   */ 
  pablo.turn_wheels_mm(distance, distance);

}