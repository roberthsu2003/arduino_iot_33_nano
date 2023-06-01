#define BTN 8
#define BUZZER 4


void setup()
{
  Serial.begin(9600);
  pinMode(BTN, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  bool btnValue = digitalRead(BTN);
  if(btnValue==0){
    Serial.println("press");
    sound();
  }
  delay(100);
}

void sound(){
  digitalWrite(BUZZER,HIGH);
  delay(100);
  digitalWrite(BUZZER,LOW);
}
