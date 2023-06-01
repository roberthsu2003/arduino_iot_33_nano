// C++ code
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A1) / 1023.0 * 255;
  Serial.println(value);
}
