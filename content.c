// C++ code
//
#define LED 8

void setup()
{
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop()
{
  Serial.println("Hello! Arduino");
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
