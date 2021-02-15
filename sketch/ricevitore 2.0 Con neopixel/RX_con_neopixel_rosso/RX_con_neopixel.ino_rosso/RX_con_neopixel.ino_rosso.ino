#include <Adafruit_NeoPixel.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"


#ifdef __AVR__
#include <avr/power.h> //controllo potenza neopixel
#endif

#define PIX 16 
#define PIN 6

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
      pixels.setPixelColor(16, pixels.Color(255,0,0)); // Colore rosso
      pixels.show();
      Serial.println("sono accesso");
      delay(3000);
    }
    else
    {
       pixels.setPixelColor(16, pixels.Color(0,0,0));
       pixels.show();
       Serial.println("sono spento");
    }
    delay(2);
   }
}
