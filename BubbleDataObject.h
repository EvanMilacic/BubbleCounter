/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

#ifndef BubbleDataObject_h
#define BubbleDataObject_h

#include "Arduino.h"
#include <RTClib.h>
#include "TimedVariable.h"
#include "enums.h"

class BubbleDataObject {
private:
	TimedVariable bubblesPerDay(0);
	TimedVariable bubblesPerHour(0);
	TimedVariable bubblesPerMin(0);

	DateTime startOfMeasurement;

public:
	BubbleDataObject(void);

  	//Setters
	void setStartTime(DateTime start);
	template <class T>
	void setTimedVariable(TimedVariable type, T newValue);
  	void setBubblesPerDay(int newBubsPerDay);
  	void setBubblesPerHour(int newBubsPerHour);
  	void setBubblesPerMin(int newBubsPerMin);
  
  	//Getters
	int calculatePercentFromOldDay(void);
	int calculatePercentFromOldHour(void);
	int calculatePercentFromOldMin(void);

	int calculatePercentFromMaxDay(void);
	int calculatePercentFromMaxHour(void);
	int calculatePercentFromMaxMin(void);

	DateTime calculateRunTime(DateTime now);

};

#endif