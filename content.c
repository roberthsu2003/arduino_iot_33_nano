#include "releaseButton.h"
#define BUTTON 11
unsigned int stateChangeCount = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  stateChangeCount += button_release(BUTTON);  
  bool switchState = displayNum(stateChangeCount,1);
  if(switchState){
    //開啟
    Serial.println("開啟");
  }else{
    //關閉
    Serial.println("關閉");
  }
}
