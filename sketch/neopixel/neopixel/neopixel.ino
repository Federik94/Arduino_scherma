#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
#include <avr/power.h> //controllo potenza neopixel
#endif

#define PIX 16 
#define PIN 6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel (PIX, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show();
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
  for (int i=0; i< PIX ; i++){
   pixels.setPixelColor(i, pixels.Color(255,0,0)); // Colore rosso
  }
  pixels.show();
  delay(1000);
  // put your main code here, to run repeatedly:

}
