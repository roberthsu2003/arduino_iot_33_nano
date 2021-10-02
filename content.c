#define BTN 2
#define LED 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN,INPUT_PULLUP);
  pinMode(LED,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btnState = digitalRead(BTN);
  
  if(btnState == LOW){
    Serial.println("按鈕被按下");
    digitalWrite(LED,HIGH);
  }else{
    Serial.println("沒按按鈕");
    digitalWrite(LED,LOW);
  }
  delay(10);
}
