#define RED_LED 2
#define BLUE_LED 5

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
  digitalWrite(RED_LED, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(RED_LED, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(BLUE_LED, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(BLUE_LED, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}
