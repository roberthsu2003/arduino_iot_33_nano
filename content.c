#define VR A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println(vrValue(VR));
 delay(10);
}

int vrValue(byte pin){
  return analogRead(pin);
}
