/* LCDButtons - Is used to store data from the keypad buttons on the lcd screen.
 * It should read the button press and translate its action to a state
 * E.Milacic
 */

#ifndef LCDButtons_h
#define LCDButtons_h

#include "Arduino.h"
#include "enums.h"

class LCDButtons {
private:
    int pin;
    KeypadButtons lastPressedValue;
public:
    LCDButtons(int _pin);

    KeypadButtons readButton(void);
    KeypadButtons lastPressedButton(void);

};

#endif