
#include "Firebase_Arduino_WiFiNINA.h"
#include "DHT.h"

#define FIREBASE_HOST "arduinofirebase-6d104.firebaseio.com"
#define FIREBASE_AUTH "z5lPWwjZLZuNNcUEelbJdiNaIvnR2Zfq49BuQBAa"
#define WIFI_SSID "RobertIphone"
#define WIFI_PASSWORD "0926656000"
#define led 13
#define touchSensor 12
#define dhtData 11
//Define Firebase data object

FirebaseData firebaseData;
DHT dht(dhtData,DHT11);

bool currentState;
String path = "touchSensor/touch";

void setup()
{

  pinMode(led, OUTPUT);
  pinMode(touchSensor, INPUT);
  dht.begin();
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
  Serial.println("連線Firebase正常");
  currentState = digitalRead(touchSensor);
}



void loop()
{
  //touch
  bool state = digitalRead(touchSensor);
  Serial.println(currentState);
  if (state != currentState) {
    currentState = state;
    digitalWrite(led, state);
    Serial.println("上傳");
    if (Firebase.setBool(firebaseData, path, state)) {
      Serial.print("上傳成功");
    } else {
      Serial.print("Firebase存取失敗");
      Serial.print(firebaseData.errorReason());
    }
  }

  //dht11
  float t=dht.readTemperature();
  float h= dht.readHumidity();
  if(isnan(t) || isnan(h)){
    Serial.println("無法從DHT讀取資料");
  }else{
    Serial.println(t);
    Serial.println(h);
  }
  
  
  delay(1);
}
