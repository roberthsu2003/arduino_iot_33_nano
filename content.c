/*
 * SimpleTimer使用說明:https://playground.arduino.cc/Code/SimpleTimer/
*/
#include "secret.h"
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>
#include "releaseButton.h"
#include <sound.h>
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

#define BLYNK_PRINT Serial
#define BUTTON 5
#define BUZZER 4
#define DHTTYPE DHT11
#define DHTPIN 2
#define ALERT_TEMP 27

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,2);
SimpleTimer timer;
SimpleTimer timer60;

unsigned int stateChangeCount = 0;
bool isOpen = false;
Sound sound(BUZZER);
int timerId;

char auth[] = BLYNK_AUTH_TOKEN;

// wifi認證
char ssid[] = ID;
char pass[] = PASS;


void setup() {  
  Serial.begin(9600);
  while(!Serial);
  Blynk.begin(auth, ssid, pass);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("CLOSE!!");
  lcd.setCursor(2,1);
  lcd.print("Hollo! Arduino!");

  timerId = timer.setInterval(2000, workOfSecond);
  timer.disable(timerId);  
}

void loop() {
  timer.run();
  timer60.run();
  Blynk.run();
  stateChangeCount += button_release(BUTTON);
  bool switchState = displayNum(stateChangeCount,1);
  //偵測switchState是1或0
  if(switchState){
    //1
    buttonOpen();
  }else{
    //0
    buttonClose();
  }
}

void buttonOpen(){
  if(isOpen == false){ //只會執行一次
    isOpen = true;
    Serial.println("開");
    sound.phone();
    timer.enable(timerId);    
  }  
}

void buttonClose(){
  if(isOpen == true){
    isOpen = false;
    Serial.println("關");
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("CLOSE!!");     
    sound.phone();
    timer.disable(timerId);
  }  
}

void workOfSecond(){
  float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
    Serial.println("測試失敗");
      return;
    }
    //顯示到lcd
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("H:"+String(h)+" %");
    lcd.setCursor(0,1);
    lcd.print("T:"+String(t)+" C");

    //傳送到Blyker
    Blynk.virtualWrite(V0,t);
    Blynk.virtualWrite(V1,h);
    //溫度超過ALERT_TEMP溫度發出警告
    if(t > ALERT_TEMP){
      alert();
    }
}


int timerId60;
bool alertState = false;

void alert(){  //發出警告後60秒內不會再發出警告
    if(alertState == false){
        timerId60 = timer60.setTimeout(1000*60,caculateTime);  //setTimeout 60秒後，只執行一次
        alertState = true;
        Serial.println("alert");
        sound.melodySound();
    }
        
}

void caculateTime(){
  Serial.println("計時");  
  alertState = false;
}




secret.h

#define BLYNK_TEMPLATE_ID "kJA"
#define BLYNK_DEVICE_NAME "溫度溼度按鈕蜂鳴器警告"
#define BLYNK_AUTH_TOKEN "OwtKO19N1"
#define ID "ome"
#define PASS "09"
