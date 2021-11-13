#include "releaseButton.h"
#include <sound.h>
#define BUTTON 5
#define BUZZER 4

unsigned int stateChangeCount = 0;
bool isOpen = false;
Sound sound(BUZZER);
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
}

void loop() {
  stateChangeCount += button_release(BUTTON);
  bool switchState = displayNum(stateChangeCount,1);
  //偵測switchState是1或0
  if(switchState){
    //1
    buttonOpen();
  }else{
    //0
    buttonClose();
  }
}

void buttonOpen(){
  if(isOpen == false){ //只會執行一次
    isOpen = true;
    Serial.println("開");
    /*
    digitalWrite(BUZZER,true);
    delay(1000);
    digitalWrite(BUZZER,false);
    */
    //tone(BUZZER,4978,1000);
    //sound.beep(1000);
    sound.phone();
  }  
}

void buttonClose(){
  if(isOpen == true){
    isOpen = false;
    Serial.println("關");
    /*
    digitalWrite(BUZZER,true);
    delay(1000);
    digitalWrite(BUZZER,false);
    */
    //tone(BUZZER,4978,1000);
     sound.phone();
  }  
}
