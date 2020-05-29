# 上拉電阻
## 學習何時使用上接電阻
### 線路圖
![上接電阻線路圖](上拉電阻_bb.jpg)

![成品](IMG_0372.jpg)

```C++
#define btn 2
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = digitalRead(btn);
  if(sensorVal == LOW)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);
}
```

