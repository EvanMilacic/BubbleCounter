/* TimedVariable - Is used to store data from the current step, the previous and the max achieved
 * I made it a class because i want it do update itself, when provided with the correct value.
 * E.Milacic
 */

#ifndef TimedVariable_h
#define TimedVariable_h

#include "Arduino.h"

template <class T>
class TimedVariable {
private:
    T currentVal;
    T oldVal;
    T maxVal;

public:
    TimedVariable(T initValue);
    void updateValues(T newValue);

    //getters
    T getCurrent(void);
    T getOld(void);
    T getMax(void);
};


#endif