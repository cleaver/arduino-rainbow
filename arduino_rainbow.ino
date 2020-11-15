#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN   13

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 24

#define HUE_STEP 512;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
int pixel = 0;
int red = 0;
int green = 0;
int blue = 0;
uint16_t hue = 0;
int saturation = 196;
int value = 255;
uint32_t rgbcolor = 0;

void setup() {
  strip.begin();
  strip.clear(); // Initialize all pixels to 'off'
  strip.setBrightness(10);
  randomSeed(analogRead(A0));

}

void loop() {
  rgbcolor = strip.ColorHSV(hue, saturation, value);
  strip.setPixelColor(pixel, rgbcolor);
  strip.show();

  pixel++;
  if (pixel >= LED_COUNT) {
    pixel = 0;
  }
  hue += HUE_STEP;
  
  delay(50);
}
