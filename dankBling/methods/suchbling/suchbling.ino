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
  suchbling();
}


void suchbling() {
  
  int rb = 100;
  int gb = 20;
  int bb = 0;
  uint32_t blue = strip.Color(rb, gb, bb);
  
  int ro = 0;
  int go = 20;
  int bo = 100;
  uint32_t orange = strip.Color(ro, go, bo);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  //int cycle = 0;
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    
    strip.setPixelColor(i, blue);
    rb-=5;
    gb--;
    blue = strip.Color(rb, gb, bb);
    
    strip.setPixelColor(i - 1, blue);
    rb-=5;
    gb--;
    blue = strip.Color(rb, gb, bb);
    
    strip.setPixelColor(i - 2, blue);
    rb-=5;
    gb--;
    blue = strip.Color(rb, gb, bb);
    
    strip.setPixelColor(i - 3, blue);
    rb-=5;
    gb--;
    blue = strip.Color(rb, gb, bb);
    
    strip.setPixelColor(i - 4, blue);
    
    
    strip.setPixelColor(strip.numPixels() - i, orange);
    go--;
    bo-=5;
    orange = strip.Color(ro, go, bo);
    
    strip.setPixelColor(strip.numPixels() - (i - 1), orange);
    go--;
    bo-=5;
    orange = strip.Color(ro, go, bo);
    
    strip.setPixelColor(strip.numPixels() - (i - 2), orange);
    go--;
    bo-=5;
    orange = strip.Color(ro, go, bo);
    
    strip.setPixelColor(strip.numPixels() - (i - 3), orange);
    go--;
    bo-=5;
    orange = strip.Color(ro, go, bo);
    
    strip.setPixelColor(strip.numPixels() - (i - 4), orange);
    
    strip.show();
    
    strip.setPixelColor(i - 5, 0);
    strip.setPixelColor(strip.numPixels() - (i - 5), 0);
    delay(50);
  }
  
  strip.show();
  
}


