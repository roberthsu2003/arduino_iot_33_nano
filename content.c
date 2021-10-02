#define CDS A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);
  //Serial.println(sensorVal);
  
  if(sensorVal > 700){
    Serial.println("暗");
  }else if(sensorVal < 100){
    Serial.println("亮");
  }else{
    Serial.println("正常");
  }
  
  delay(100);
}
