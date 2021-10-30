#include "ch595.h"
#include "releaseButton.h"
#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5
int count = 0; //計算按鈕狀態改變的次數
int displayNumberState;

void setup() {
  Serial.begin(9600); 
  displayNumberState = displayNum(count,9);
  setNumberCH595(0,latchPin,dataPin,clockPin);
}

void loop() {    
    count += button_release(button);    
    int displayNumber = displayNum(count,9);
    if(displayNumber != displayNumberState){
       displayNumberState = displayNumber;
       setNumberCH595(displayNumberState,latchPin,dataPin,clockPin);
       Serial.println(displayNumber);  
    }
    
}


ch595.h

#ifndef __CH595_H__
#define __CH595_H__
/*
 * setNumber(顯示的數字,latchPin,dataPin,clockPin)
*/
#include <arduino.h>
void setNumberCH595(byte n,byte latch,byte data,byte c){  
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(c, OUTPUT);
  byte numbers[10] = {B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,B01111111,B01111011};
  digitalWrite(latch,LOW);
  shiftOut(data,c,LSBFIRST,numbers[n]);
  digitalWrite(latch,HIGH);
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
