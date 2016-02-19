#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 128;

LPD8806 strip = LPD8806(nLEDs);
// GND-13-11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  randomcolor(0, 0, 0, 40, 0, 100, 10);
  randomcolor(0, 100, 0, 20, 0, 100, 10);
}

// random(low, high);
void randomcolor(int r0, int r1, int g0, int g1, int b0, int b1, int iterations) {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int k = 0; k < iterations; k++) {
    for(int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(random(r0, r1), random(g0, g1), random(b0, b1)));
      strip.show();
    }
    delay(100);
  }
}



