/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

#ifndef BubbleDataObject_h
#define BubbleDataObject_h

#include "Arduino.h"
#include <RTClib.h>

class BubbleDataObject {
private:
	int bubblesPerDay;
	int bubblesPerHour;
	int bubblesPerMin;

	int old_bubblesPerDay;
	int old_bubblesPerHour;
	int old_bubblesPerMin;

	int maxBubblesPerDay;
	int maxBubblesPerHour;
	int maxBubblesPerMin;

	DateTime startOfMeasurement;

public:
	BubbleDataObject(void);

  	//Setters
	void setStartTime(DateTime start);
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