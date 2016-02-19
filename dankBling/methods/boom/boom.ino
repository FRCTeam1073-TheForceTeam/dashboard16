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
  boom(0, 40, 100);
  boom(100, 20, 0);
}

void boom(int red, int green, int blue) {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  int r = red; int g = green; int b = blue;
  int rInc = r / 10; int gInc = g / 10; int bInc = b / 10;
  int wait = 50;
  
  uint32_t c = strip.Color(r, g, b);
  int count = 0;
  boolean up = false;
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    r = red; g = green; b = blue;
    c = strip.Color(r, g, b);
    
    for(int j = i; j >= 0; j--) {
      
      strip.setPixelColor((strip.numPixels() / 2) + j, c);
      strip.setPixelColor((strip.numPixels() / 2) - j, c);
      
      if(r >= red && g >= green && b >= blue) {
        up = false;
        r = red; g = green; b = blue;
      }
      else if(r <= (red / 10) && g <= (green / 10) && b <= (blue /10)) {
        up = true;
        r = (red / 10); g = (green / 10); b = (blue / 10);
      }
      
      if(up == false) {
        r-=rInc; g-=gInc; b-=bInc;
      }
      else if(up == true) {
        r+=rInc; g+=gInc; b+=bInc;
      }
      
      c = strip.Color(r, g, b);
      
    }
    strip.show();
    delay(wait);
    
  }
  
}



