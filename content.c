#include <SPI.h>
#include <WiFiNINA.h>
#include "secret.h"

char ssid[] = SSIDNAME; 
char pass[] = PASSWORD;

int status = WL_IDLE_STATUS;

void setup() {
  
  Serial.begin(9600);
  while(!Serial);
  //如果連線的狀態，不是WL_CONNECTED，就繼續執行
  while(status != WL_CONNECTED){
    Serial.print("連線到SSID");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(5000);
  }

  Serial.println("已經連線成功");
}

void loop() {
  // put your main code here, to run repeatedly:

}
