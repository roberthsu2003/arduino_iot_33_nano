#include "password.h"

#define BLYNK_PRINT Serial
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

#define VR A0

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = MY_PHONE_NAME;
char pass[] = MY_PHONE_NUMBER;

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100, myTimerEvent);
  timer.setInterval(1000,sendVRValue);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 Blynk.run();
 timer.run();
}

void myTimerEvent(){
  Serial.println(vrValue(VR));
}

int vrValue(byte pin){
  return analogRead(pin);
}


void sendVRValue(){
  short outputValue = vrValue(VR);
  byte myValue = map(outputValue,0,1023,0,100);
  Blynk.virtualWrite(V0, myValue);
}
