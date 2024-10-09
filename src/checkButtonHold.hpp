#ifndef CHECK_BUTTON_HOLD
#define CHECK_BUTTON_HOLD
#define BUTTOP_PIN 0
#include<Arduino.h>
void checkButtonHold(){
  unsigned long startTime = millis();
  while(digitalRead(BUTTON_PIN) == LOW){
    if(millis() - startTime > 3000){
      bootloader();
    }
  }
}
#endif