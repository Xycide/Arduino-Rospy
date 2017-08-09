#include "Control.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); //LED
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Control arbot;
  char right;
  char left;
  char command;

 if (Serial.available()) {
  command = Serial.read();
  Serial.print(command);
  delay(50);
  if (!arbot.RangeCheck(command)) {
    switch (command) {
      case '0': 
      left = Serial.read();
      delay(50);
      right = Serial.read();
      delay(50);
      if (arbot.RangeCheck(left) == 1 && arbot.RangeCheck(right) == 2) {
        Serial.print(left);
        delay(50);
        arbot.LeftSpeed(map(left, 58, 78, -255, 255));
        Serial.println(right);
        delay(50);
        arbot.RightSpeed(map(right, 79, 99 , -255, 255));
      }
      break;
      case '1':
      // stabby Stab
      break;
      // beep boop
      case '2':
      delay (50);
      digitalWrite(13, HIGH);
      delay (50);
      digitalWrite(13, LOW);
      break;   
    }
  }
  
 }
}
