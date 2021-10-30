#include "ch595.h"
#define dataPin 2
#define latchPin 3
#define clockPin 4

byte i = 0;

void setup() {  
}

void loop() {
  if(i >= 10) i = 0;  
  setNumberCH595(i,latchPin,dataPin,clockPin);
  i++;
  delay(1000);
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
