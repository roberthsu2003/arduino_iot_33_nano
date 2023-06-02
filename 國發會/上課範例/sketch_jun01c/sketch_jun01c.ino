// C++ code
//
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 9
int rValue=0;
int gValue=0;
int bValue=0;

void setup()
{
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
}

void loop()
{
  int value = analogRead(A1);
  int mapValue = map(value,0,1023,0,255);
  //Serial.println(mapValue);
  
  changeColor(rValue,gValue,bValue);
  
  if(Serial.available()){
    switch(Serial.read()){
      case 'r':
        Serial.println('r');
        rValue=255;
        gValue=0;
        bValue=0;
        break;
      case 'g':
        Serial.println('g');
        rValue=0;
        gValue=255;
        bValue=0;
        break;
      case 'b':
        Serial.println('b');
        rValue=0;
        gValue=0;
        bValue=255;
        break;
      default:
        break;
    }
    
  }
   
}

void changeColor(int r, int g, int b){
  int rValue = (r>=120) ? 120 : r ;
  int gValue = (g>=120) ? 120 : g ;
  int bValue = (b>=120) ? 120 : b ;
  
  analogWrite(RED_PIN,rValue);
  analogWrite(GREEN_PIN,gValue);
  analogWrite(BLUE_PIN,bValue); 
}
