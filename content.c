#define BTN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btnState = digitalRead(BTN);
  
  if(btnState == LOW){
    Serial.println("按鈕被按下");
  }else{
    Serial.println("沒按按鈕");
  }
  delay(10);
}
