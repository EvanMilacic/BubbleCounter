/* Bubble Counter project - This project is meant to measure the bubbles through a water-lock in a fermenter
 *  It should indicate what the current fermentation rate is and the rate relative to the past.
 *  It countains a data-logging shield to store the time stamps of the bubble.
 *  An LCD keypad schield is added to allow for read-out during the measurment.
 *  There is a conflict in my boards on the D10 pin. So i snipped the D10 pin of the LCD keypad shield.
 *  E.Milacic
 */

/*=============================================== Libraries ==========================================*/
// LCD library
#include <LiquidCrystal.h>

//SD card libraries
#include <SPI.h>
#include <SD.h>

//RealTimeClock library
#include <RTClib.h>

/*======================================== Home made extensions =======================================*/
#include "SDCard.h"
#include "BubbleDataObject.h"


/*=============================================== Globals ==============================================*/

//Set up all the components
//LCD screen
const int ButtonPin = A0;
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

//SD card objects
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 10;
const int testCard = 1;
const int hasCard = 1;
SDCard sdcard(chipSelect);

//RealTimeClock
RTC_DS1307 RTC;

BubbleDataObject bubbles;



void setup() {
  //Start the serial to help with debugging
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

if(hasCard){
  //Start the SD card
  if(!sdcard.init()){
    while(1);
  }
  // Test the SD card
  if(testCard){
    sdcard.test();
  }
}
  //Start the clock
  Wire.begin();
  if(!RTC.begin()){
    Serial.println("RTC failed.");
  }
  //This is to reset the time of the clock in case of delay
  RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));

  //This starts the LCD screen with the right dimensions
  LCD.begin(16,2);

  bubbles.setStartTime(RTC.now());
}

void loop() {
DateTime now = bubbles.calculateRunTime(RTC.now());
delay(1000);

LCD.setCursor(0,0);
LCD.clear();

  
}
