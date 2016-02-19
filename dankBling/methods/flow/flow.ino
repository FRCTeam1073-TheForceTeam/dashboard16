#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 48;

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
  flow(0, 40, 100);
}

void flow(int r, int g, int b) {
  
  int wait = 50;
  int rInc = r / 10; int gInc = g / 10; int bInc = b / 10;
  r = rInc; g = gInc; b = bInc;
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  
  for(int i = 0; i < strip.numPixels(); i+=18) {
    
    for(int j = i; j < i + 9; j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
      r+=rInc;
      g+=gInc;
      b+=bInc;
    }
    
    for(int j = i + 9; j < i + 18; j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
      r-=rInc;
      g-=gInc;
      b-=bInc;
    }
    
  }
  strip.show();
  delay(wait);
  
}


