#define dataPin 2
#define latchPin 3
#define clockPin 4

void setNumberCH595(byte n,byte latch,byte data,byte c){
  byte numbers[10] = {B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,B01111111,B01111011};
  digitalWrite(latch,LOW);
  shiftOut(data,c,LSBFIRST,numbers[n]);
  digitalWrite(latch,HIGH);
}

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  setNumberCH595(5,latchPin,dataPin,clockPin);
}

void loop() {
  // put your main code here, to run repeatedly:

}
