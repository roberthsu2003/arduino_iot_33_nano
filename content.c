// C++ code
//
void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(4, HIGH);
  Serial.println("open");
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(4, LOW);
  Serial.println("close");
  delay(1000); // Wait for 1000 millisecond(s)
}
