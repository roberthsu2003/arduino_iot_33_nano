#include <BlynkSimpleWiFiNINA.h>
#define VR A0

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  timer.setInterval(100, myTimerEvent);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
 timer.run();
}

void myTimerEvent(){
  Serial.println(vrValue(VR));
}

int vrValue(byte pin){
  return analogRead(pin);
}
