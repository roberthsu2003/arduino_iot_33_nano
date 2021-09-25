

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  intervalOne();
  intervalTwo();
}


void intervalOne(){
  static unsigned long previousTime = millis();
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >= 1000){
    previousTime = currentTime;
    Serial.println("每隔1秒執行一次");
  }
}

void intervalTwo(){
  static unsigned long previousTime = millis();
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >= 2000){
    previousTime = currentTime;
    Serial.println("每隔2秒執行一次");
  }
}
