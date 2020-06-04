# 事件導向
## 學習如何善用事件導向
### 線路圖
![](EventDrive_bb.jpg)

### 實體線路圖
![](IMG_0372.jpg)

### 上拉電阻接線
[![上拉電阻成品展示](https://img.youtube.com/vi/y28I-Kwlljg/2.jpg)](https://youtu.be/y28I-Kwlljg)

### 上拉電阻成品展示
[![上拉電阻成品展示](https://img.youtube.com/vi/_LYhqSXSdy8/1.jpg)](https://youtu.be/_LYhqSXSdy8)



```C++
##################################
#安裝Eventually package
#
###################################

#include <Eventually.h>

/*
 * This is the standard blinky lights written using Eventually.
 * Just set LIGHT_PIN to whatever pin you have your LED attached to.
 */

#define LIGHT_PIN 5

EvtManager mgr;
bool state = LOW;

void setup() {
  pinMode(LIGHT_PIN, OUTPUT);
  mgr.addListener(new EvtTimeListener(1000, true, (EvtAction)blinkme)); 
}

bool blinkme() {
  state = !state; // Switch light states
  digitalWrite(LIGHT_PIN, state); // Display the state
  return false; // Allow the event chain to continue
}

USE_EVENTUALLY_LOOP(mgr) // Use this instead of your loop() function.
```

