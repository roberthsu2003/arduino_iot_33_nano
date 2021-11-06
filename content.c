#define WIRE_PIN 11
#define LIGHT_PIN 5


void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT_PIN,OUTPUT);
  pinMode(WIRE_PIN,INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(WIRE_PIN),blinkme,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);
}

void blinkme(){
  Serial.println("HELLO!");
}
