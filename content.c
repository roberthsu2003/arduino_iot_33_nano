#include <SPI.h>
#include <WiFiNINA.h>
#include "secretData.h"

#define CDS A0
char ssid[] = SSIDNAME;
char pass[] = PASSWORD;
int status = WL_IDLE_STATUS;
char server[] = "www.google.com"; 
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("沒有這個網路模組wifinina");
  }
  Serial.println("檢查完成");
}

void loop() {
  cds();
}

void cds(){  
int sensorVal = analogRead(A0);
  //Serial.println(sensorVal);
  
  if(sensorVal > 700){
    //Serial.println("暗");
  }else if(sensorVal < 100){
    //Serial.println("亮");
  }else{
    //Serial.println("正常");
  }  
  delay(100);
}
