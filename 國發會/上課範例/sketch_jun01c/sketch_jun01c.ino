// C++ code
//
#define RED_PIN 5

void setup()
{
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
}

void loop()
{
  int value = analogRead(A1);
  int mapValue = map(value,0,1023,0,120);
  Serial.println(mapValue);
  analogWrite(RED_PIN,mapValue);
  
}
