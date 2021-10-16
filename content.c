#include <SPI.h>
#include <WiFiNINA.h>
#include "secret.h"
#define cds A0

char ssid[] = SSIDNAME; 
char pass[] = PASSWORD;
char server[] = "maker.ifttt.com";

int status = WL_IDLE_STATUS;
WiFiSSLClient client;

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
  sendMail(30,40);
}

void loop() {      
  getCds();
}

void getCds(){
  int sensorValue = analogRead(cds);
  Serial.println(sensorValue);
  delay(1000);
}

void sendMail(int v1,int v2){
 if(client.connect(server, 443)){
    client.println("GET /trigger/sendMail/with/key/"+String(IFTTTKEY)+"?value1="+String(v1)+"&value2="+String(v2)+" HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();
    Serial.println("傳送成功");
  }
}


secret.h
#define SSIDNAME ""
#define PASSWORD ""
#define IFTTTKEY "eDqcZjq"
