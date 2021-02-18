#include <Adafruit_NeoPixel.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"


#ifdef __AVR__
#include <avr/power.h> //controllo potenza neopixel
#endif

#define PIX 12 //numero led
#define PIN 6  // 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel (PIX, PIN, NEO_GRB + NEO_KHZ800); // settaggio la neopixel
int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01
RF24 radio(7,8); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{
  Serial.begin(9600);
  radio.begin(); // Start the NRF24L01
  
  radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  
  radio.startListening(); // Rimane in ascolto fino a che non riceve un dato dal arduino trasmettitore
   
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.show();
  delay(1000);
}

void loop(void)
{
  while (radio.available())
  {
    radio.read(ReceivedMessage, 1); // Read information from the NRF24L01
    
    if (ReceivedMessage[0] == 111) // Indicates switch is pressed
    {
      pixels.setPixelColor(0, pixels.Color(255,0,0)); // Colore rosso 
      pixels.setPixelColor(1, pixels.Color(255,0,0)); // Colore rosso1
      pixels.setPixelColor(2, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(3, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(4, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(5, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(6, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(7, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(8, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(9, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(10, pixels.Color(255,0,0)); // Colore rosso
      pixels.setPixelColor(11, pixels.Color(255,0,0)); // Colore rosso // Colore rosso
      pixels.show();
      Serial.println("sono accesso");
      delay(2000);
    }
    else
    {
       pixels.setPixelColor(0, pixels.Color(0,0,0));
       pixels.setPixelColor(1, pixels.Color(0,0,0));
       pixels.setPixelColor(2, pixels.Color(0,0,0));
       pixels.setPixelColor(3, pixels.Color(0,0,0));
       pixels.setPixelColor(4, pixels.Color(0,0,0));
       pixels.setPixelColor(5, pixels.Color(0,0,0));
       pixels.setPixelColor(6, pixels.Color(0,0,0));
       pixels.setPixelColor(7, pixels.Color(0,0,0));
       pixels.setPixelColor(8, pixels.Color(0,0,0));
       pixels.setPixelColor(9, pixels.Color(0,0,0));
       pixels.setPixelColor(10, pixels.Color(0,0,0));
       pixels.setPixelColor(11, pixels.Color(0,0,0));
       pixels.show();
       Serial.println("sono spento");
       delay(5);
    }
    delay(2);
   }
}
