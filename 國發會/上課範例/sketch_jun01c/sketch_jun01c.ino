// C++ code
//
#define RED_PIN 5
#define GREEN_PIN 6
#define BLUE_PIN 9
#define LIGHT A2

byte rState = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
}

void loop()  
{
  int lightValue = analogRead(LIGHT);
  Serial.println(lightValue);
  int value = analogRead(A1);
  int mapValue = map(value,0,1023,0,255);
  //Serial.println(mapValue);
  
  changeColor(mapValue,rState);
  
  if(Serial.available()){
    switch(Serial.read()){
      case 'r':
        Serial.println('r');
        rState = 1;
        break;
      case 'g':
        Serial.println('g');
        rState = 2;
        break;
      case 'b':
        Serial.println('b');
        rState = 3;
        break;
      default:
        break;
    }
    
  }
   
}

void changeColor(int value, byte state){
  int allValue = (value>=120) ? 120 : value ;
  if (state == 1){
    analogWrite(RED_PIN, allValue);
    analogWrite(GREEN_PIN,0);
    analogWrite(BLUE_PIN,0); 
  }else if(state == 2){
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN,allValue);
    analogWrite(BLUE_PIN,0); 
    
  }else if(state == 3){
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN,0);
    analogWrite(BLUE_PIN,allValue);     
  }else{
    analogWrite(RED_PIN, allValue);
    analogWrite(GREEN_PIN,allValue);
    analogWrite(BLUE_PIN,allValue); 
  }
  
}
