#define LED A2

char inputValue;
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
    inputValue = Serial.read();

    if (inputValue == '1') {
      Serial.println("您輸入的是1");
      digitalWrite(LED, HIGH);
    } else if (inputValue == '0') {
      Serial.println("您輸入的是0");
      digitalWrite(LED, LOW);
    } else if (inputValue == '2') {
      Serial.println("您輸入的是2");
      digitalWrite(LED, HIGH);
    }

  }
  analogWrite(LED,0);
}
