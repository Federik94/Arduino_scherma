#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"

#define SwitchPin 4

int SentMessage[1] = {000}; 
RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 7 and 8 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  Serial.begin(9600);
  pinMode(SwitchPin, INPUT_PULLUP); 
  digitalWrite(SwitchPin,HIGH); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); //  NRF24L01 è pronto a partire
}

void loop()
{
  if (digitalRead(SwitchPin) == LOW)    // Se il tasto è premuto
  { 
      SentMessage[0] = 111;
      radio.write(SentMessage, 1); // manda il dato al arduino ricevitore
      Serial.println("tasto premuto");
    delay(5);
  }
  else 
  {
      SentMessage[0] = 000;
      radio.write(SentMessage, 1);  // Sennò rimani in modalità idle
      
  }
}
