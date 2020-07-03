# 事件導向
## 學習電壓改變事件
### 線路圖
![](EventDrive_bb.jpg)

### 實體線路圖
![](IMG_0386.jpg)

### 事件導向_間隔時間執行_成品展示
[![事件導向_間隔時間執行](https://img.youtube.com/vi/XptfalbqghI/0.jpg)](https://youtu.be/XptfalbqghI)



```C++
##################################
#安裝Eventually package
#
###################################

#include <Eventually.h>

/* 
 * This just shows a simple way of using the library.
 * Pushing a button moves the Arduino back-and-forth
 * from a fast blink to a slow blink.
 */

#define LIGHT_PIN 5
#define BUTTON_PIN 3

bool speed = LOW;
EvtManager mgr;
bool pin_state = LOW;

bool blink() {
  pin_state = !pin_state;
  digitalWrite(LIGHT_PIN, pin_state);
  return false;
}

bool set_speed() {
  mgr.resetContext();
  mgr.addListener(new EvtPinListener(BUTTON_PIN, (EvtAction)set_speed));
  speed = !speed; // Change speeds
  if(speed == HIGH) {
    mgr.addListener(new EvtTimeListener(250, true, (EvtAction)blink));
  } else {
    mgr.addListener(new EvtTimeListener(1000, true, (EvtAction)blink));
  }

  return true;
}

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  set_speed();
}

USE_EVENTUALLY_LOOP(mgr)
```

