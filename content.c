// C++ code
//

#define LIGHT A2

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  int value = analogRead(LIGHT);
  Serial.println(value);
  delay(100);
  
}
