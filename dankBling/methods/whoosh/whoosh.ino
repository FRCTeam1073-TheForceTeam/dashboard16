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
  whoosh(100, 20, 0, 0, 40, 100);
  //whoosh();
}


void whoosh(int r1, int g1, int b1, int r2, int g2, int b2) {

   
  uint32_t w100 = strip.Color(r1, g1, b1);
  uint32_t w90 = strip.Color((9 * (r1 / 10)), (9 * (g1 / 10)), (9 * (b1 / 10)));
  uint32_t w80 = strip.Color((8 * (r1 / 10)), (8 * (g1 / 10)), (8 * (b1 / 10)));
  uint32_t w70 = strip.Color((7 * (r1 / 10)), (7 * (g1 / 10)), (7 * (b1 / 10)));
  uint32_t w60 = strip.Color((6 * (r1 / 10)), (6 * (g1 / 10)), (6 * (b1 / 10)));
  uint32_t w50 = strip.Color((5 * (r1 / 10)), (5 * (g1 / 10)), (5 * (b1 / 10)));
  uint32_t w40 = strip.Color((4 * (r1 / 10)), (4 * (g1 / 10)), (4 * (b1 / 10)));
  uint32_t w30 = strip.Color((3 * (r1 / 10)), (3 * (g1 / 10)), (3 * (b1 / 10)));
  uint32_t w20 = strip.Color((2 * (r1 / 10)), (2 * (g1 / 10)), (2 * (b1 / 10)));
  uint32_t w10 = strip.Color((r1 / 10), (g1 / 10), (b1 / 10));
  uint32_t w5 = strip.Color((r1 / 20), (g1 / 20), (b1 / 20));
  
  uint32_t x100 = strip.Color(r2, g2, b2);
  uint32_t x90 = strip.Color((9 * (r2 / 10)), (9 * (g2 / 10)), (9 * (b2 / 10)));
  uint32_t x80 = strip.Color((8 * (r2 / 10)), (8 * (g2 / 10)), (8 * (b2 / 10)));
  uint32_t x70 = strip.Color((7 * (r2 / 10)), (7 * (g2 / 10)), (7 * (b2 / 10)));
  uint32_t x60 = strip.Color((6 * (r2 / 10)), (6 * (g2 / 10)), (6 * (b2 / 10)));
  uint32_t x50 = strip.Color((5 * (r2 / 10)), (5 * (g2 / 10)), (5 * (b2 / 10)));
  uint32_t x40 = strip.Color((4 * (r2 / 10)), (4 * (g2 / 10)), (4 * (b2 / 10)));
  uint32_t x30 = strip.Color((3 * (r2 / 10)), (3 * (g2 / 10)), (3 * (b2 / 10)));
  uint32_t x20 = strip.Color((2 * (r2 / 10)), (2 * (g2 / 10)), (2 * (b2 / 10)));
  uint32_t x10 = strip.Color((r2 / 10), (g2 / 10), (b2 / 10));
  uint32_t x5 = strip.Color((r2 / 20), (g2 / 20), (b2 / 20));
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    
    int halfstrip = strip.numPixels() / 2;
    
    if(i < halfstrip)
      strip.setPixelColor(i, w100);
    if(i - 1 < halfstrip)
      strip.setPixelColor(i - 1, w90);
    if(i - 2 < halfstrip)
      strip.setPixelColor(i - 2, w80);
    if(i - 3 < halfstrip)
      strip.setPixelColor(i - 3, w70);
    if(i - 4 < halfstrip)
      strip.setPixelColor(i - 4, w60);
    if(i - 5 < halfstrip)
      strip.setPixelColor(i - 5, w50);
    if(i - 6 < halfstrip)
      strip.setPixelColor(i - 6, w40);
    if(i - 7 < halfstrip)
      strip.setPixelColor(i - 7, w30);
    if(i - 8 < halfstrip)
      strip.setPixelColor(i - 8, w20);
    if(i - 9 < halfstrip)
      strip.setPixelColor(i - 9, w10);
    if(i - 10 < halfstrip)
      strip.setPixelColor(i - 10, 0);
    
    /*strip.setPixelColor(i, w100);
    strip.setPixelColor(i - 1, w90);
    strip.setPixelColor(i - 2, w80);
    strip.setPixelColor(i - 3, w70);
    strip.setPixelColor(i - 4, w60);
    strip.setPixelColor(i - 5, w50);
    strip.setPixelColor(i - 6, w40);
    strip.setPixelColor(i - 7, w30);
    strip.setPixelColor(i - 8, w20);
    strip.setPixelColor(i - 9, w10);
    strip.setPixelColor(i - 10, 0);*/
    
    if(strip.numPixels() - i > halfstrip)
      strip.setPixelColor(strip.numPixels() - i, x100);
    if(strip.numPixels() - (i + 1) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 1), x90);
    if(strip.numPixels() - (i + 2) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 2), x80);
    if(strip.numPixels() - (i + 3) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 3), x70);
    if(strip.numPixels() - (i + 4) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 4), x60);
    if(strip.numPixels() - (i + 5) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 5), x50);
    if(strip.numPixels() - (i + 6) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 6), x40);
    if(strip.numPixels() - (i + 7) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 7), x30);
    if(strip.numPixels() - (i + 8) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 8), x20);
    if(strip.numPixels() - (i + 9) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 9), x10);
    if(strip.numPixels() - (i + 10) > halfstrip)
      strip.setPixelColor(strip.numPixels() - (i + 10), 0);
    
    /*strip.setPixelColor(strip.numPixels() - i, x100);
    strip.setPixelColor(strip.numPixels() - (i + 1), x90);
    strip.setPixelColor(strip.numPixels() - (i + 2), x80);
    strip.setPixelColor(strip.numPixels() - (i + 3), x70);
    strip.setPixelColor(strip.numPixels() - (i + 4), x60);
    strip.setPixelColor(strip.numPixels() - (i + 5), x50);
    strip.setPixelColor(strip.numPixels() - (i + 6), x40);
    strip.setPixelColor(strip.numPixels() - (i + 7), x30);
    strip.setPixelColor(strip.numPixels() - (i + 8), x20);
    strip.setPixelColor(strip.numPixels() - (i + 9), x10);
    strip.setPixelColor(strip.numPixels() - (i + 10), 0);*/
    
    strip.show();
    delay(50);
    
  }
  
  strip.show();
  
}

