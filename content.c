#include "releaseButton.h"
#define BUTTON 11
#define TRIG_PIN 3
#define ECHO_PIN 4

unsigned int stateChangeCount = 0;
bool runOnce = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
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
    digitalWrite(TRIG_PIN,HIGH);
    delayMicroseconds(10);
    unsigned long backTime = pulseIn(ECHO_PIN,HIGH);
    Serial.println(backTime);
  }
}

void buttonClose(){
  if(runOnce == true){ //只會執行一次
    runOnce = false;
    Serial.println("關閉");
  }
 
}
