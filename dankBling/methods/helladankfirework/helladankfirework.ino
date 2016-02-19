#include "LPD8806.h"
#include "SPI.h"

int nLEDs =160;

LPD8806 strip = LPD8806(nLEDs); 


void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  helladankfirework();
}

void helladankfirework() {
  
  // shoot firework
  int boom = 2 * (strip.numPixels() / 3);
  int boomdis = 25;
  int wait = 50;
  
  uint32_t w100 = strip.Color(120, 120, 120);
  uint32_t w90 = strip.Color(108, 108, 108);
  uint32_t w80 = strip.Color(96, 96, 96);
  uint32_t w70 = strip.Color(84, 84, 84);
  uint32_t w60 = strip.Color(72, 72, 72);
  uint32_t w50 = strip.Color(60, 60, 60);
  uint32_t w40 = strip.Color(48, 48, 48);
  uint32_t w30 = strip.Color(36, 36, 36);
  uint32_t w20 = strip.Color(24, 24, 24);
  uint32_t w10 = strip.Color(12, 12, 12);
  uint32_t w5 = strip.Color(6, 6, 6);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  // shoot
  for(int i = 0; i < boom + 10; i++) {
    
    if(i < boom)
      strip.setPixelColor(i, w100);
    if(i - 1 < boom)
      strip.setPixelColor(i - 1, strip.Color(108, 108, 108));
    if(i - 2 < boom)
      strip.setPixelColor(i - 2, strip.Color(96, 96, 96));
    if(1 - 3 < boom)
      strip.setPixelColor(i - 3, strip.Color(84, 84, 84));
    if(i - 4 < boom)
      strip.setPixelColor(i - 4, strip.Color(72, 72, 72));
    if(i - 5 < boom)
      strip.setPixelColor(i - 5, strip.Color(60, 60, 60));
    if(i - 6 < boom)
      strip.setPixelColor(i - 6, strip.Color(48, 48, 48));
    if(i - 7 < boom)
      strip.setPixelColor(i - 7, strip.Color(36, 36, 36));
    if(i - 8 < boom)
      strip.setPixelColor(i - 8, strip.Color(24, 24, 24));
    if(i - 9 < boom)
      strip.setPixelColor(i - 9, strip.Color(12, 12, 12));
    if(i - 10 < boom)
      strip.setPixelColor(i - 10, 0);
      
    for(int j = boom; j < boom + 10; j++) {
      strip.setPixelColor(j, 0);
    }
    
    strip.show();
    delay(wait);
    
  }
  
  strip.show();
  
  for(int i = 0; i < boomdis + 8; i++) {    
    // i is the greatest distance from boom and i is less than boomdis
    if(i < boomdis) {
      strip.setPixelColor(boom - i, w100);
      strip.setPixelColor(boom + i, w100);
    }
    if(i - 1 < boomdis && i >= 0) {
      strip.setPixelColor(boom - (i - 1), strip.Color(96, 96, 96));
      strip.setPixelColor(boom + (i - 1), strip.Color(96, 96, 96));
    }
    if(i - 2 < boomdis && i >= 0) {
      strip.setPixelColor(boom - (i - 2), strip.Color(72, 72, 72));
      strip.setPixelColor(boom + (i - 2), strip.Color(72, 72, 72));
    }
    if(i - 3 < boomdis && i >= 0) {
      strip.setPixelColor(boom - (i - 3), strip.Color(48, 48, 48));
      strip.setPixelColor(boom + (i - 3), strip.Color(48, 48, 48));
    }
    if(i - 4 < boomdis && i >= 0) {
      strip.setPixelColor(boom - (i - 4), strip.Color(24, 24, 24));
      strip.setPixelColor(boom + (i - 4), strip.Color(24, 24, 24));
    }
    if(i - 5 < boomdis && i >= 0) {
      strip.setPixelColor(boom - (i - 5), w10);
      strip.setPixelColor(boom + (i - 5), w10);
    }
    
    // begin fizzle
    if(i - 1 >= boomdis) {
      strip.setPixelColor(boom + boomdis, w100);
      strip.setPixelColor(boom - boomdis, w100);
    }
    if(i - 2 >= boomdis) {
      strip.setPixelColor(boom + (boomdis + 1), w90);
      strip.setPixelColor(boom - (boomdis + 1), w90);
    }
    if(i - 3 >= boomdis) {
      strip.setPixelColor(boom + (boomdis + 2), w50);
      strip.setPixelColor(boom - (boomdis + 2), w50);
    }
    if(i - 4 >= boomdis) {
      strip.setPixelColor(boom + (boomdis + 2), w80);
      strip.setPixelColor(boom - (boomdis + 2), w80);
    }
    if(i - 5 >= boomdis) {
      strip.setPixelColor(boom + (boomdis + 2), w50);
      strip.setPixelColor(boom - (boomdis + 2), w50);
    }
    if(i - 6 >= boomdis) {
      strip.setPixelColor(boom + (boomdis + 2), w20);
      strip.setPixelColor(boom - (boomdis + 2), w20);
    }
    
    strip.show();
    delay(wait);
    
  }
  
  strip.show();
    
  fizzle();
  
}


