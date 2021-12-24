#include "DigiKeyboard.h"

const int pinLED = 1;
const int pinBTN = 2;

int btnState = 0;
int lastbtnState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT); //onboard LED
  pinMode(pinBTN, INPUT_PULLUP); //button pin w/ pullup inline
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  btnState = digitalRead(pinBTN);
  if (btnState == LOW && btnState != lastbtnState) {
    digitalWrite(pinLED, HIGH);
    recGame();
  }

  else if (btnState == HIGH && btnState != lastbtnState) {
    digitalWrite(pinLED, LOW);
  }

  lastbtnState = btnState;
  
}

void recGame() {
  DigiKeyboard.sendKeyStroke(KEY_G, MOD_ALT_LEFT | MOD_GUI_LEFT);
  DigiKeyboard.delay(5000);
  return;
}
