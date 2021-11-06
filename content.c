#include "releaseButton.h"
#define BUTTON 11
unsigned int stateChangeCount = 0;
bool runOnce = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  stateChangeCount += button_release(BUTTON);  
  bool switchState = displayNum(stateChangeCount,1);//得到0或1,0為關閉,1為開啟
  if(switchState){
    //開啟
    buttonOpen();
  }else{
    //關閉
    buttonClose();
  }
}

void buttonOpen(){
  if(runOnce == false){ //只會執行一次
    runOnce = true;
    Serial.println("Open");
  }
}

void buttonClose(){
  if(runOnce == true){ //只會執行一次
    runOnce = false;
    Serial.println("關閉");
  }
 
}
