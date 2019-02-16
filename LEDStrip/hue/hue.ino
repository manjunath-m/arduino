#include <FastLED.h>

 
#define LED_PIN     12
int potPin = 14; 
#define NUM_LEDS    300
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
 
#define CLOCK_PIN 13
#define BRIGHTNESS 200
#define TWO_HUNDRED_PI 628

#define TWO_HUNDRED_PI 628
#define TWO_THIRDS_PI 2.094

#include "FastLED.h"
 
#define NUM_LEDS 22
#define DATA_PIN 5
#define TWO_HUNDRED_PI 628
#define TWO_THIRDS_PI 2.094
 
CRGB leds[NUM_LEDS];
 
int val1 = 0;
int val2 = 0;
int val3 = 0;
 
  
uint8_t hue[NUM_LEDS];
 int element = 0;
int last_element = 0;
 

void setup() { 
   
   delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

//  for(int i = 0; i< NUM_LEDS; i++){
//    hue[i] = 255/ NUM_LEDS * i;
//  }
  
}

void loop() { 
// for(int i=0; i<NUM_LEDS; i++){
//        leds[i] = CHSV(160, 255, 128);
//        FastLED.show();
//        delay(1);
//        leds[i] = CHSV(0,0,0);
//        FastLED.show();
//    }
 for(int i=0; i<TWO_HUNDRED_PI; i++){
        val1 = round(255/2.0*(sin(i/100.0)+1));
        val2 = round(255/2.0*(sin(i/100.0+TWO_THIRDS_PI)+1));
        val3 = round(255/2.0*(sin(i/100.0-TWO_THIRDS_PI)+1));
//leds[7] = CHSV(0, 255, val1);
//        leds[8] = CHSV(96, 255, val2);
//        leds[9] = CHSV(160, 255, val3);
     for(int j=0; j < NUM_LEDS - 3; j=j+2){
        leds[j] = CHSV(0, 255, val1);
        leds[j+1] = CHSV(96, 255, val2);
        leds[j+2] = CHSV(160, 255, val3);
     }
        FastLED.show();
     
//        delay(1);
    }
}

void fillColor(CRGB color, int start, int end){
  for(int i =start; i<end; i++){
    leds[i] = color;
  }
}
