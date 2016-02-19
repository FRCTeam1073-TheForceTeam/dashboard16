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
  test(100, 20, 0, 10);
  test(0, 40, 100, 10);
}

void test(int r, int g, int b, int wait) {
  uint32_t test = strip.Color(r, g, b);
  for(int pixel = 0; pixel < strip.numPixels(); pixel++) { 
    strip.setPixelColor(pixel, test);
  }
  strip.show();
  delay(wait);
}
