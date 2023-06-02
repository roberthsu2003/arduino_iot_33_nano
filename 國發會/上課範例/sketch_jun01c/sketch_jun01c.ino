// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A1);
  int mapValue = map(value,0,1023,0,255);
  Serial.println(mapValue);
}
