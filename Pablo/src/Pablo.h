#ifndef Pablo_h
#define Pablo_h

// #include "PabloPresets.h"
// Include libraries for the stepper motors
#include "PabloAccelStepper.h"

// Include libraries for drawing to the OLED screen
#include <U8g2lib.h>

// The old Motor shield
#include <AFMotor.h>

#include <SPI.h>
#include <Wire.h>

#define PABLO_V1 1
#define PABLO_V2 2

#define MOVEMENT_STILL 		0
#define MOVEMENT_FORWARDS 	1
#define MOVEMENT_ROTATING 	2
#define MOVEMENT_BACKWARDS 	3

class Pablo
{
  public:
    Pablo();
    Pablo(int motorShieldVersion);
    void init();
    void init(String botName, String botMessage);
    void init(String botName);
    void run();
    
    void turn_wheels_mm(float left, float right);
    void turn_wheels_mm(float distance_l, float distance_r, float top_speed);
    void set_wheels_mm(float distance_l, float distance_r,  float top_speed);
    void set_wheels_mm(float distance_l, float distance_r);
    bool wheels_still_turning();

    // UI control
    bool waitForStartButton();
    void readModeButton();

    void message(String text);
    void message(int number);
    void messageLarge(String);

    /* OBJECTS */
  	// Stepper motors 
  	PabloAccelStepper * stepper_r;
	PabloAccelStepper * stepper_l;

    // current index of drawingMode
	int drawingMode = 0;

  private:
  	/* FUNCTIONS */
  	void setupButtons();
  	void setupDisplay();
  	void setupMotors();
  	void enablePowerToMotors();
  	void disablePowerToMotors();

  	void report();
  	void displayStartMessage();
  	void displayCountDown(int number);
  	void captureSettings();

  	long distanceToSteps(float mm);
  	void stopAndResetSteppers();

  	void setupRotaryEncoder();
  	void readRotaryEncoders();
  	void cycleRotaryIncrement();

  	void default_mode();

  	/* OBJECTS */
	U8G2_SSD1306_128X64_NONAME_F_HW_I2C * OLEDScreen;

	/* VARIABLES */
	String _botName = "Pablo";
	String _botMessage = "Hello :)";

	// Forward or backward motion of the Artbot
	// Allows knowing whether acceletaration should be applied or not
	// 1 is forwards, 0 is backwards, 2 is twisting.
	int movement_direction = MOVEMENT_STILL;

	// Allows knowing if the steppers are currently activated or just waiting.
	boolean isDrawing = false;

	int _pabloVersion;

	long pablo_presets [10][4] = { 
		{1048, 40, 22, 203}, // start let centre, florette big.
		{99999, 40, 8, 133}, // spirograph, mid size
		{2100, 37, 22, 190}, // big sprawling, sta bottom middle
		{99999, 35, 20, 236},	 // big florette?
		{719, 40, 5, 314},
		{3200, 9, 30, 99999},
		{809, 6, 35, 45},
		{190, 34, 35, 40},
		{45, 2, 15, 40},
		{1534, 9, 32, 40}
	};

	// These are settings captured by the UI settings
	long setting_right_wheel_distance = 93;	// in mm
	long setting_right_wheel_speed = 25;	// arbitrary scale
	long setting_left_wheel_speed = 35;		// in mm
	long setting_left_wheel_distance = 100;	// arbitrary scale

	// Button pin positions.
	// Note: these are changed in init() ... as a function of whether or not
	// we are doing an old (AF_motor bot) or a new bot
	int buttonIncThousands;		// K0: 22
	int buttonIncHundreds = 23;		// K1: 23
	int buttonIncTens     = 24;		// K2: 24
	int buttonIncOnes	  = 25;	 	// K3: 25

	int buttonDrawingMode = 29;		// K4: 26
	int buttonUnused = 27;			// K5: 27
	int buttonPresets = 28;			// K6: 28
	int buttonStart = 26;			// K7: 29

	// toggle button states
	int buttonDrawingMode_state = 0;

	// Many values are required for the action of the rotary controllers
	int rotaryEncoder1_set_clkPin = 49;
	int rotaryEncoder1_set_dtPin = 47;
	int rotaryEncoder1_set_btnPin = 45;
	int rotaryEncoder1_read_clkPin;
	int rotaryEncoder1_read_dtPin;
	int rotaryEncoder1_previousRead_clkPin;

	// Determines which of the 4 displayed values that the Rotary controller will modify
	int rotaryMode = 0;
	// holds the increment amount that the rotary controller uses
	int rotary_increment = 1;
	// current index of preset array
	int preset_index = -1;
};

#endif

