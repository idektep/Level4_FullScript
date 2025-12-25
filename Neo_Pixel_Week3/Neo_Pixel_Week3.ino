#include <VoiceRecognitionV3.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 6
#define PIN2 7
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(12, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
#if defined(__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  strip.begin();
  strip.setBrightness(50);
  strip.show();  // Initialize all pixels to 'off'
  strip2.begin();
  strip2.setBrightness(50);
  strip2.show();  // Initialize all pixels to 'off'
}
void loop() {



}
