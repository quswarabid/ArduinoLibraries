#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Display a message and wait for start button
  pablo.message("  Press Start");
  pablo.waitForStartButton();

  pablo.message(" An Arc! ");
  // Turn the left wheel 50mm, and the right wheel 100mm
  pablo.turn_wheels_mm(50, 100);

}