void fizzle() {
  
  int boom = 2 * (strip.numPixels() / 3);
  int boomdis = 25;
  
  int wait = 50;
  
  uint32_t w100 = strip.Color(120, 120, 120);
  uint32_t w90 = strip.Color(108, 108, 108);
  uint32_t w80 = strip.Color(96, 96, 96);
  uint32_t w70 = strip.Color(84, 84, 84);
  uint32_t w60 = strip.Color(72, 72, 72);
  uint32_t w50 = strip.Color(60, 60, 60);
  uint32_t w40 = strip.Color(48, 48, 48);
  uint32_t w30 = strip.Color(36, 36, 36);
  uint32_t w20 = strip.Color(24, 24, 24);
  uint32_t w10 = strip.Color(12, 12, 12);
  uint32_t w5 = strip.Color(6, 6, 6);
  
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w80);
  strip.setPixelColor(boom + boomdis + 4, w70);
  strip.setPixelColor(boom + boomdis + 5, w50);
  strip.setPixelColor(boom + boomdis + 6, w20);
  strip.setPixelColor(boom + boomdis + 7, w40);
  strip.setPixelColor(boom + boomdis + 8, 0);
  strip.setPixelColor(boom + boomdis + 9, 0);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w80);
  strip.setPixelColor(boom - (boomdis + 4), w70);
  strip.setPixelColor(boom - (boomdis + 5), w50);
  strip.setPixelColor(boom - (boomdis + 6), w20);
  strip.setPixelColor(boom - (boomdis + 7), w40);
  strip.setPixelColor(boom - (boomdis + 8), 0);
  strip.setPixelColor(boom - (boomdis + 9), 0);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, w80);
  strip.setPixelColor(boom + boomdis + 1, w70);
  strip.setPixelColor(boom + boomdis + 2, w60);
  strip.setPixelColor(boom + boomdis + 3, w70);
  strip.setPixelColor(boom + boomdis + 4, w60);
  strip.setPixelColor(boom + boomdis + 5, w40);
  strip.setPixelColor(boom + boomdis + 6, 0);
  strip.setPixelColor(boom + boomdis + 7, w30);
  strip.setPixelColor(boom + boomdis + 8, w5);
  strip.setPixelColor(boom + boomdis + 9, 0);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, w80);
  strip.setPixelColor(boom - (boomdis + 1), w70);
  strip.setPixelColor(boom - (boomdis + 2), w60);
  strip.setPixelColor(boom - (boomdis + 3), w70);
  strip.setPixelColor(boom - (boomdis + 4), w60);
  strip.setPixelColor(boom - (boomdis + 5), w40);
  strip.setPixelColor(boom - (boomdis + 6), 0);
  strip.setPixelColor(boom - (boomdis + 7), w30);
  strip.setPixelColor(boom - (boomdis + 8), w5);
  strip.setPixelColor(boom - (boomdis + 9), 0);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, w60);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w60);
  strip.setPixelColor(boom + boomdis + 4, w50);
  strip.setPixelColor(boom + boomdis + 5, w30);
  strip.setPixelColor(boom + boomdis + 6, w5);
  strip.setPixelColor(boom + boomdis + 7, w40);
  strip.setPixelColor(boom + boomdis + 8, w10);
  strip.setPixelColor(boom + boomdis + 9, w5);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, w60);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w60);
  strip.setPixelColor(boom - (boomdis + 4), w50);
  strip.setPixelColor(boom - (boomdis + 5), w30);
  strip.setPixelColor(boom - (boomdis + 6), w5);
  strip.setPixelColor(boom - (boomdis + 7), w40);
  strip.setPixelColor(boom - (boomdis + 8), w10);
  strip.setPixelColor(boom - (boomdis + 9), w5);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  
  strip.setPixelColor(boom + boomdis, w30);
  strip.setPixelColor(boom + boomdis + 1, w60);
  strip.setPixelColor(boom + boomdis + 2, w40);
  strip.setPixelColor(boom + boomdis + 3, w50);
  strip.setPixelColor(boom + boomdis + 4, w40);
  strip.setPixelColor(boom + boomdis + 5, w50);
  strip.setPixelColor(boom + boomdis + 6, w10);
  strip.setPixelColor(boom + boomdis + 7, w30);
  strip.setPixelColor(boom + boomdis + 8, w20);
  strip.setPixelColor(boom + boomdis + 9, w10);
  strip.setPixelColor(boom + boomdis + 10, w5);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, w30);
  strip.setPixelColor(boom - (boomdis + 1), w60);
  strip.setPixelColor(boom - (boomdis + 2), w40);
  strip.setPixelColor(boom - (boomdis + 3), w50);
  strip.setPixelColor(boom - (boomdis + 4), w40);
  strip.setPixelColor(boom - (boomdis + 5), w50);
  strip.setPixelColor(boom - (boomdis + 6), w10);
  strip.setPixelColor(boom - (boomdis + 7), w30);
  strip.setPixelColor(boom - (boomdis + 8), w20);
  strip.setPixelColor(boom - (boomdis + 9), w10);
  strip.setPixelColor(boom - (boomdis + 10), w5);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, w30);
  strip.setPixelColor(boom + boomdis + 2, w30);
  strip.setPixelColor(boom + boomdis + 3, w60);
  strip.setPixelColor(boom + boomdis + 4, w20);
  strip.setPixelColor(boom + boomdis + 5, w10);
  strip.setPixelColor(boom + boomdis + 6, w5);
  strip.setPixelColor(boom + boomdis + 7, w30);
  strip.setPixelColor(boom + boomdis + 8, w30);
  strip.setPixelColor(boom + boomdis + 9, w20);
  strip.setPixelColor(boom + boomdis + 10, w10);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), w30);
  strip.setPixelColor(boom - (boomdis + 2), w30);
  strip.setPixelColor(boom - (boomdis + 3), w60);
  strip.setPixelColor(boom - (boomdis + 4), w20);
  strip.setPixelColor(boom - (boomdis + 5), w10);
  strip.setPixelColor(boom - (boomdis + 6), w5);
  strip.setPixelColor(boom - (boomdis + 7), w30);
  strip.setPixelColor(boom - (boomdis + 8), w30);
  strip.setPixelColor(boom - (boomdis + 9), w20);
  strip.setPixelColor(boom - (boomdis + 10), w10);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, w5);
  strip.setPixelColor(boom + boomdis + 2, w20);
  strip.setPixelColor(boom + boomdis + 3, w70);
  strip.setPixelColor(boom + boomdis + 4, w5);
  strip.setPixelColor(boom + boomdis + 5, w20);
  strip.setPixelColor(boom + boomdis + 6, w10);
  strip.setPixelColor(boom + boomdis + 7, w20);
  strip.setPixelColor(boom + boomdis + 8, w5);
  strip.setPixelColor(boom + boomdis + 9, w30);
  strip.setPixelColor(boom + boomdis + 10, w40);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), w5);
  strip.setPixelColor(boom - (boomdis + 2), w20);
  strip.setPixelColor(boom - (boomdis + 3), w70);
  strip.setPixelColor(boom - (boomdis + 4), w5);
  strip.setPixelColor(boom - (boomdis + 5), w20);
  strip.setPixelColor(boom - (boomdis + 6), w10);
  strip.setPixelColor(boom - (boomdis + 7), w20);
  strip.setPixelColor(boom - (boomdis + 8), w5);
  strip.setPixelColor(boom - (boomdis + 9), w30);
  strip.setPixelColor(boom - (boomdis + 10), w40);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, 0);
  strip.setPixelColor(boom + boomdis + 2, w5);
  strip.setPixelColor(boom + boomdis + 3, w40);
  strip.setPixelColor(boom + boomdis + 4, w10);
  strip.setPixelColor(boom + boomdis + 5, w5);
  strip.setPixelColor(boom + boomdis + 6, w10);
  strip.setPixelColor(boom + boomdis + 7, w30);
  strip.setPixelColor(boom + boomdis + 8, 0);
  strip.setPixelColor(boom + boomdis + 9, w20);
  strip.setPixelColor(boom + boomdis + 10, w10);
  strip.setPixelColor(boom + boomdis + 11, w5);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), 0);
  strip.setPixelColor(boom - (boomdis + 2), w5);
  strip.setPixelColor(boom - (boomdis + 3), w40);
  strip.setPixelColor(boom - (boomdis + 4), w10);
  strip.setPixelColor(boom - (boomdis + 5), w5);
  strip.setPixelColor(boom - (boomdis + 6), w10);
  strip.setPixelColor(boom - (boomdis + 7), w30);
  strip.setPixelColor(boom - (boomdis + 8), 0);
  strip.setPixelColor(boom - (boomdis + 9), w20);
  strip.setPixelColor(boom - (boomdis + 10), w10);
  strip.setPixelColor(boom - (boomdis + 11), w5);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, 0);
  strip.setPixelColor(boom + boomdis + 2, 0);
  strip.setPixelColor(boom + boomdis + 3, w20);
  strip.setPixelColor(boom + boomdis + 4, w5);
  strip.setPixelColor(boom + boomdis + 5, 0);
  strip.setPixelColor(boom + boomdis + 6, w5);
  strip.setPixelColor(boom + boomdis + 7, w10);
  strip.setPixelColor(boom + boomdis + 8, w5);
  strip.setPixelColor(boom + boomdis + 9, w10);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, w10);
  strip.setPixelColor(boom + boomdis + 12, w5);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), 0);
  strip.setPixelColor(boom - (boomdis + 2), 0);
  strip.setPixelColor(boom - (boomdis + 3), w20);
  strip.setPixelColor(boom - (boomdis + 4), w5);
  strip.setPixelColor(boom - (boomdis + 5), 0);
  strip.setPixelColor(boom - (boomdis + 6), w5);
  strip.setPixelColor(boom - (boomdis + 7), w10);
  strip.setPixelColor(boom - (boomdis + 8), w5);
  strip.setPixelColor(boom - (boomdis + 9), w10);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), w10);
  strip.setPixelColor(boom - (boomdis + 12), w5);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, 0);
  strip.setPixelColor(boom + boomdis + 2, 0);
  strip.setPixelColor(boom + boomdis + 3, 0);
  strip.setPixelColor(boom + boomdis + 4, w10);
  strip.setPixelColor(boom + boomdis + 5, 0);
  strip.setPixelColor(boom + boomdis + 6, 0);
  strip.setPixelColor(boom + boomdis + 7, w5);
  strip.setPixelColor(boom + boomdis + 8, 0);
  strip.setPixelColor(boom + boomdis + 9, w5);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, w5);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, w5);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), 0);
  strip.setPixelColor(boom - (boomdis + 2), 0);
  strip.setPixelColor(boom - (boomdis + 3), 0);
  strip.setPixelColor(boom - (boomdis + 4), w10);
  strip.setPixelColor(boom - (boomdis + 5), 0);
  strip.setPixelColor(boom - (boomdis + 6), 0);
  strip.setPixelColor(boom - (boomdis + 7), w5);
  strip.setPixelColor(boom - (boomdis + 8), 0);
  strip.setPixelColor(boom - (boomdis + 9), w5);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), w5);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), w5);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, 0);
  strip.setPixelColor(boom + boomdis + 2, 0);
  strip.setPixelColor(boom + boomdis + 3, 0);
  strip.setPixelColor(boom + boomdis + 4, 0);
  strip.setPixelColor(boom + boomdis + 5, w5);
  strip.setPixelColor(boom + boomdis + 6, 0);
  strip.setPixelColor(boom + boomdis + 7, 0);
  strip.setPixelColor(boom + boomdis + 8, w5);
  strip.setPixelColor(boom + boomdis + 9, 0);
  strip.setPixelColor(boom + boomdis + 10, w5);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, w5);
  strip.setPixelColor(boom + boomdis + 15, 0);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), 0);
  strip.setPixelColor(boom - (boomdis + 2), 0);
  strip.setPixelColor(boom - (boomdis + 3), 0);
  strip.setPixelColor(boom - (boomdis + 4), 0);
  strip.setPixelColor(boom - (boomdis + 5), w5);
  strip.setPixelColor(boom - (boomdis + 6), 0);
  strip.setPixelColor(boom - (boomdis + 7), 0);
  strip.setPixelColor(boom - (boomdis + 8), w5);
  strip.setPixelColor(boom - (boomdis + 9), 0);
  strip.setPixelColor(boom - (boomdis + 10), w5);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), w5);
  strip.setPixelColor(boom - (boomdis + 15), 0);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, 0);
  strip.setPixelColor(boom + boomdis + 1, 0);
  strip.setPixelColor(boom + boomdis + 2, 0);
  strip.setPixelColor(boom + boomdis + 3, 0);
  strip.setPixelColor(boom + boomdis + 4, 0);
  strip.setPixelColor(boom + boomdis + 5, 0);
  strip.setPixelColor(boom + boomdis + 6, 0);
  strip.setPixelColor(boom + boomdis + 7, 0);
  strip.setPixelColor(boom + boomdis + 8, 0);
  strip.setPixelColor(boom + boomdis + 9, w5);
  strip.setPixelColor(boom + boomdis + 10, 0);
  strip.setPixelColor(boom + boomdis + 11, 0);
  strip.setPixelColor(boom + boomdis + 12, 0);
  strip.setPixelColor(boom + boomdis + 13, 0);
  strip.setPixelColor(boom + boomdis + 14, 0);
  strip.setPixelColor(boom + boomdis + 15, w5);
  
  strip.setPixelColor(boom - boomdis, 0);
  strip.setPixelColor(boom - (boomdis + 1), 0);
  strip.setPixelColor(boom - (boomdis + 2), 0);
  strip.setPixelColor(boom - (boomdis + 3), 0);
  strip.setPixelColor(boom - (boomdis + 4), 0);
  strip.setPixelColor(boom - (boomdis + 5), 0);
  strip.setPixelColor(boom - (boomdis + 6), 0);
  strip.setPixelColor(boom - (boomdis + 7), 0);
  strip.setPixelColor(boom - (boomdis + 8), 0);
  strip.setPixelColor(boom - (boomdis + 9), w5);
  strip.setPixelColor(boom - (boomdis + 10), 0);
  strip.setPixelColor(boom - (boomdis + 11), 0);
  strip.setPixelColor(boom - (boomdis + 12), 0);
  strip.setPixelColor(boom - (boomdis + 13), 0);
  strip.setPixelColor(boom - (boomdis + 14), 0);
  strip.setPixelColor(boom - (boomdis + 15), w5);
  
  strip.show();
  delay(wait);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  strip.show();
  
}


