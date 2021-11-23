/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

#include "Arduino.h"
#include "BubbleDataObject.h"

BubbleDataObject::BubbleDataObject(void){
    bubblesPerDay = 0;
    bubblesPerHour = 0;
    bubblesPerMin = 0;
    
    old_bubblesPerDay = 0;
    old_bubblesPerHour = 0;
    old_bubblesPerMin = 0;

    maxBubblesPerDay = 0;
    maxBubblesPerHour = 0;
    maxBubblesPerMin = 0;
}

void BubbleDataObject::setStartTime(DateTime start){
    startOfMeasurement = start;
}

void BubbleDataObject::setBubblesPerDay(int newBubsPerDay){
  old_bubblesPerDay = bubblesPerDay;
  bubblesPerDay = newBubsPerDay;
  maxBubblesPerDay = (maxBubblesPerDay < newBubsPerDay)?newBubsPerDay:maxBubblesPerDay;
}

void BubbleDataObject::setBubblesPerHour(int newBubsPerHour){
  old_bubblesPerHour = bubblesPerHour;
  bubblesPerHour = newBubsPerHour;
  maxBubblesPerHour = (maxBubblesPerHour < newBubsPerHour)?newBubsPerHour:maxBubblesPerHour;
}

void BubbleDataObject::setBubblesPerMin(int newBubsPerMin){
  old_bubblesPerMin = bubblesPerMin;
  bubblesPerMin = newBubsPerMin;
  maxBubblesPerMin = (maxBubblesPerMin < newBubsPerMin)?newBubsPerMin:maxBubblesPerMin;
}

int BubbleDataObject::calculatePercentFromOldDay(void){
    double percent = (bubblesPerDay/old_bubblesPerDay)*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromOldHour(void){
    double percent = (bubblesPerHour/old_bubblesPerHour)*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromOldMin(void){
    double percent = (bubblesPerMin/old_bubblesPerMin)*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromMaxDay(void){
    double percent = (bubblesPerDay/maxBubblesPerDay)*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromMaxHour(void){
    double percent = (bubblesPerHour/maxBubblesPerHour)*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromMaxMin(void){
    double percent = (bubblesPerMin/maxBubblesPerMin)*100;
    return (int)percent;
}

DateTime BubbleDataObject::calculateRunTime(DateTime _now){
    DateTime durationOfMeasurement(_now.unixtime() - startOfMeasurement.unixtime());
    return durationOfMeasurement;
}
