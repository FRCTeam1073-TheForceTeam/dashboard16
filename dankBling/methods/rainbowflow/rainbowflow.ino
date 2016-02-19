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
  rainbowflow();
}

/*uint32_t red = strip.Color(100, 0, 0);
  uint32_t orange = strip.Color(100, 20, 0);
  uint32_t yellow = strip.Color(60, 20, 0);
  uint32_t green = strip.Color(0, 100, 0);
  uint32_t blue = strip.Color(0, 0, 100);
  uint32_t purple = strip.Color(60, 0, 100);*/
  
void rainbowflow() {
  
  int wait = 50;
  int r = 100; int g = 0; int b = 0;
  uint32_t c = strip.Color(r, g, b);
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    g+=1;
    c = strip.Color(r, g, b);
  }
  
  /*r = 100; g = 20; b = 0;
  c = strip.Color(r, g, b);*/
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r-=2;
    c = strip.Color(r, g, b);
  }
  
  /*r = 60; g = 20; b = 0;
  c = strip.Color(r, g, b);*/
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r-=3;
    g+=4;
    c = strip.Color(r, g, b);
  }
  
  /*r = 0; g = 100; b = 0;
  c = strip.Color(r, g, b);*/
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    g-=5;
    b+=5;
    c = strip.Color(r, g, b);
  }
  
  /*r = 0; g = 0; b = 100;
  c = strip.Color(r, g, b);*/
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r+=3;
    c = strip.Color(r, g, b);
  }
  
  /*r = 60; g = 0; b = 100;
  c = strip.Color(r, g, b);*/
  
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, c);
    }
    strip.show();
    delay(wait);
    r+=2;
    b-=5;
    c = strip.Color(r, g, b);
  }
  
  /*r = 100; g = 0; b = 0;
  c = strip.Color(r, g, b);*/
  
}



