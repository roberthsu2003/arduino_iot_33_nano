void setup() {
  
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int receiveData = Serial.read();

    switch(receiveData){
      case '1':
        digitalWrite(7, HIGH);
        break;
      case '0':
        digitalWrite(7, LOW);
        break;
      default:
        break;
    }
  }
}
