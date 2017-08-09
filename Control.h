#ifndef Control_h
#define Control_h
#include "Arduino.h"

class Control {
  public:
  Control();
  void ClearSerial();
  void forward(int wspeed);
  void vstop();
  void LeftSpeed(int wspeed);
  void RightSpeed(int wspeed);
  int RangeCheck(int command);
  int MA1;
  int MA2;
  int MB1;
  int MB2;
  int PB;
  int PA;
};

#endif
