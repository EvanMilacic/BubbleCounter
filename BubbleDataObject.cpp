/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

#include "Arduino.h"
#include "BubbleDataObject.h"


BubbleDataObject::BubbleDataObject(void){};

void BubbleDataObject::setStartTime(DateTime start){
    startOfMeasurement = start;
}

void BubbleDataObject::setTimedVariable(TimedVariable type, T newValue){
    switch(type){
        case DAY:{
            bubblesPerDay.updateValues(newValue);
            break;
        }
        case HOUR:{
            bubblesPerHour.updateValues(newValue);
            break;
        }
        case MIN:{
            bubblesPerMin.updateValues(newValue);
            break;
        }
    }
}

void BubbleDataObject::setBubblesPerDay(int newBubsPerDay){
  bubblesPerDay.updateValues(newBubsPerDay);
}

void BubbleDataObject::setBubblesPerHour(int newBubsPerHour){
  bubblesPerHour.updateValues(newBubsPerHour);
}

void BubbleDataObject::setBubblesPerMin(int newBubsPerMin){
  bubblesPerMin.updateValues(newBubsPerMin);
}

int BubbleDataObject::calculatePercentFromOldDay(void){
    double percent = (bubblesPerDay.getCurrent()/bubblesPerDay.getOld())*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromOldHour(void){
    double percent = (bubblesPerHour.getCurrent()/bubblesPerHour.getOld())*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromOldMin(void){
    double percent = (bubblesPerMin.getCurrent()/bubblesPerMin.getOld())*100;
    return (int)percent;
}

int BubbleDataObject::calculatePercentFromMaxDay(void){
    double percent = (bubblesPerDay.getCurrent()/bubblesPerDay.getMax())*100;
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
