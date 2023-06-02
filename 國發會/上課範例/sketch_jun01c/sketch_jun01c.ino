// C++ code
//
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 9

void setup()
{
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
}

void loop()
{
  int value = analogRead(A1);
  int mapValue = map(value,0,1023,0,255);
  Serial.println(mapValue);
  changeColor(mapValue,0,0);
   
}

void changeColor(int r, int g, int b){
  int rValue = (r>=120) ? 120 : r ;
  int gValue = (g>=120) ? 120 : g ;
  int bValue = (b>=120) ? 120 : b ;
  
  analogWrite(RED_PIN,rValue);
  analogWrite(GREEN_PIN,gValue);
  analogWrite(BLUE_PIN,bValue); 
}
