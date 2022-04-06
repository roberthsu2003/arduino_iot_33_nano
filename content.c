// C++ code
//

#define BTN 12
#define LED 13

void setup()
{
  Serial.begin(9600);
  pinMode(BTN,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
}

void loop()
{
  bool value = digitalRead(BTN);
  Serial.println(value);
  
  if(value){
    digitalWrite(LED,LOW);
  }else{
    digitalWrite(LED,HIGH);
  }
  
  delay(100);
}
