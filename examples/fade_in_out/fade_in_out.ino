// fade_in_out.ino
//
// small demonstrator for ws2812_i2s library
// created by JoDa

#include <ws2812_i2s.h>

#define NUM_LEDS 100

static WS2812 ledstrip;
static Pixel_t pixels[NUM_LEDS];


void setup() 
{
  Serial.begin(115200);
  Serial.println("ws2812 i2s library demo sketch");
  
  ledstrip.init(NUM_LEDS);
}


void loop() 
{
  uint8_t i;
  static uint8_t c = 0;
  static uint8_t d = 1;

  for(i=0; i<NUM_LEDS; i++)
  {
    pixels[i].R = c;
    pixels[i].G = c;
    pixels[i].B = c;
  }

  c += d;
  if ( (c==255) || (c==0) ) d = -d;

  ledstrip.show(pixels);
  delay(10);

}

// end of file
