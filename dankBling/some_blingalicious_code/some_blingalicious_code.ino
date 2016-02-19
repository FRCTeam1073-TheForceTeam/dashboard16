#include "LPD8806.h"
#include "SPI.h"

int nLEDs = 128;

LPD8806 strip = LPD8806(nLEDs);
// GND-13-11

  // uint32_t max = strip.Color(127, 127, 127);
  /*uint32_t red = strip.Color(127, 0, 0);
  uint32_t orange = strip.Color(100, 20, 0);
  uint32_t yellow = strip.Color(60, 20, 0);
  uint32_t green = strip.Color(0, 127, 0);
  uint32_t blue = strip.Color(0, 0, 127);
  uint32_t purple = strip.Color(60, 0, 100);*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  test(0, 40, 100); 
  suchbling();
  breathe(0, 40, 100);
  helladankfirework(0, 40, 100);
  pulse(0, 120, 0);
  muchwow();
  randomfizzle(100, 0, 0, true);
  randomfizzle(127, 127, 127, true);
  randomfizzle(0, 0, 100, true);
  rainbowflow();
  boom(0, 100, 100);
  whoosh();
  randomcolor(0, 0, 0, 40, 0, 100, 10);
  randomcolor(0, 100, 0, 20, 0, 0, 10);
  whoosh2();
  test(100, 20, 0);
  test(0, 40, 100);
  test(100, 20, 0);
  test(0, 40, 100);
  explode(50);
  whitewhoosh();
  flow(0, 40, 100);
}

void test(int r, int g, int b) {
  uint32_t test = strip.Color(r, g, b);
  for(int pixel = 0; pixel < strip.numPixels(); pixel++) { 
    strip.setPixelColor(pixel, test);
  }
  strip.show();
  delay(500);
}

// random(low, high);
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


void muchwow() {
  
  uint32_t blue = strip.Color(0, 40, 100);
  uint32_t orange = strip.Color(100, 20, 0);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    
    strip.setPixelColor(i, blue);
    strip.setPixelColor(strip.numPixels() - i, orange);
    
    strip.show();
    
    strip.setPixelColor(i, 0);
    strip.setPixelColor(strip.numPixels() - i, 0);
    delay(50);
  }
  
  strip.show();
  
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



void whoosh2() {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = strip.numPixels() / 2; i >= 0; i--) {
    
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


void whitewhoosh() {
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < strip.numPixels() / 2; i++) {
    
    uint32_t white = strip.Color(120, 120, 120);
    
    strip.setPixelColor(i, white);
    strip.setPixelColor(i - 1, strip.Color(108, 108, 108));
    strip.setPixelColor(i - 2, strip.Color(96, 96, 96));
    strip.setPixelColor(i - 3, strip.Color(84, 84, 84));
    strip.setPixelColor(i - 4, strip.Color(72, 72, 72));
    strip.setPixelColor(i - 5, strip.Color(60, 60, 60));
    strip.setPixelColor(i - 6, strip.Color(48, 48, 48));
    strip.setPixelColor(i - 7, strip.Color(36, 36, 36));
    strip.setPixelColor(i - 8, strip.Color(24, 24, 24));
    strip.setPixelColor(i - 9, strip.Color(12, 12, 12));
    strip.setPixelColor(i - 10, 0);
    
    strip.setPixelColor(strip.numPixels() - i, white);
    strip.setPixelColor(strip.numPixels() - (i + 1), strip.Color(108, 108, 108));
    strip.setPixelColor(strip.numPixels() - (i + 2), strip.Color(96, 96, 96));
    strip.setPixelColor(strip.numPixels() - (i + 3), strip.Color(84, 84, 84));
    strip.setPixelColor(strip.numPixels() - (i + 4), strip.Color(72, 72, 72));
    strip.setPixelColor(strip.numPixels() - (i + 5), strip.Color(60, 60, 60));
    strip.setPixelColor(strip.numPixels() - (i + 6), strip.Color(48, 48, 48));
    strip.setPixelColor(strip.numPixels() - (i + 7), strip.Color(36, 36, 36));
    strip.setPixelColor(strip.numPixels() - (i + 8), strip.Color(24, 24, 24));
    strip.setPixelColor(strip.numPixels() - (i + 9), strip.Color(12, 12, 12));
    strip.setPixelColor(strip.numPixels() - (i + 10), 0);
    
    strip.show();
    
    strip.setPixelColor(i, 0);
    strip.setPixelColor(strip.numPixels() - i, 0);
    delay(50);
    
  }
  
  strip.show();
  
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = strip.numPixels() / 2; i >= 0; i--) {
    
    uint32_t white = strip.Color(120, 120, 120);
    
    strip.setPixelColor(i, white);
    strip.setPixelColor(i - 1, strip.Color(108, 108, 108));
    strip.setPixelColor(i - 2, strip.Color(96, 96, 96));
    strip.setPixelColor(i - 3, strip.Color(84, 84, 84));
    strip.setPixelColor(i - 4, strip.Color(72, 72, 72));
    strip.setPixelColor(i - 5, strip.Color(60, 60, 60));
    strip.setPixelColor(i - 6, strip.Color(48, 48, 48));
    strip.setPixelColor(i - 7, strip.Color(36, 36, 36));
    strip.setPixelColor(i - 8, strip.Color(24, 24, 24));
    strip.setPixelColor(i - 9, strip.Color(12, 12, 12));
    strip.setPixelColor(i - 10, 0);
    
    strip.setPixelColor(strip.numPixels() - i, white);
    strip.setPixelColor(strip.numPixels() - (i + 1), strip.Color(108, 108, 108));
    strip.setPixelColor(strip.numPixels() - (i + 2), strip.Color(96, 96, 96));
    strip.setPixelColor(strip.numPixels() - (i + 3), strip.Color(84, 84, 84));
    strip.setPixelColor(strip.numPixels() - (i + 4), strip.Color(72, 72, 72));
    strip.setPixelColor(strip.numPixels() - (i + 5), strip.Color(60, 60, 60));
    strip.setPixelColor(strip.numPixels() - (i + 6), strip.Color(48, 48, 48));
    strip.setPixelColor(strip.numPixels() - (i + 7), strip.Color(36, 36, 36));
    strip.setPixelColor(strip.numPixels() - (i + 8), strip.Color(24, 24, 24));
    strip.setPixelColor(strip.numPixels() - (i + 9), strip.Color(12, 12, 12));
    strip.setPixelColor(strip.numPixels() - (i + 10), 0);
    
    strip.show();
    
    strip.setPixelColor(i, 0);
    strip.setPixelColor(strip.numPixels() - i, 0);
    delay(50);
    
  }
  
  strip.show();
  
  
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


void someOtherBling() {
  
  uint32_t orange = strip.Color(0, 20, 100);
  uint32_t blue = strip.Color(100, 20, 0);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, orange);
    strip.setPixelColor(i - 1, blue);
    strip.show();
    strip.setPixelColor(i, orange);
    strip.setPixelColor(i - 1, blue);
    delay(50);
  }
  
  strip.show();
  
}

// Chase one dot down the full strip. Good for testing purposes.
void colorChase(uint32_t c, uint8_t wait) {
  int i;

  // Start by turning all pixels off:
  for(i = 0; i < strip.numPixels(); i++)
    strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }
  strip.show(); // Refresh to turn off last pixel
}

void wave2(int red, int green, int blue, int wait, boolean forward) {
  
  uint32_t c = strip.Color(0,0,0);
  for(int i = 0; i < (2 * strip.numPixels()) / 3; i++) 
    strip.setPixelColor(i, 0);

  int redIncrement = (int) (red + 1) / (strip.numPixels() / 2);
  int greenIncrement = (int) (green + 1) /(strip.numPixels() / 2);
  int blueIncrement = (int) (blue + 1) / (strip.numPixels() / 2);

  int increment = (int) 128 / (strip.numPixels() / 2);  // increment = 1
  boolean clearing = false;
  for(int i = 0; i < strip.numPixels(); i++)
    strip.setPixelColor(i, 0);

  for(int i = 0; i < strip.numPixels() + strip.numPixels() / 2; i++) {
    int r = red;
    int g = green;
    int b = blue;
    //if(i >= strip.numPixels() / 2)clearing = true;  // i >= 32
    if(i >= strip.numPixels() / 16)clearing = true;  // i >= 8
    for(int j = i; j >= 0; j--) {
      r-=redIncrement;
      g-=greenIncrement;
      b-=blueIncrement;

      c = strip.Color(r, g, b);

      if(forward){
        if(j < strip.numPixels()) strip.setPixelColor(j, c);
        if((j < strip.numPixels() && clearing && i + 1 >= strip.numPixels() / 2 + j)) strip.setPixelColor(j, 0);
      }
      //backwards wave
      else{
        if(j < strip.numPixels()) strip.setPixelColor(strip.numPixels() - j - 1, c);
        if((j < strip.numPixels() && clearing && i+1 >= strip.numPixels() / 2 + j)) strip.setPixelColor(strip.numPixels() - j - 1, 0);
      }
    }
    strip.show();
    delay(wait);
  }
}

// in - out
void breathe(int r, int g, int b) {
  
  int rInc = r / 10; int gInc = g / 10; int bInc = b / 10;
  r = 0; g = 0; b = 0;
  
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
    }
    strip.show();
    delay(50);
    r+=rInc; g+=gInc; b+=bInc;
  }
  
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(r, g, b));
    }
    strip.show();
    delay(50);
    r-=rInc; g-=gInc; b-=bInc;
  }
  
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


void helladankfirework(int r, int g, int b) {
  
  // shoot firework
  int boom = 2 * (strip.numPixels() / 3);
  int boomdis = 25;
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
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  
  for(int i = 0; i < boom + 10; i++) {
    
    if(i < boom)
      strip.setPixelColor(i, w100);
    if(i - 1 < boom)
      strip.setPixelColor(i - 1, w90);
    if(i - 2 < boom)
      strip.setPixelColor(i - 2, w80);
    if(1 - 3 < boom)
      strip.setPixelColor(i - 3, w70);
    if(i - 4 < boom)
      strip.setPixelColor(i - 4, w60);
    if(i - 5 < boom)
      strip.setPixelColor(i - 5, w50);
    if(i - 6 < boom)
      strip.setPixelColor(i - 6, w40);
    if(i - 7 < boom)
      strip.setPixelColor(i - 7, w30);
    if(i - 8 < boom)
      strip.setPixelColor(i - 8, w20);
    if(i - 9 < boom)
      strip.setPixelColor(i - 9, w10);
    if(i - 10 < boom)
      strip.setPixelColor(i - 10, 0);
      
    for(int j = boom; j < boom + 10; j++) {
      strip.setPixelColor(j, 0);
    }
    
    strip.show();
    delay(wait);
    
  }
  
  strip.show();
  
  strip.setPixelColor(boom, w100);
  
  strip.show();
  delay(50);
  
  strip.setPixelColor(boom - 1, w100);
  strip.setPixelColor(boom, w80);
  
  strip.setPixelColor(boom + 1, w100);
  
  strip.show();
  delay(50);
  
  strip.setPixelColor(boom - 2, w100);
  strip.setPixelColor(boom - 1, w80);
  strip.setPixelColor(boom, w60);
  
  strip.setPixelColor(boom + 2, w100);
  strip.setPixelColor(boom + 1, w80);
  
  strip.show();
  delay(50);
  
  strip.setPixelColor(boom - 3, w100);
  strip.setPixelColor(boom - 2, w80);
  strip.setPixelColor(boom - 1, w60);
  strip.setPixelColor(boom, w40);
  
  strip.setPixelColor(boom + 3, w100);
  strip.setPixelColor(boom + 2, w80);
  strip.setPixelColor(boom + 1, w60);
  
  strip.show();
  delay(50);
  
  strip.setPixelColor(boom - 4, w100);
  strip.setPixelColor(boom - 3, w80);
  strip.setPixelColor(boom - 2, w60);
  strip.setPixelColor(boom - 1, w40);
  strip.setPixelColor(boom, w20);
  
  strip.setPixelColor(boom + 4, w100);
  strip.setPixelColor(boom + 3, w80);
  strip.setPixelColor(boom + 2, w60);
  strip.setPixelColor(boom + 1, w40);
  
  strip.show();
  delay(50);
  
  strip.setPixelColor(boom - 5, w100);
  strip.setPixelColor(boom - 4, w80);
  strip.setPixelColor(boom - 3, w60);
  strip.setPixelColor(boom - 2, w40);
  strip.setPixelColor(boom - 1, w20);
  strip.setPixelColor(boom, 0);
  
  strip.setPixelColor(boom + 5, w100);
  strip.setPixelColor(boom + 4, w80);
  strip.setPixelColor(boom + 3, w60);
  strip.setPixelColor(boom + 2, w40);
  strip.setPixelColor(boom + 1, w20);
  
  strip.show();
  delay(50);
  
  for(int i = 6; i < boomdis; i++) {
    
    uint32_t white = strip.Color(120, 120, 120);
    
    // i is the greatest distance from boom and i is less than boomdis
    strip.setPixelColor(boom - i, w100);
    strip.setPixelColor(boom - (i - 1), w80);
    strip.setPixelColor(boom - (i - 2), w60);
    strip.setPixelColor(boom - (i - 3), w40);
    strip.setPixelColor(boom - (i - 4), w20);
    strip.setPixelColor(boom - (i - 5), 0);
     
    strip.setPixelColor(boom + i, w100);
    strip.setPixelColor(boom + (i - 1), w80);
    strip.setPixelColor(boom + (i - 2), w60);
    strip.setPixelColor(boom + (i - 3), w40);
    strip.setPixelColor(boom + (i - 4), w20);
    strip.setPixelColor(boom + (i - 5), 0);
    
    strip.show();
    delay(50);
    
    strip.setPixelColor(i, 0);
    strip.setPixelColor(strip.numPixels() - i, 0);
    
  }
  
  strip.show();
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis - 1), w80);
  strip.setPixelColor(boom - (boomdis - 2), w60);
  strip.setPixelColor(boom - (boomdis - 3), w40);
  strip.setPixelColor(boom - (boomdis - 4), 0);
     
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + (boomdis - 1), w80);
  strip.setPixelColor(boom + (boomdis - 2), w60);
  strip.setPixelColor(boom + (boomdis - 3), w40);
  strip.setPixelColor(boom + (boomdis - 4), 0);
  
  strip.setPixelColor(boom + boomdis, w100);
  
  strip.setPixelColor(boom - boomdis, w100);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis - 1), w80);
  strip.setPixelColor(boom - (boomdis - 2), w60);
  strip.setPixelColor(boom - (boomdis - 3), 0);
     
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + (boomdis - 1), w80);
  strip.setPixelColor(boom + (boomdis - 2), w60);
  strip.setPixelColor(boom + (boomdis - 3), 0);
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis - 1), w80);
  strip.setPixelColor(boom - (boomdis - 2), 0);
     
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + (boomdis - 1), w80);
  strip.setPixelColor(boom + (boomdis - 2), 0);
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w80);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w80);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis - 1), 0);
     
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + (boomdis - 1), 0);
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w80);
  strip.setPixelColor(boom + (boomdis + 4), w70);
  
  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w80);
  strip.setPixelColor(boom - (boomdis + 4), w70);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom - boomdis, 0);
  
  strip.setPixelColor(boom + boomdis, 0);
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w80);
  strip.setPixelColor(boom + (boomdis + 4), w70);
  strip.setPixelColor(boom - (boomdis + 5), w50);

  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w80);
  strip.setPixelColor(boom - (boomdis + 4), w70);
  strip.setPixelColor(boom - (boomdis + 5), w50);
  //strip.setPixelColor(boom - (boomdis + 6), w20);
  
  strip.show();
  delay(wait);
  
  strip.setPixelColor(boom + boomdis, w100);
  strip.setPixelColor(boom + boomdis + 1, w90);
  strip.setPixelColor(boom + boomdis + 2, w50);
  strip.setPixelColor(boom + boomdis + 3, w80);
  strip.setPixelColor(boom + (boomdis + 4), w70);
  strip.setPixelColor(boom - (boomdis + 5), w50);
  strip.setPixelColor(boom - (boomdis + 6), w20);

  strip.setPixelColor(boom - boomdis, w100);
  strip.setPixelColor(boom - (boomdis + 1), w90);
  strip.setPixelColor(boom - (boomdis + 2), w50);
  strip.setPixelColor(boom - (boomdis + 3), w80);
  strip.setPixelColor(boom - (boomdis + 4), w70);
  strip.setPixelColor(boom - (boomdis + 5), w50);
  strip.setPixelColor(boom - (boomdis + 6), w20);
  
  strip.show();
  delay(wait);
  
  for(int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  
  randomfizzle(r, g, b, false);
  
}

void randomfizzle(int r , int g, int b, boolean israndom) {
  
  int boom = 0; //boom = 2 * (strip.numPixels() / 3);
  int boomdis = 0;
  
  if(israndom == false) {
    boom = 2 * (strip.numPixels() / 3);
    boomdis = 25;
  }
  else if(israndom == true) {
    boom = random((strip.numPixels() / 6), (5 * (strip.numPixels() / 6)));
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



