#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    300
#define BRIGHTNESS  60
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
  
//  currentPalette = RainbowColors_p;
//  currentBlending = LINEARBLEND;
  
  SetupBlackAndWhiteStripedPalette();
}

void loop() {
//    ChangePalettePeriodically();
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */
    FillLEDsFromPaletteColors2(startIndex, 0, 100);
    FillLEDsFromPaletteColors2(startIndex, 200, 300);
//    FillLEDsFromPaletteColors( startIndex);

//fill_solid( &(leds[10]), 1, CHSV( 224, 187, 255) );
  //fill_rainbow( &(leds[11]), 1, 222);
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
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

void FillLEDsFromPaletteColors2( uint8_t colorIndex, uint8_t startIndex, uint8_t endIndex)
{   
    for( int i = startIndex; i < endIndex; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        colorIndex += 3;
    }
}

void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 20;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
//        if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = NOBLEND; }
//        if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
        if( secondHand == 0)  { SetupBlackAndWhiteStripedPalette();   currentBlending = LINEARBLEND;  }
//        if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
//        if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
//        if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
        //if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
        //if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
//        if( secondHand == 30)  { currentPalette = RainbowColors_p;       currentBlending = NOBLEND; }
//        if( secondHand == 35)  { currentPalette = RainbowColors_p;       currentBlending = LINEARBLEND; }
        
//        if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
//        if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
//        if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
//        if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
    }
}

void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Blue);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::Blue;
    currentPalette[4] = CRGB::Blue;
    currentPalette[8] = CRGB::Blue;
    currentPalette[12] = CRGB::Blue;
    
}


// Fill single led
// fill_solid( &(leds[i]), 1 /*number of leds*/, CRGB( 255, 68, 221) )
