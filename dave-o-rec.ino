#include "DigiKeyboard.h"

const int pinLED = 1;
const int pinBTN = 2;

int btnState = 0;
int lastbtnState = HIGH;

bool gameRecording = false;
int btnHeld = 0;
const int btnHeldMax = 3000;

void (* resetDigispark) (void) = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT); //onboard LED
  pinMode(pinBTN, INPUT_PULLUP); //button pin w/ pullup inline
  lastbtnState = digitalRead(pinBTN);
}

void loop() {
  // put your main code here, to run repeatedly:
  DigiKeyboard.update();
  btnState = digitalRead(pinBTN);
  if (btnState == LOW && btnState != lastbtnState) {
    btnHeld = 0;
    delay(10);
  }
  
  else if (btnState == LOW && btnState == lastbtnState) {
    btnHeld = btnHeld + 100;
    if (btnHeld > btnHeldMax) {
      resetBoard();
    } 
    delay(100);
  }

  else if (btnState == HIGH && btnState != lastbtnState) {
    digitalWrite(pinLED, HIGH);
    recGame();
  }
  
  else if (btnState == HIGH && btnState == lastbtnState && gameRecording == true) {
    digitalWrite(pinLED, LOW);  
    gameRecording == false;
  }

  lastbtnState = btnState;
  
}

void recGame() {
  DigiKeyboard.sendKeyStroke(KEY_G, MOD_ALT_LEFT | MOD_GUI_LEFT);
  gameRecording = true;
  DigiKeyboard.delay(5000);
  return;
}

void resetBoard() {
  for (int i = 0; i <= 5; i++) {
    digitalWrite(pinLED, HIGH);
    delay(100);
    digitalWrite(pinLED, LOW);
    delay(100);
  }

  resetDigispark();
    
}
