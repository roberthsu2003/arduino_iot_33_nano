#define RED_LED 2
#define BLUE_LED 5

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
  oneSecond();  
  twoSecond();
}

void oneSecond(){
  static unsigned long previous = 0;
  static bool ledState = false;
  if(millis() - previous >= 1000){
    previous = millis();
    ledState = !ledState;
  }
  digitalWrite(RED_LED, ledState);
}

void twoSecond(){
  static unsigned long previous = 0;
  static bool ledState = false;
  if(millis() - previous >= 2000){
    previous = millis();
    ledState = !ledState;
  }
  digitalWrite(BLUE_LED, ledState);
}
