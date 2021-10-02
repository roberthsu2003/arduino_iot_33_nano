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
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("請更新Firmware");
  }

  while (status != WL_CONNECTED) {
    Serial.print("現在要連線的SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("連線成功");
  printWifiStatus();

  Serial.println("開始連線至google...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("連線到server");
    // Make a HTTP request:
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  }
  
  Serial.println("檢查完成");
}

void loop() {
  cds();
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

   if (!client.connected()) {
    Serial.println();
    Serial.println("停止連線至google");
    client.stop();

    // do nothing forevermore:
    while (true);
  }

  
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

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
