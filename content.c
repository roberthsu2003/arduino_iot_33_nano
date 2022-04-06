// C++ code
//

#define BTN 12

void setup()
{
  Serial.begin(9600);
  pinMode(BTN,INPUT);
}

void loop()
{
  bool value = digitalRead(BTN);
  Serial.println(value);
  delay(100);
}
