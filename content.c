#define BLYNK_PRINT Serial
#include "secret.h"
#include "ch595.h"
#include "releaseButton.h"
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5
int count = 0; //計算按鈕狀態改變的次數
int displayNumberState;
int displayNumber;

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ID;
char pass[] = PASS;

void setup() {
  Serial.begin(9600); 
  displayNumberState = displayNum(count,9);
  setNumberCH595(0,latchPin,dataPin,clockPin);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000, myTimerEvent);
}

void loop() { 
    Blynk.run();
    timer.run();   
    count += button_release(button);    
    displayNumber = displayNum(count,9);
    if(displayNumber != displayNumberState){
       displayNumberState = displayNumber;
       setNumberCH595(displayNumber,latchPin,dataPin,clockPin);
       Serial.println(displayNumber);  
    }
    
}

void myTimerEvent(){
  Blynk.virtualWrite(V0,displayNumber);
}

secret.h

#define BLYNK_TEMPLATE_ID "w"
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN "wxOWym"

#define ID "rober"
#define PASS "092"



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
