#define CDS A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);
  Serial.println(sensorVal);
  delay(100);
}
