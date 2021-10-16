#include <SPI.h>
#include <WiFiNINA.h>
#include "secret.h"
#define cds A0

char ssid[] = SSIDNAME; 
char pass[] = PASSWORD;
char server[] = "maker.ifttt.com";
bool sended = false;

int status = WL_IDLE_STATUS;
WiFiSSLClient client;

unsigned long triggerTime=0;

void setup() {
  
  Serial.begin(9600);
  while(!Serial);
  //如果連線的狀態，不是WL_CONNECTED，就繼續執行
  while(status != WL_CONNECTED){
    Serial.print("連線到SSID:");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(5000);
  }
  Serial.println("已經連線成功");
  
  /*  
  if(client.connect(server, 443)){
    client.println("GET /trigger/sendMail/with/key/eDqcZfqY_i_BHCZVXCwb6aq7GLPKpdV4q1ePja35Mjq?value1=30&value2=40 HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();
    Serial.println("傳送成功");
  }
  */
  
}

void loop() {      
  getCds();
  calculatTime();
}

void getCds(){
  int sensorValue = analogRead(cds);
  //Serial.println(sensorValue);
  if(sensorValue >= 997 && sended==false){
    sendMail(sensorValue);
  }
  
}

void calculatTime(){
  unsigned long currentTime = millis();
  if((currentTime - triggerTime) >= 10000){
    sended = false;
  }
}

void sendMail(int v1){
  Serial.println("發送line");
 if(client.connect(server, 443)){
    client.println("GET /trigger/over997/with/key/"+String(IFTTTKEY)+"?value1="+String(v1)+" HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();
    Serial.println("line傳送成功");
    sended = true;
    triggerTime = millis();
  }else{
    Serial.println("line發送失敗");
  }
}
