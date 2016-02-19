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
  pulse(0, 100, 0);
  pulse(100, 0, 0);
}

// inverse breathe
void pulse(int r, int g, int b) {
  
  int full = strip.numPixels();
  int rInc = r / 20;
  int gInc = g / 20;
  int bInc = b / 20;
  int wait = 50;
  
  uint32_t c = strip.Color(r, g, b);
  
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < full; j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r-=rInc;
    g-=gInc;
    b-=bInc;
    c = strip.Color(r, g, b);
  }
  
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < full; j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r+=rInc;
    g+=gInc;
    b+=bInc;
    c = strip.Color(r, g, b);
  }
  
}








