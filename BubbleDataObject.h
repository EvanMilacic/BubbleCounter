/* BubbleDataObject - Is used to store data from a single measurement.
 * It should be a struct.
 * E.Milacic
 */

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

	int calculatePercentFromOldDay(void);
	int calculatePercentFromOldHour(void);
	int calculatePercentFromOldMin(void);

	int calculatePercentFromMaxDay(void);
	int calculatePercentFromMaxHour(void);
	int calculatePercentFromMaxMin(void);

	DateTime calculateRunTime(DateTime now);

};