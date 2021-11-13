#include "releaseButton.h"
#include <sound.h>
#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleTimer.h>

#define BUTTON 5
#define BUZZER 4
#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,2);
SimpleTimer timer;

unsigned int stateChangeCount = 0;
bool isOpen = false;
Sound sound(BUZZER);
int timerId;

void setup() {
  Serial.begin(9600);
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

    if(t > 24.0){
      alert();
    }
}

void alert(){
  static bool alertState = false;
  if(alertState == false){
    //執行alert動作
    alertState = true;    
    sound.melodySound();
    oneMinite(alertState);
    Serial.println(alertState);
  }
}

void oneMinite(bool alertState){
  delay(1000*30);
  alertState = false;
}
