#include <FastLED.h>

 
#define LED_PIN     12
#define NUM_LEDS    300
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
 
#define CLOCK_PIN 13
#define BRIGHTNESS 60
 
CRGB leds[NUM_LEDS];

void setup() { 
   
           delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
}

void loop() { 
  // Turn the LED on, then pause
  leds[0] = CRGB::Red;
  fillColor(CRGB::Red, 0,5);
  fillColor(CRGB::Goldenrod, 5,10);
  FastLED.show();
  delay(500);
   
  leds[0] = CRGB::Black;
fillColor(CRGB::Black, 0, NUM_LEDS);
  FastLED.show();
  delay(500);
}

void fillColor(CRGB color, int start, int end){
  for(int i =start; i<end; i++){
    leds[i] = color;
  }
}
