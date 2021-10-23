#define a 3
#define b 4
#define c 5
#define d 6
#define e 7
#define f 8
#define g 9

void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  Serial.begin(9600);
  while(!Serial);  
  displayNum();
}
void displayNum(){
  byte n = B01111110;//7段顯示器0的數字
  for(int i=6; i>=0; i--){
    Serial.print(bitRead(n,i));    
  }
  Serial.println();
  
}

void loop() {
  if(Serial.available()){
      switch(Serial.read()){
      case '0':
      Serial.println(0);
      
      break;

      case '1':
      Serial.println(1);
      
      break;

      case '2':
      Serial.println(2);
      
      break;

      case '3':
      Serial.println(3);
      
      break;

      case '4':
      Serial.println(4);
      
      break;

      case '5':
      Serial.println(5);
      
      break;

      case '6':
      Serial.println(6);
      
      break;

      case '7':
      Serial.println(7);
      
      break;

      case '8':
      Serial.println(8);
      
      break;

      case '9':
      Serial.println(9);
      
      break;
    }
  }
   

}
