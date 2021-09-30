#define BTN 2
#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool btnState = digitalRead(BTN);
  Serial.println(btnState);
  if(btnState){
    digitalWrite(LED, LOW);
  }else{
    digitalWrite(LED, HIGH);
  }
}
