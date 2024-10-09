#include <Arduino.h>
#define LED_PIN 2
#define BUTTON_PIN 0
#define PROGRAM_A_ADDRESS 0x8000
#define PROGRAM_B_ADDRESS 0x10000
#include<loadprogramA.hpp>
#include<loadprogramB.hpp>
void bootloader();
void checkButtonHold();

void setup() {
  // put your setup code here, to run once:
pinMode(LED_PIN, OUTPUT);
pinMode(BUTTON_PIN, INPUT_PULLUP);
bootloader();
}

void loop() {
  // put your main code here, to run repeatedly:
}
void bootloader(){
while(true){
    if(digitalRead(BUTTON_PIN) == LOW)
  {
    LoadProgramA();
  } else{
    LoadProgramB();
  }
}
}

void LoadProgramA(){
   while(true){
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(3000);
  }
  checkButtonHold();
}

void LoadProgramB(){
  for(int i = 0; i<5; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
  delay(3000);
  checkButtonHold();
}

void checkButtonHold(){
  unsigned long startTime = millis();
  while(digitalRead(BUTTON_PIN) == LOW){
    if(millis() - startTime > 3000){
      bootloader();
    }
  }
}

