#include "releaseButton.h"
#define BUTTON 5

unsigned int stateChangeCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  stateChangeCount += button_release(BUTTON);
  bool switchState = displayNum(stateChangeCount,1);
  Serial.println(switchState);
}
