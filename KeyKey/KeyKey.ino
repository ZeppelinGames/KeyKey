#include "DigiKeyboard.h"

const int BTN = 1;
int lastPress = 0;
int currBtnState;
bool lastBtnState = LOW;

int currH1 = 0x00;
bool setH1 = false;
int currH2 = 0x00;

bool held = false;
int heldTime = 0;

void setup() {
  pinMode(BTN, INPUT);
}

void loop() {
  currBtnState = digitalRead(BTN);
  if (currBtnState != lastBtnState && millis() > lastPress + 50) {

    if (currBtnState == HIGH) {
      held = true;
      heldTime = millis();
    } else {
      held = false;
      if (millis() - heldTime > 200) {
        //held down
        DigiKeyboard.println("1");
      } else {
        //tapped
        DigiKeyboard.println("0");
      }
    }

    lastBtnState = currBtnState;
    lastPress = millis();
  }
}
