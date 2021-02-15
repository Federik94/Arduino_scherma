#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define led 2
RF24 radio(7, 8); // CE, CSN
const byte addresses[6] = "00001";
boolean buttonState = 0;

void setup() {
  pinMode(led, OUTPUT);
  
Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}

void loop() {
  delay(5);
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  if (buttonState == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("luce accesa....");
  }
  else {
    digitalWrite(led, LOW);
  }
}
