#include "data.h"

#define INPUT_RED A0
#define INPUT_GREEN A1
#define INPUT_BLUE A2
#define OUTPUT_RED 2
#define OUTPUT_GREEN 3
#define OUTPUT_BLUE 5


RGB_LED r(INPUT_RED,OUTPUT_RED);
RGB_LED g(INPUT_GREEN,OUTPUT_GREEN);
RGB_LED b(INPUT_BLUE,OUTPUT_BLUE);

void setup() {
  Serial.begin(9600);  
}

void loop() {
  r.run();
  g.run();
  b.run();
  delay(1000);
}



