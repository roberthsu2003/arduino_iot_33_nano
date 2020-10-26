void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
}

void loop()
{
  buttonDetect();
}

void buttonDetect(){
  int sensorVal = digitalRead(2);
  if(sensorVal == 1){
    Serial.println("release");
    ledStop();
  }else{
    Serial.println("press");
    ledEffect();
  }
}

void ledEffect(){
  Serial.println("do something of led");
}

void ledStop(){
  Serial.println("led Stop");
}
