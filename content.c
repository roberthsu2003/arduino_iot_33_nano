char inputValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);  
  Serial.println("Hello!Word!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    inputValue = Serial.read();
    
    if(inputValue == '1'){
      Serial.println("您輸入的是1");
    }else if(inputValue == '0'){
      Serial.println("您輸入的是0");
    }else if(inputValue == '2'){
      Serial.println("您輸入的是2");
    }
    
  }
 
}
