#define RED_LED 2
//const byte redLed = 2;

void setup()
{
  pinMode(RED_LED, OUTPUT);
}

void loop()
{
  digitalWrite(RED_LED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(RED_LED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
