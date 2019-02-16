#include <FastLED.h>

 
#define LED_PIN     12
int potPin = 14; 
#define NUM_LEDS    300
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
 
#define CLOCK_PIN 13
#define BRIGHTNESS 200
 
CRGB leds[NUM_LEDS];

void setup() { 
   
           delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
}

void loop() { 
  int ledsToUpdate = analogRead(potPin)/4;
  if(ledsToUpdate >= NUM_LEDS){
    ledsToUpdate = NUM_LEDS -1;
  }
  int ledIndex = analogRead(potPin)/4;
  //fillColor(CRGB::Chartreuse);
  CRGB color = CRGB::Chartreuse;
  //Goldenrod
  if(ledIndex > 50 && ledIndex < 80){
    color = CRGB::Chartreuse;
  } else if(ledIndex > 80 && ledIndex < 100) {
    color = CRGB::BlanchedAlmond;
  }else if(ledIndex > 100 && ledIndex < 140) {
    color = CRGB::DarkGreen;
  }else if(ledIndex > 140 && ledIndex < 180) {
    color = CRGB::DarkOrange;
  }else if(ledIndex > 180) {
    color = CRGB::DeepSkyBlue;
  }
    else{
    color = CRGB::Goldenrod;
  } 
  fillColor(color,0,ledIndex);
  FastLED.show();
  fillColor(CRGB::Black, 0,NUM_LEDS);
}

void fillColor(CRGB color, int start, int end){
  for(int i =start; i<end; i++){
    leds[i] = color;
  }
}
