#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5
unsigned long switchCount = 0; //狀態改變的次數
int i = 0; //按下放開的次數


void setup() {
  Serial.begin(9600);
  
  
}

int button_release(int buttonPin) { //傳出按鈕改變的次數
  pinMode(buttonPin, INPUT_PULLUP);
  static bool buttonState = digitalRead(buttonPin);
  bool currentButtonState = digitalRead(buttonPin);
  if (currentButtonState != buttonState) {
    delay(30); //解決彈跳
    if (currentButtonState != buttonState) {
      buttonState = currentButtonState;
      return 1;
    }
  }
  return 0;
}

int displayNum(int stateCount,int maxNum){ //stateCount是按鈕狀態改變的次數,maxNum是0~maxNum
    int i = stateCount / 2; 
    return i % (maxNum+1);    
}

int count = 0; //計算按鈕狀態改變的次數

void loop() {    
    count += button_release(button);    
    int displayNumber = displayNum(count,9);
    Serial.println(displayNumber);
}
