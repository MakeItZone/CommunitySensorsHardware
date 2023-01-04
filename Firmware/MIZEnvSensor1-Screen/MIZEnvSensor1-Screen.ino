/*
 * Display test & discovery progam for MakeItZone's Environmental Sensors group.
 * Target platform is the Heltec ESP32 LoRa v2
*/

// Bring in pre-created pieces code that does a bunch of work for us (libraries)
#include <Wire.h> // i2c
#include <Adafruit_GFX.h> // generic (abstract) drawing functions
#include <Adafruit_SSD1306.h> // interface for our specific screen

// Constants for the OLED Screen
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define SCREEN_I2C_SDA 4
#define SCREEN_I2C_SCL 15
#define SCREEN_RESET 16
#define VEXT 21
#define SCREEN_ADDRESS 0x3C

// create instances of i2c interface and SSD1306 objects
TwoWire SCREENI2C = TwoWire(0);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SCREENI2C, SCREEN_RESET);

/*
 * ===============================================================
 * End of global declarations\
*/

void setup() {
  // put your setup code here, to run once:

  // Setup a serial port so we can send (and recieve) text to a monitoring computer.
  // This is a "virtual" serial port that is sent via USB.
  Serial.begin(9600);
  Serial.println("Starting up...");

  // Setup the screen

  // On the Heltec ESP32 LoRa v2 the power for the display can be turned off.
  // Turn on the screen
  pinMode(VEXT,OUTPUT);
	digitalWrite(VEXT, LOW);
  // and give a slight delay for it to initialize
  delay(100);

  // start communications with the screen
  SCREENI2C.begin(SCREEN_I2C_SDA, SCREEN_I2C_SCL, 100000);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Output a message to the programmers computer so we know the code is running
  Serial.println("run...");

  // wait a second before doing it all again
  delay(1000);
}
