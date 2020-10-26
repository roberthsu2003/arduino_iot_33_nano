void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
}

void loop()
{
  int sensorVal = digitalRead(2);
  if(sensorVal == 1){
    Serial.println("release");
  }else{
    Serial.println("press");
  }
}
