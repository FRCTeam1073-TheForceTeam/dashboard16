#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 128;

LPD8806 strip = LPD8806(nLEDs);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  breathe(0, 40, 100);
  breathe(100, 20, 0);
}

// in - out
void breathe(int r, int g, int b) {
  
  int rInc = r / 20; int gInc = g / 20; int bInc = b / 20;
  r = 0; g = 0; b = 0;
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
    }
    strip.show();
    delay(50);
    r+=rInc; g+=gInc; b+=bInc;
  }
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
    }
    strip.show();
    delay(50);
    r-=rInc; g-=gInc; b-=bInc;
  }
  
}

