/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

#include "Arduino.h"
#include "BubbleDataObject.h"

BubbleDataObject::BubbleDataObject(DateTime _now){
    bubblesPerDay = 0;
    bubblesPerHour = 0;
    bubblesPerMinute = 0;
    
    old_bubblesPerDay = 0;
    old_bubblesPerHour = 0;
    old_bubblesPerMin = 0;

    maxBubblesPerDay = 0;
    maxBubblesPerHour = 0;
    maxBubblesPerMinute = 0;

    startOfMeasurement = _now;
}

DateTime BubbleDataObject::calculateRunTime(DateTime _now){
    DateTime durationOfMeasurement(_now.unixtime() - startOfMeasurement.unixtime());
    return durationOfMeasurement;
}

