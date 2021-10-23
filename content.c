secret.h
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#define ID ""
#define PASS ""

====================================
main


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
  
}
void displayNum(byte displayNum){
  //儲存7段顯示器顯示0~9所需要的2進位值
  char numbers[] = {B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,B01111111,B01111011};
  byte pins[] = {g,f,e,d,c,b,a,0};
  char n = numbers[displayNum];//7段顯示器要顯示的數字的數字
  for(int i=6; i>=0; i--){
    bool val = bitRead(n,i);
    Serial.print(val);
    digitalWrite(pins[i],val);    
  }
  Serial.println();
  
}

void loop() {
  if(Serial.available()){
      long inputNum = Serial.parseInt();
      if(inputNum>=0 && inputNum<=9){
        displayNum(inputNum);
        Serial.println(inputNum);
      }else{
        Serial.println("不合法的數字");
      }
      
  }
   

}
