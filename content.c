#define BTN 2
#define LED 13


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool sensorVal = digitalRead(BTN);
  if(sensorVal){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
