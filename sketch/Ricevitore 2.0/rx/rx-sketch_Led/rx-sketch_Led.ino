#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"

#define LED_PIN 2

int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01
RF24 radio(7,8); // NRF24L01 SPI pins. Pin 7 e 8 

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{
  Serial.begin(9600);
  radio.begin(); // Start the NRF24L01
  
  radio.openReadingPipe(1,pipe); // Get NRF24L01 pronto a ricevere
  
  radio.startListening(); // Rimane in ascolto fino a che non riceve un dato dal arduino trasmettitore
  
  pinMode(LED_PIN, OUTPUT); 
}

void loop(void)
{
  while (radio.available())
  {
    radio.read(ReceivedMessage, 1); // Read information from the NRF24L01

    if (ReceivedMessage[0] == 111) // Se il dato è arrivato...
    {
      digitalWrite(LED_PIN, HIGH); // Accendi il led
      Serial.println("sono accesso");
      delay(3000);
    }
    else
    {
       digitalWrite(LED_PIN, LOW); // sennò rimani spento....
       Serial.println("sono spento");
       delay(3000);
    }
    delay(2);
   }
}
