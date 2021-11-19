#ifndef SDCard_h
#define SDCard_h

#include "Arduino.h"
#include <SD.h>

class SDCard {
  private:
    int pin;
    File myFile;
    
  public:
    SDCard(int _pin);
    bool init();
    void test();
};

#endif
