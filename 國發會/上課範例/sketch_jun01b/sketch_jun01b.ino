#define BTN 8

void setup()
{
  Serial.begin(9600);
  pinMode(BTN, INPUT);
}

void loop()
{
  bool btnValue = digitalRead(BTN);
  Serial.println(btnValue);
  delay(100);
}
