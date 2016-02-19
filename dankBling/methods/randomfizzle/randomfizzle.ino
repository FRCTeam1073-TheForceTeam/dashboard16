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
  randomfizzle(100, 0, 0);
  randomfizzle(127, 127, 127);
  randomfizzle(0, 0, 100);
}

void randomfizzle(int r , int g, int b) {
  
  int boom = random((strip.numPixels() / 6), (5 * (strip.numPixels() / 6)));
  int boomdis = 0;
  
  int wait = 50;
  
  uint32_t w100 = strip.Color(r, g, b);
  uint32_t w90 = strip.Color((9 * (r / 10)), (9 * (g / 10)), (9 * (b / 10)));
  uint32_t w80 = strip.Color((8 * (r / 10)), (8 * (g / 10)), (8 * (b / 10)));
  uint32_t w70 = strip.Color((7 * (r / 10)), (7 * (g / 10)), (7 * (b / 10)));
  uint32_t w60 = strip.Color((6 * (r / 10)), (6 * (g / 10)), (6 * (b / 10)));
  uint32_t w50 = strip.Color((5 * (r / 10)), (5 * (g / 10)), (5 * (b / 10)));
  uint32_t w40 = strip.Color((4 * (r / 10)), (4 * (g / 10)), (4 * (b / 10)));
  uint32_t w30 = strip.Color((3 * (r / 10)), (3 * (g / 10)), (3 * (b / 10)));
  uint32_t w20 = strip.Color((2 * (r / 10)), (2 * (g / 10)), (2 * (b / 10)));
  uint32_t w10 = strip.Color((r / 10), (g / 10), (b / 10));
  uint32_t w5 = strip.Color((r / 20), (g / 20), (b / 20));
  
  
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

