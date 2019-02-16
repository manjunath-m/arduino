#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    300
#define BRIGHTNESS  120
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
//uint8_t brightness = 255;
#define UPDATES_PER_SECOND 100


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

  
void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
  
//  SetupBlackAndWhiteStripedPalette();
}

void loop() {

//  CRGB warmWhite = CRGB(255, 172, 68);
//    ChangePalettePeriodically();
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
FillLEDsFromPaletteColors2(startIndex, 0, 300, CRGB::Black ); 
FastLED.show();
//    FillLEDsFromPaletteColors2(startIndex, 0, 10, CRGB::Red);

    FillLEDsFromPaletteColors2(startIndex, 10, 25, CRGB::LightGoldenrodYellow);
delay(3000);
     FillLEDsFromPaletteColors2(startIndex, 20, 30, CRGB::Gold);
delay(3000);
FillLEDsFromPaletteColors2(startIndex, 0, 10, CRGB::Goldenrod);
delay(3000);
FillLEDsFromPaletteColors2(startIndex, 50, 60,  CRGB::Blue);
delay(3000);
FillLEDsFromPaletteColors2(startIndex, 30, 40, CRGB::PaleGoldenrod );
 
 
 
    
//    FillLEDsFromPaletteColors2(startIndex, 200, 300);
//    FillLEDsFromPaletteColors( startIndex);

//fill_solid( &(leds[10]), 1, CHSV( 224, 187, 255) );
  //fill_rainbow( &(leds[11]), 1, 222);
  FastLED.show();
//  FastLED.delay(1000 / UPDATES_PER_SECOND);
FillLEDsFromPaletteColors2(startIndex, 0, 300, CRGB::Black ); 

    for(int dot = 0; dot < NUM_LEDS; dot++) { 
//      fill_rainbow( &(leds[dot]), 1, 222);
//      int last = (NUM_LEDS - 1) - dot;
//            leds[dot] = CRGB::Blue;
//            leds[dot+1] = CRGB::HotPink;
//            leds[dot+2] = CRGB::Red;
//            FastLED.show();
//            // clear this led for the next time around the loop
//            leds[dot] = CRGB::Black;
////            leds[last] = CRGB::Black;
//            delay(10);
        }
        
}
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{   
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        colorIndex += 3;
    }
}

void FillLEDsFromPaletteColors2( uint8_t colorIndex, uint8_t startIndex, uint8_t endIndex, CRGB color)
{   
    for( int i = startIndex; i < endIndex; i++) {
//         fill_solid( &(leds[i]), 1, color );
        leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        colorIndex += 3;
    }
}
 

// Fill single led
// fill_solid( &(leds[i]), 1 /*number of leds*/, CRGB( 255, 68, 221) )
