#define BTN 8


void setup()
{
  Serial.begin(9600);
  pinMode(BTN, INPUT_PULLUP);
 
}

void loop()
{
  bool btnValue = digitalRead(BTN);
  if(btnValue==0){
    Serial.println("press");
  }
  delay(100);
}
