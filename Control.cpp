#include "Control.h"
#include "Arduino.h"

Control::Control() {

  MA1 = 4;
  MA2 = 5;
  MB1 = 6;
  MB2 = 7;
  PA = 9;
  PB = 3;

  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(PA, OUTPUT);
  pinMode(PB, OUTPUT);

  Serial.begin(115200);
}

void Control::forward(int wspeed) {
  digitalWrite(MA1, LOW);
  digitalWrite(MA2, HIGH);

  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);

  analogWrite(PA, wspeed);
  analogWrite(PB, wspeed);
}

void Control::vstop() {
  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, HIGH);

  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, HIGH);

  analogWrite(PA, 0);
  analogWrite(PB, 0);
}

void Control::LeftSpeed(int wspeed) {
  if (wspeed > 0) {
    digitalWrite(MB1, LOW);
    digitalWrite(MB2, HIGH);
  }
  else {
    digitalWrite(MB1, HIGH);
    digitalWrite(MB2, LOW);
  }
  if (wspeed < 0) {
    analogWrite(PB, -wspeed);
  }
  else {
    analogWrite(PB, wspeed);
  }
}

void Control::RightSpeed(int wspeed) {
  if (wspeed > 0) {
    digitalWrite(MA1, LOW);
    digitalWrite(MA2, HIGH);
  }
  else {
    digitalWrite(MA1, HIGH);
    digitalWrite(MA2, LOW);
  }
  if (wspeed < 0) {
    analogWrite(PA, -wspeed);
  }
  else {
    analogWrite(PA, wspeed);
  }
}

void Control::ClearSerial() {
   while(Serial.available()) {
    Serial.read();
   }
}

int Control::RangeCheck(int command) {
  if (command <= 57 && command >= 48) {
    return 0;
  }
  if (command <= 78 && command >= 58) {
    return 1;
  }
  if (command >= 79 && command <= 99) {
    return 2;
  }
  if (command == 33) {
    ClearSerial();
  }

  return -1;
}

