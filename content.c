// C++ code
//

#define BTN 12
#define LED 13

void setup()
{
  Serial.begin(9600);
  pinMode(BTN,INPUT);
  pinMode(LED,OUTPUT);
}

void loop()
{
  bool value = digitalRead(BTN);
  Serial.println(value);
  if(value){
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(LED,LOW);
  }
  delay(100);
}
