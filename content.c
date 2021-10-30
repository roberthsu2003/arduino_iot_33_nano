#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5
unsigned long switchCount = 0; //狀態改變的次數
int i = 0; //按下放開的次數
bool buttonState;

void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  buttonState = digitalRead(button);
}

void loop() {
  bool currentButtonState = digitalRead(button);
  if(currentButtonState != buttonState){
    delay(30); //解決彈跳
    if(currentButtonState != buttonState){
      buttonState = currentButtonState;
      switchCount++;
      if(switchCount % 2 == 0){
        i = switchCount / 2; 
        if(i==10){
          switchCount = 0;
          i = 0;     
        }
        Serial.println(i);      
      }      
    }    
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
