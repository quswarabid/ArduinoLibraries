#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  int distance = 25;

  for (int i = 0 ; i < 15 ; i ++) {
    /*
     * If conditions allow you to test for a situation.
     * For example, we can test how far we are through the 20 iterations
     * that are defined in this loop.
     *
     * The below if condition tests to see if i is equal to 10.
     * If it is, then we know we are halfway and we can display a message stating such.
     *
     * Notice that 2 equals signs means that we are testing for equality.
     * If it was one equal sign then we would instead be assigning the
     * value 10 to i (which might create an interesting drawing in itself!)
     */

     if ( i == 8) {
      pablo.message("  Half way! ");
     }

    pablo.turn_wheels_mm(distance, 50);
    distance = distance - 5;

  }

}