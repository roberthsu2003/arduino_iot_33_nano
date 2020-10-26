byte pins[] = {4, 5, 6, 7, 8};
byte count = sizeof(pins)/sizeof(pins[0]);

void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  for(int i=0; i<count;i++){
    pinMode(pins[i], OUTPUT);
  }
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
  for(int i=0; i<count;i++){
    digitalWrite(pins[i],HIGH);
    delay(1000);
  }
  ledStop();
}

void ledStop(){
  Serial.println("led Stop");
  for(int i=0; i<count;i++){
    digitalWrite(pins[i],LOW);
  }
}
