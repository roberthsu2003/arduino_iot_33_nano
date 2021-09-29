// C++ code
//

unsigned long previousTime;
void setup()
{
  Serial.begin(9600);
  previousTime = millis();
}

void loop()
{

 oneSecond();
 
}

void oneSecond(){
  unsigned long currentTime = millis();
  if(currentTime - previousTime >=1000){
    previousTime = currentTime;
    Serial.println("over one Second");
  }
}
