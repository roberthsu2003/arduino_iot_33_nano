#include <sound.h>
#define BUZZER 4
#define BTN 8

Sound s(BUZZER);

void setup()
{
  Serial.begin(9600);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  bool btnValue = digitalRead(BTN);
  if(btnValue==0){
    Serial.println("press");
    sound();
  }
  delay(100);
}

void sound(){
  s.melodySound();
}
