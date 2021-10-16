#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = SSIDNAME; 
char pass[] = PASSWORD;

int status = WL_IDLE_STATUS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

//secret.h
#define SSIDNAME ""
#define PASSWORD ""
#define IFTTTKEY eDqPja35Mjq
