void setup() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int receiveData = Serial.read();

    switch(receiveData){
      case '1':
        digitalWrite(LED_BUILTIN, HIGH);
        break;
      case '0':
        digitalWrite(LED_BUILTIN, LOW);
        break;
      default:
        break;
    }
  }
}
