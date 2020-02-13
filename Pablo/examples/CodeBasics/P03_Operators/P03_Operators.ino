#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

int distance = 30;

void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  /* 
   * An operator is (largely) just a standard arithmetic operation.
   * '+', '-', '*', '/' are examples of typical operators.
   * See the below code, where Pablo is instructed to turn the wheels diferent amounts
   * by simply using operators with the 'distance' variable.
   *
   */
  pablo.turn_wheels_mm(distance * -1, distance + 40);

}