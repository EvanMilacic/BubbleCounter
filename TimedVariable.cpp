/* TimedVariable - Is used to store data from the current step, the previous and the max achieved
 * I made it a class because i want it do update itself, when provided with the correct value.
 * E.Milacic
 */

#include "Arduino.h"
#include "TimedVariable.h"

TimedVariable::TimedVariable(T initValue){
    currentVal = initValue;
    oldVal = initValue;
    maxVal = initValue;
}

void TimedVariable::updateValues(T newValue){
    oldVal = currentVal;
    currentVal = newValue;
    maxVal = (maxVal < currentVal)?currentVal:maxVal; 
}

T TimedVariable::getCurrent(void){
    return currentVal;
}

T TimedVariable::getOld(void){
    return oldVal;
}

T TimedVariable::getMax(void){
    return maxVal;
}