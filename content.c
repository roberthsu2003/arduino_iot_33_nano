#define LIGHTS 36
#define LED 23

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightsValue = analogRead(LIGHTS);
  byte percentValue = map(lightsValue,1400,4095,0,100);
  Serial.println(percentValue);
  if(percentValue >= 40){
    Serial.println("亮");
    digitalWrite(LED,LOW);
  }else{
    Serial.println("暗");
    digitalWrite(LED,HIGH);
  }
  delay(100);
}
