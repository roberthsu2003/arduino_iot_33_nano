int buttonPin = 2;
int buttonState = 0; 
int ledPin = 13;
void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
	buttonState	= digitalRead(buttonPin);
  if(buttonState == 1){
    Serial.println("press");
    digitalWrite(ledPin, HIGH);
  }else{
    Serial.println("release");
    digitalWrite(ledPin, LOW);
  }
}
