#define LIGHTS 36

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lightsValue = analogRead(LIGHTS);
  byte percentValue = map(lightsValue,1400,4095,0,100);
  Serial.println(percentValue);
  if(percentValue >= 40){
    Serial.println("亮");
  }else{
    Serial.println("暗");
  }
  delay(100);
}
