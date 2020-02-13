#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

int distance = 30;
  /*
   * The variable 'distance' (see above) is an Integer, a whole number.
   * But variables can be different types.
   * The variable below, 'text' is of the type that can hold words.
   * This type is called a 'string'.
   */

String text = "YOLO!";

void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  /*
   * Here, the message 'text' is sent to the screen
   */
  pablo.message(text);

  delay(10000); // make sure that the text is displayed long enought that we can see it!

}