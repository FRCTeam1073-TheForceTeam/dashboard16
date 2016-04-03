#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 36;

LPD8806 strip = LPD8806(nLEDs);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

uint32_t colors[] = {strip.Color(0, 0, 127), strip.Color(127, 127, 127), strip.Color(100, 20, 0)};

void loop() {
  // put your main code here, to run repeatedly:
  explode(50);
  carnival(colors, 3, 2);
  flow(0, 0, 127);
  flow(100, 20, 0);
  rainbowflow();
  randomcolor(0, 0, 0, 40, 0, 100, 10);
  randomcolor(0, 100, 0, 20, 0, 0, 10);
  explode(50);
  randomfizzle(100, 20, 0, true, 0);
  randomfizzle(0, 0, 127, true, 0);
  randomfizzle(100, 200, 0, true, 0);
  randomfizzle(0, 0, 127, true, 0);
  randomfizzle(100, 20, 0, true, 0);
  randomfizzle(0, 0, 127, true, 0);
  randomfizzle(100, 200, 0, true, 0);
  randomfizzle(0, 0, 127, true, 0);
  boom(0, 0, 127);
  boom(100, 20, 0);
}


void explode(int wait){
  uint32_t c = strip.Color(0,0,0);
  int interval = (int) 128/(strip.numPixels()/6)-1; //1/2 the strip, 3 colors, 128 values per color: 128values * 1/2 strip / 3 colors = 128/(strip/6) the "-1" accounts for rounding lost in integer counts
  
  for (int i = strip.numPixels()/2; i < strip.numPixels(); i++){
      strip.setPixelColor(i, strip.Color(100,100,100)); // Set new pixel 'on'
      strip.setPixelColor(strip.numPixels()-1-i, strip.Color(70,70,70)); // Set new pixel 'on'
      strip.show();              // Refresh LED states
      delay(2);
    }
  //for(int i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);
  for(int i = 0; i <= strip.numPixels()/2; i++){
    int colorFading = 0; // color fading from: 0 is red, 1 is blue, 2 is green
    int red = 127;
    int green = 0;
    int blue = 0;
    for(int j = strip.numPixels()/2 - i; j < strip.numPixels()/2; j++){
      if(colorFading == 0){
        red-=interval;
        blue+=interval;
        if(red < interval) colorFading++;
      }
      else if(colorFading == 1){
        blue-=interval;
        green+=interval;
        if(blue < interval) colorFading++;
      }
      else{
        green-=interval;
        if(green < interval) colorFading = 0;
      }
      c = strip.Color(red,green,blue);
      strip.setPixelColor(j,c);
      strip.setPixelColor(strip.numPixels()-j-1,c);
    }
    strip.show();
    delay(wait);
  }
  c = strip.Color(127,10,10);
  for (int i = strip.numPixels()/2; i >= 0; i--){
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.setPixelColor(strip.numPixels()-1-i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i+1, 0); // Erase pixel, but don't refresh!
    strip.setPixelColor(strip.numPixels()-2-i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }
}

void randomcolor(int r0, int r1, int g0, int g1, int b0, int b1, int iterations) {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int k = 0; k < iterations; k++) {
    for(int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(random(r0, r1), random(g0, g1), random(b0, b1)));
      strip.show();
    }
    delay(100);
  }
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


void carnival(uint32_t colors[], int numColors, int rotations) {
  
  boolean direct = true;
  int pixels = 0;
  if(strip.numPixels() % 2 == 0) {
    pixels = strip.numPixels();
  }
  else if(strip.numPixels() % 2 == 1) {
    pixels = strip.numPixels() + 1;
  }
  
  for(int i = 0; i < numColors * rotations; i++) {
    
    int c = i;
    while(c >= numColors) {
      c-=numColors;
    }
    
    if(direct == true) {
      for(int j = 0; j < pixels; j+=2) {
        strip.setPixelColor(j, colors[c]);
        strip.show();
        delay(50);
        direct = false;
      }
    }
    
    else {
      for(int k = pixels + 1; k > 0; k-=2) {
        strip.setPixelColor(k, colors[c]);
        strip.show();
        delay(50);
        direct = true;
      }
    }
    
  }
  
}


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
      strip.show(); delay(wait);
      r+=rInc; g+=gInc; b+=bInc;
    }
    
    for(int j = i + 9; j < i + 18; j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show(); delay(wait);
      r-=rInc; g-=gInc; b-=bInc;
    }
    
  }
  strip.show();
  delay(wait);
  
}

void randomfizzle(int r , int g, int b, boolean israndom, int getboom) {
  
  int boom = 0; //boom = 2 * (strip.numPixels() / 3);
  int boomdis = 0;
  
  if(israndom == false) {
    boom = getboom;
    boomdis = 10;
  }
  else if(israndom == true) {
    int side = random(0, 2);
    if(side == 0) {
      //boom = random((strip.numPixels() / 2) / 3, (2 * (strip.numPixels() / 2)) / 3);
      boom = random(6, 12);
    }
    else {
      //boom = random(((strip.numPixels() / 2) / 3) + ((strip.numPixels() / 2) / 6), strip.numPixels() - (strip.numPixels() / 2) / 6);
      boom = random(24, 30);
    }
    boomdis = 0;
  }
  
  //int boomdis = 0;
  
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

