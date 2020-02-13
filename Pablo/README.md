## Pablo: A drawing machine for media artists

Pablo is an Arduino based drawing machine that has been designed for two purposes:
- to empower anyone who wishes to explore the aesthetic potential of computational drawing
- as a pedagogical platform to expose students to media, programming, hardware hacking, and aesthetics.

This library allows the user to drive Pablo by manipulating a hardware user interface (UI), but also to write code in the Arduino software development environment that can then drive the drawing machine.

The hardware UI has been designed to offer very a minimum of controls that offer a maximum of differrent patterns.

## Code Example

Pablo's basic command is `pablo.turn_wheels_mm(50, 100);` This command will result in the left wheel turning 50mm and the right wheel turning 100mm (this will create an arc).

A full example Arduino *.ino sketch wwill look something like this:

```cpp
#include <Pablo.h>

Pablo pablo;

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Display a message and wait for start button
  pablo.message("  Press Start");
  pablo.waitForStartButton();

  // Turn the left wheel 50mm, and the right wheel 100mm (this creates an arc)
  pablo.turn_wheels_mm(50, 100);

}
```

## Motivation

Pablo's design is intended to empower anyone interested in crossing the line between computational logic and aesthetics.

## Installation

Pablo can be installed using Arduino's library manager.

Alternatively, it can be downloaded and placed in the Arduino 'libraries' folder.

## API Reference

`turn_wheels_mm(float distance_left_wheel, float distance_right_wheel);`


## Contributors

Pablo is developed by Polygon Door, a creative media laboratory based in Australia.

## License

This software is Copyright (C) 2016 Polygon Door.
Use is subject to license conditions. The main licensing option available is GPL V2.

Open Source Licensing GPL V2
This is the appropriate option if you want to share the source code of your
application with everyone you distribute it to, and you also want to give them
the right to share who uses it. If you wish to use this software under Open
Source Licensing, you must contribute all your source code to the open source
community in accordance with the GPL Version 2 when your application is
distributed. See http://www.gnu.org/copyleft/gpl.html

Note: Pablo incorporates AccelStepper, Copyright (C) 2010 Mike McCauley