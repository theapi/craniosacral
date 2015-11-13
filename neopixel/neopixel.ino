/**
 * https://learn.adafruit.com/adafruit-neopixel-uberguide/overview
 */
 
// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.
#include <Adafruit_NeoPixel.h>

#define NUM_PIXELS 16
#define PIN_NEO 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN_NEO, NEO_GRB + NEO_KHZ800);



void setup() 
{
  strip.begin();
  
  for (byte n = 0; n < NUM_PIXELS; n++) {
    strip.setPixelColor(n, 0, 0, 0);
  }
  strip.show(); // Initialize all pixels to 'off'

}

void loop() 
{
  show_cri();
  show_midtide();
  show_longtide();
}

/**
 * 8 - 14 cycles per minute (11)
 * 
 * 11 * 16 = 176 pixels per minute
 * 176 / 60 = 2.93 pixels per second
 * 1000 / 2.933333 = 340.9
 * so an interval of 341
 */
void show_cri() {
  static unsigned long last = 0; 
  static long interval = 341; 
  
  unsigned long now = millis();
  if (now - last > interval) {
    last = now;    
    for (byte n = 0; n < NUM_PIXELS; n++) {
       strip.setPixelColor(n, 255, 0, 0);
    }
    strip.show();
  }
}

/**
 * 2 - 2.5 cycles per minute (2.25)
 * 
 * 2.25 * 16 = 36 pixels per minute
 * 36 / 60 = 0.6 pixels per second
 * 1000 / 0.6 = 1666.666
 * so an interval of 1667
 */
void show_midtide() {
  static unsigned long last = 0; 
  static long interval = 1667; 
  
  unsigned long now = millis();
  if (now - last > interval) {
    last = now;    
    for (byte n = 0; n < NUM_PIXELS; n++) {
       strip.setPixelColor(n, 0, 255, 0);
    }
    strip.show();
  }
}

/**
 * 100 seconds per cycle
 * 100 / 16 = 6.25 seconds per pixel
 * so an interval of 6250
 */
void show_longtide() {
  static unsigned long last = 0; 
  static long interval = 6250; 
  
  unsigned long now = millis();
  if (now - last > interval) {
    last = now;    
    for (byte n = 0; n < NUM_PIXELS; n++) {
       strip.setPixelColor(n, 0, 255, 0);
    }
    strip.show();
  }
}

