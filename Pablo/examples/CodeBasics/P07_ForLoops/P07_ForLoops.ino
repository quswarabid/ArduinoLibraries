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

  /* For loops are perhaps the most useful programming construct.
   * They allow you to repeat lines of code very easily.
   * They also allo you to change things during each repetition
   *
   * In the below example, the loop is run 10 times.
   *
   * Each time the loop runs an arc is drawn.
   * Each time the loop runs the left wheel travels less far, so the arc has a diferent radius.
   * The result is a spiral.
   */ 
  for (int i = 0 ; i < 15 ; i ++) {
    pablo.turn_wheels_mm(distance, 50);
    distance = distance - 5;
  }

}