// C++ code
//
void setup()
{
  int english;	
  Serial.begin(9600);
  	Serial.println("english Score:");
    while(true){
      if(Serial.available()){
        english = Serial.parseInt();
        break;
      }
      
    }
  Serial.print("Hello!your english is ");
  Serial.println(english);
}

void loop()
{
  
}
