#define dataPin 2
#define latchPin 3
#define clockPin 4

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  digitalWrite(latchPin,LOW);
  byte number = B01111111;
  shiftOut(dataPin,clockPin,LSBFIRST,number);
  digitalWrite(latchPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
