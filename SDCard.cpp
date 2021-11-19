#include "Arduino.h"
#include "SDCard.h"


SDCard::SDCard(int _pin){
	this->pin = _pin;
	}

bool SDCard::init(void){
  Serial.println("Initialising SD card...");
  if(!SD.begin(pin)){
    Serial.println("Initialising failed.");
    return false;
  }else{
    Serial.println("Card is present.");
    return true;
  }
	Serial.println("Initialising failed.");
  return false;
	}

void SDCard::test(void){
      myFile = SD.open("test.txt",FILE_WRITE);
  
      if(myFile){
        Serial.println("Writing to test.txt..");
        myFile.println("Testing 1, 2, 3.");
        myFile.close();
        Serial.println("Done.");
      }else{
        Serial.println("Error when opening test.txt.");
      }
  
      myFile = SD.open("test.txt");
      if(myFile){
        Serial.println("test.txt");
  
        // read from file until empty
        while(myFile.available()){
          Serial.write(myFile.read());
        }
        myFile.close();
      }else{
        Serial.println("Error opening test.txt.");
      }
}


