// 使用IFTTT
// 使用arduino nano 33 iot

/*
  連線iftttt,evenName:over30
  和line連線
*/

#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include "data.h"

int status = WL_IDLE_STATUS;
char server[] = "maker.ifttt.com";
WiFiMulti WiFiMulti;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Waiting for WiFi to connect...");
  while ((WiFiMulti.run() != WL_CONNECTED)) {
    Serial.print(".");
  }
  Serial.println(" connected");

 
  //連線ifttt
  /*一開始就連線的測試
    if (client.connect(server, 443)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    client.println("GET /trigger/over30/with/key/eDqcZfqY_i_BHCZVXCwb6aq7GLPKpdV4q1ePja35Mjq?value1=30&value2=40 HTTP/1.1");
    client.println("Host: maker.ifttt.com");
    client.println("Connection: close");
    client.println();
    }
  */
}



void loop()
{
 WiFiClientSecure *client = new WiFiClientSecure;
 if(client){
  {
    HTTPClient https;
    if (https.begin(*client, "https://maker.ifttt.com/trigger/nighting/with/key/eDqcZfqY_i_BHCZVXCwb6aq7GLPKpdV4q1ePja35Mjq?value1=30&value2=40&value3=50")){
      https.end();
    }
  }

  delete client;
  
 }
 delay(1000000);
}
