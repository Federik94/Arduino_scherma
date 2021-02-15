
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button 4

RF24 radio(7, 8); // CE, CSN
const byte addresses[6] = "00001";
boolean buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  radio.startListening();
  if ( radio.available()) {
    delay(5);
    radio.stopListening();
    buttonState = digitalRead(button);
    radio.write(&buttonState, sizeof(buttonState));
   
  }
}
