/*
 * This example uses a loop to repeat several lines in a radial pattern.
 */
#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1
float d = 100.0; // this variable determines the distance of the each stem on the seed head

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Display a message and wait for start button
  pablo.message("  Press Start");
  pablo.waitForStartButton();

  pablo.message(" A Seed Head! ");
  // The below code gets called 20 times ... each time, the 3 lines get shorter.
  for (int i = 0; i < 20; i++) {
    // arc
    pablo.turn_wheels_mm(d/2, d);
    pablo.turn_wheels_mm(-d/2, -d);

    // straight line
    pablo.turn_wheels_mm(d, d);
    pablo.turn_wheels_mm(-d, -d);

    // arc in other direction
    pablo.turn_wheels_mm(d, d/2);
    pablo.turn_wheels_mm(-d, -d/2);

    // rotate a bit
    pablo.turn_wheels_mm(-40, 40);

    // reduce length of stem
    d = d * 0.98;
  }

}