#define BTN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btnState = digitalRead(BTN);
  
  if(btnState == HIGH){
    Serial.println("按鈕被按了");
  }else{
    Serial.println("沒按按鈕");
  }
  delay(10);
}
