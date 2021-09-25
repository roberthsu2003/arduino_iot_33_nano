unsigned long previousTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  previousTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  intervalOne();
  
}


void intervalOne(){
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >= 1000){
    previousTime = currentTime;
    Serial.println("每隔1秒執行一次");
  }
}
