int buttonPin = 2;
int buttonState = 0;  
void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop()
{
	buttonState	= digitalRead(buttonPin);
  if(buttonState == 1){
    Serial.println("press");
  }else{
    Serial.println("release");
  }
}
