// C++ code
//
#define redled 11
int a = 9;

void setup()
{
  pinMode(redled,OUTPUT);
}

void loop()
{
  if(a == 10){
    digitalWrite(redled,HIGH);
    delay(1000);
    digitalWrite(redled,LOW);
    delay(1000);
  }else{
    digitalWrite(redled,HIGH);
    delay(300);
    digitalWrite(redled,LOW);
    delay(300);
  }
}
