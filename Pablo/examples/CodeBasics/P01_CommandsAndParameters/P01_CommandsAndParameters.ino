#include <Pablo.h>

Pablo pablo(PABLO_V2); //for version 1 3d chassis change V2 to V1

void setup() {
  pablo.init();
}

void loop() {
  /* 
   * Commands are words that the Arduino understands.
   * When a command is called, the Arduino executes those instructions
   **** All commands end with brackets like these: () *****
   * Some commands can only be executed on an object.
   * In the below line of code run() is a command that belongs just to the Pablo 
   * drawing machine. This command must therefore be run on Pablo.
   * The dot '.' lets you know that run() is being called on pablo.
   */
  pablo.run(); // <- run() is a command

  /*
   * Many commands take parameters. This means that some information must
   * be given to the command for it to do what it needs to do.
   * In the below code, for example, the command message() will write a message
   * to the pablo screen. BUT, it needs to be told what message to display.
   * As such we need to pass it a parameter. In this example we pass it
   * some text.
   * 
   */
  pablo.message("Hello, press start!");
  pablo.waitForStartButton(); // <- this command takes no parameters

  pablo.message(" You pressed start! ");

  /*
   * The basic command that is offered by Pablo is this line of code below.
   * It allows you to control how far each wheel can move.
   * This command takes 2 parameters: 
   * - How far to move the left wheel (in mm)
   * - How far to move the right wheel (in mm)
   */
  pablo.turn_wheels_mm(50, 100);

  delay(40000); // <- this command tells the Arduino to STOP (by delay-ing any more execution)
  // It takes one parameter, which is how long to stop in milliseconds.

}