/*
void whoosh() {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    
    uint32_t blue = strip.Color(0, 40, 100);
    uint32_t orange = strip.Color(100, 20, 0);
    
    strip.setPixelColor(i, blue);
    strip.setPixelColor(i - 1, strip.Color(0, 36, 90));
    strip.setPixelColor(i - 2, strip.Color(0, 32, 80));
    strip.setPixelColor(i - 3, strip.Color(0, 28, 70));
    strip.setPixelColor(i - 4, strip.Color(0, 24, 60));
    strip.setPixelColor(i - 5, strip.Color(0, 20, 50));
    strip.setPixelColor(i - 6, strip.Color(0, 16, 40));
    strip.setPixelColor(i - 7, strip.Color(0, 12, 30));
    strip.setPixelColor(i - 8, strip.Color(0, 8, 20));
    strip.setPixelColor(i - 9, strip.Color(0, 4, 10));
    strip.setPixelColor(i - 10, 0);
    
    strip.setPixelColor(strip.numPixels() - i, orange);
    strip.setPixelColor(strip.numPixels() - (i + 1), strip.Color(90, 18, 0));
    strip.setPixelColor(strip.numPixels() - (i + 2), strip.Color(80, 16, 0));
    strip.setPixelColor(strip.numPixels() - (i + 3), strip.Color(70, 14, 0));
    strip.setPixelColor(strip.numPixels() - (i + 4), strip.Color(60, 12, 0));
    strip.setPixelColor(strip.numPixels() - (i + 5), strip.Color(50, 10, 0));
    strip.setPixelColor(strip.numPixels() - (i + 6), strip.Color(40, 8, 0));
    strip.setPixelColor(strip.numPixels() - (i + 7), strip.Color(30, 6, 0));
    strip.setPixelColor(strip.numPixels() - (i + 8), strip.Color(20, 4, 0));
    strip.setPixelColor(strip.numPixels() - (i + 9), strip.Color(10, 2, 0));
    strip.setPixelColor(strip.numPixels() - (i + 10), 0);
    
    strip.show();
    
    strip.setPixelColor(i, 0);
    strip.setPixelColor(strip.numPixels() - i, 0);
    delay(50);
    
  }
  
  strip.show();
  
}
*/
