// C++ code
//
void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0){
    char inputValue = Serial.read();
    Serial.println(inputValue);
    switch(inputValue){
      case '1':
      digitalWrite(4,HIGH);
      break;
      case '0':
      digitalWrite(4,LOW);
      break;
    }
  }
  
 
}
