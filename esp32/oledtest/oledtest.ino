
#include <Wire.h>
#include "SSD1306.h"

SSD1306 display(0x3c, 18, 19); 

void setup() {
  display.init();
  display.drawString(0, 0, "Hello World");
  display.display();
}

bool d = true;
void loop() {
  // put your main code here, to run repeatedly:
  d ? display.invertDisplay() : display.normalDisplay();
  d = !d;
  delay(500);
}
