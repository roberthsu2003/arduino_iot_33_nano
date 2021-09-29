// C++ code
//

#define RED 4
#define BLUE 5

void setup()
{
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

void loop()
{

 oneSecond();
 twoSecond();
}

void oneSecond(){
  static bool redState = false;
  static unsigned long previousTime = millis();
  unsigned long currentTime = millis();
  if(currentTime - previousTime >=1000){
    previousTime = currentTime;
    Serial.println("over one Second");
    redState = !redState;
    digitalWrite(RED,redState);
  }
}

void twoSecond(){
  static bool blueState = false;
  static unsigned long previousTime = millis();
  unsigned long currentTime = millis();
  if(currentTime - previousTime >=2000){
    previousTime = currentTime;
    Serial.println("over two Second");
    blueState = !blueState;
    digitalWrite(BLUE, blueState);
  }
}
