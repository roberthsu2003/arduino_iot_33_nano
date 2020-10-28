
#include "Firebase_Arduino_WiFiNINA.h"

#define FIREBASE_HOST "arduinofirebase-6d104.firebaseio.com"
#define FIREBASE_AUTH ""
#define WIFI_SSID "RobertIphone"
#define WIFI_PASSWORD "0926656000"
#define led 13
#define touchSensor 12

//Define Firebase data object
FirebaseData firebaseData;
bool currentState;

void setup()
{

  pinMode(led,OUTPUT);
  pinMode(touchSensor, INPUT);
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
 bool state = digitalRead(touchSensor);
 Serial.println(currentState);
 if(state != currentState){
   currentState = state;
   Serial.println("上傳");
 }
 delay(1000);
}
