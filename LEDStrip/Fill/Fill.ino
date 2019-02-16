#include <FastLED.h>

 
#define LED_PIN     12
#define NUM_LEDS    300
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
 
#define CLOCK_PIN 13
#define BRIGHTNESS 60
 
CRGB leds[NUM_LEDS];
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void setup() { 
   
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
//  EVERY_N_SECONDS( 2 ) { nextPattern(); } // change patterns periodically
  
}

void loop() { 
fill_rainbow( leds, NUM_LEDS, gHue, 7);
delay(3000);   
fillColor(CRGB::Amethyst);
fillColor(CRGB::AntiqueWhite);
fillColor(CRGB::Aqua);
fillColor(CRGB::Aquamarine);
fillColor(CRGB::Azure);
fillColor(CRGB::Beige);
fillColor(CRGB::Bisque);
fillColor(CRGB::Black);
fillColor(CRGB::BlanchedAlmond);
fillColor(CRGB::Blue);
fillColor(CRGB::BlueViolet);
fillColor(CRGB::Brown);
fillColor(CRGB::BurlyWood);
fillColor(CRGB::CadetBlue);
fillColor(CRGB::Chartreuse);
fillColor(CRGB::Chocolate);
fillColor(CRGB::Coral);
fillColor(CRGB::CornflowerBlue);
fillColor(CRGB::Cornsilk);
fillColor(CRGB::Crimson);
fillColor(CRGB::Cyan);
fillColor(CRGB::DarkBlue);
fillColor(CRGB::DarkCyan);
fillColor(CRGB::DarkGoldenrod);
fillColor(CRGB::DarkGray);
fillColor(CRGB::DarkGreen);
fillColor(CRGB::DarkKhaki);
fillColor(CRGB::DarkMagenta);
fillColor(CRGB::DarkOliveGreen);
fillColor(CRGB::DarkOrange);
fillColor(CRGB::DarkOrchid);
fillColor(CRGB::DarkRed);
fillColor(CRGB::DarkSalmon);
fillColor(CRGB::DarkSeaGreen);
fillColor(CRGB::DarkSlateBlue);
fillColor(CRGB::DarkSlateGray);
fillColor(CRGB::DarkTurquoise);
fillColor(CRGB::DarkViolet);
fillColor(CRGB::DeepPink);
fillColor(CRGB::DeepSkyBlue);
fillColor(CRGB::DimGray);
fillColor(CRGB::DodgerBlue);
fillColor(CRGB::FireBrick);
fillColor(CRGB::FloralWhite);
fillColor(CRGB::ForestGreen);
fillColor(CRGB::Fuchsia);
fillColor(CRGB::Gainsboro);
fillColor(CRGB::GhostWhite);
fillColor(CRGB::Gold);
fillColor(CRGB::Goldenrod);
fillColor(CRGB::Gray);
fillColor(CRGB::Green);
fillColor(CRGB::GreenYellow);
fillColor(CRGB::Honeydew);
fillColor(CRGB::HotPink);
fillColor(CRGB::IndianRed);
fillColor(CRGB::Indigo);
fillColor(CRGB::Ivory);
fillColor(CRGB::Khaki);
fillColor(CRGB::Lavender);
fillColor(CRGB::LavenderBlush);
fillColor(CRGB::LawnGreen);
fillColor(CRGB::LemonChiffon);
fillColor(CRGB::LightBlue);
fillColor(CRGB::LightCoral);
fillColor(CRGB::LightCyan);
fillColor(CRGB::LightGoldenrodYellow);
fillColor(CRGB::LightGreen);
fillColor(CRGB::LightGrey);
fillColor(CRGB::LightPink);
fillColor(CRGB::LightSalmon);
fillColor(CRGB::LightSeaGreen);
fillColor(CRGB::LightSkyBlue);
fillColor(CRGB::LightSlateGray);
fillColor(CRGB::LightSteelBlue);
fillColor(CRGB::LightYellow);
fillColor(CRGB::Lime);
fillColor(CRGB::LimeGreen);
fillColor(CRGB::Linen);
fillColor(CRGB::Magenta);
fillColor(CRGB::Maroon);
fillColor(CRGB::MediumAquamarine);
fillColor(CRGB::MediumBlue);
fillColor(CRGB::MediumOrchid);
fillColor(CRGB::MediumPurple);
fillColor(CRGB::MediumSeaGreen);
fillColor(CRGB::MediumSlateBlue);
fillColor(CRGB::MediumSpringGreen);
fillColor(CRGB::MediumTurquoise);
fillColor(CRGB::MediumVioletRed);
fillColor(CRGB::MidnightBlue);
fillColor(CRGB::MintCream);
fillColor(CRGB::MistyRose);
fillColor(CRGB::Moccasin);
fillColor(CRGB::NavajoWhite);
fillColor(CRGB::Navy);
fillColor(CRGB::OldLace);
fillColor(CRGB::Olive);
fillColor(CRGB::OliveDrab);
fillColor(CRGB::Orange);
fillColor(CRGB::OrangeRed);
fillColor(CRGB::Orchid);
fillColor(CRGB::PaleGoldenrod);
fillColor(CRGB::PaleGreen);
fillColor(CRGB::PaleTurquoise);
fillColor(CRGB::PaleVioletRed);
fillColor(CRGB::PapayaWhip);
fillColor(CRGB::PeachPuff);
fillColor(CRGB::Peru);
fillColor(CRGB::Pink);
fillColor(CRGB::Plaid);
fillColor(CRGB::Plum);
fillColor(CRGB::PowderBlue);
fillColor(CRGB::Purple);
fillColor(CRGB::Red);
fillColor(CRGB::RosyBrown);
fillColor(CRGB::RoyalBlue);
fillColor(CRGB::SaddleBrown);
fillColor(CRGB::Salmon);
fillColor(CRGB::SandyBrown);
fillColor(CRGB::SeaGreen);
fillColor(CRGB::Seashell);
fillColor(CRGB::Sienna);
fillColor(CRGB::Silver);
fillColor(CRGB::SkyBlue);
fillColor(CRGB::SlateBlue);
fillColor(CRGB::SlateGray);
fillColor(CRGB::Snow);
fillColor(CRGB::SpringGreen);
fillColor(CRGB::SteelBlue);
fillColor(CRGB::Tan);
fillColor(CRGB::Teal);
fillColor(CRGB::Thistle);
fillColor(CRGB::Tomato);
fillColor(CRGB::Turquoise);
fillColor(CRGB::Violet);
fillColor(CRGB::Wheat);
fillColor(CRGB::White);
fillColor(CRGB::WhiteSmoke);
fillColor(CRGB::Yellow);
fillColor(CRGB::YellowGreen);
  
}

void fillColor(CRGB color){
  fill_solid( leds, NUM_LEDS, color);
  FastLED.show();
  delay(2000);
}
