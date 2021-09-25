#define LED A2

long inputValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);

  while (!Serial);
  Serial.println("Hello!Word!");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    inputValue = Serial.parseInt();
    Serial.println(inputValue);
    analogWrite(LED,inputValue);
  }
  
}
