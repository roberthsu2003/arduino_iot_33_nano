// C++ code
//
#define LED 4

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0){
    char inputValue = Serial.read();
    Serial.println(inputValue);
    switch(inputValue){
      case '1':
      digitalWrite(LED,HIGH);
      break;
      case '0':
      digitalWrite(LED,LOW);
      break;
    }
  }
  
 
}
