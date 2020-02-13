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
   * Arrays are just lists of things. You can have a list of anything:
   * A list of integers, of strings, of floating point numbers etc.
   * Arrays are also very useful. When programming in C or C++ you will 
   * see them everywhere.
   * 
   * The line below declares an array called 'distances'.
   * It is the square brackets '[]' that tells the computer that this variable is an array.
   *
   * Notice that the values in the array are then defined as comma separated values 
   * bound by curly braces '{}'.
   *
   * This array has 6 values
   */

  int distances[] = {
    20, 72, 100, 53, 42, 35
  }; 

  /*
   * To access the values in the array, you need to specify what is claled the 'index'
   * The index is the position that a variable holds in the array.
   * So:
   * - index 0 is the value 20
   * - index 1 is the value 72
   * - index 2 is the value 100
   * 
   * etc.
   *
   * Note how, in the For loop below, the index value is taken directly from the loop's 'i' variable.
   * As it turns out, For loops and arrays are a very natural fit.
   */
  for (int i = 0 ; i < 6 ; i ++) {

    // travel the distance defined in the array
    pablo.turn_wheels_mm(distances[i], distances[i]);

    // pivot the Artbot, before travelling th enext distance
    pablo.turn_wheels_mm(50, -50);

  }

}