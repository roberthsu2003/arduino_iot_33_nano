# 溫濕度感測_及時資料庫顯示
## 學習讓Arduino及時讀取資料,並讓網頁及時顯示溫濕度
### 線路圖
[![](dht11_bb.jpg)](led_control_bb.pdf)

### 實體線路圖
![](IMG_0411.jpg)

### Firebase建立專案,並建立及時資料庫節點
![](firebaseDatabase.jpg)

### 控制網站
https://arduinofirebase-6d104.web.app/
![QRCode](條碼.png)

### 及時資料庫LEDControl影片展示
[![](https://img.youtube.com/vi/gRjMzTIt6XU/1.jpg)](https://youtu.be/gRjMzTIt6XU)



```C++
// Firebase
// 使用arduino nano 33 iot

/*
 *連線Firebase realtimeDatabase
 *get節點資料
*/

//Example shows how to connect to Firebase RTDB and perform basic operation for set, get, push and update data to database
//Required WiFiNINA Library for Arduino from https://github.com/arduino-libraries/WiFiNINA

#include "Firebase_Arduino_WiFiNINA.h"

#define FIREBASE_HOST "arduinofirebase-6d104.firebaseio.com"
#define FIREBASE_AUTH "xxxxxxxxx"
#define WIFI_SSID "robert_hsu_home"
#define WIFI_PASSWORD "xxxxxx"
#define led 13
//Define Firebase data object
FirebaseData firebaseData;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  delay(100);
  Serial.println();

  Serial.print("Connecting to Wi-Fi");
  int status = WL_IDLE_STATUS;
  while (status != WL_CONNECTED)
  {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  //Provide the autntication data
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
}

 

void loop()
{
  String path = "ledControl/state";
  if(Firebase.getBool(firebaseData,path)){
     Serial.println("getNode");
     Serial.println(firebaseData.boolData());
     if(firebaseData.boolData()){
      digitalWrite(led,HIGH);
     }else{
      digitalWrite(led,LOW);
     }
  }else{
     Serial.println(firebaseData.errorReason());
  }  
  delay(500);
}
```

