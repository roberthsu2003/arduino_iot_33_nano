#include "releaseButton.h"
#include "sr104.h"
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
    int distance = getDistanceCM(TRIG_PIN,ECHO_PIN);
    Serial.println(distance);
  }
}

void buttonClose(){
  if(runOnce == true){ //只會執行一次
    runOnce = false;
    Serial.println("關閉");
  } 
}



sr104.h

#ifndef __SR104_H__
#define __SR104_H__
#define USECOND 58

#include <arduino.h>

int getDistanceCM(byte trigPin, byte echoPin){
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  unsigned long backTime = pulseIn(echoPin,HIGH);
  int distance = backTime / USECOND;
  return distance;
}

#endif


releaseButton.h
#ifndef __RELEASEBUTTON_H__
#define __RELEASEBUTTON_H__


int button_release(int buttonPin) { //傳出按鈕改變的次數
  pinMode(buttonPin, INPUT_PULLUP);
  static bool buttonState = digitalRead(buttonPin);
  bool currentButtonState = digitalRead(buttonPin);
  if (currentButtonState != buttonState) {
    delay(50); //解決彈跳
    if (currentButtonState != buttonState) {
      buttonState = currentButtonState;
      return 1;
    }
  }
  return 0;
}

int displayNum(int stateCount,int maxNum){ //stateCount是按鈕狀態改變的次數,maxNum是0~maxNum
    int i = stateCount / 2; 
    return i % (maxNum+1);    
}

#endif
