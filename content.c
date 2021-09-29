// C++ code
//


void setup()
{
  Serial.begin(9600);
  
}

void loop()
{

 oneSecond();
 twoSecond();
}

void oneSecond(){
  static unsigned long previousTime = millis();
  unsigned long currentTime = millis();
  if(currentTime - previousTime >=1000){
    previousTime = currentTime;
    Serial.println("over one Second");
  }
}

void twoSecond(){
  static unsigned long previousTime = millis();
  unsigned long currentTime = millis();
  if(currentTime - previousTime >=2000){
    previousTime = currentTime;
    Serial.println("over two Second");
  }
}
