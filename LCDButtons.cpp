/* LCDButtons - Is used to store data from the keypad buttons on the lcd screen.
 * It should read the button press and translate its action to a state
 * E.Milacic
 */

#include "Arduino.h"
#include "LCDButtons.h"

LCDButtons::LCDButtons(int _pin){
    pin = _pin;
    lastPressedValue = KeypadButtons::NONE;
}

KeypadButtons LCDButtons::readButton(void){
    int buttonValue = analogueRead(pin);
    if(buttonValue > 800){
        lastPressedValue = KeypadButtons::NONE;
    }else if(buttonValue < 800){
        lastPressedValue = KeypadButtons::SELECT;
    }else if(buttonValue < 600){
        lastPressedValue = KeypadButtons::LEFT;
    }else if(buttonValue < 400){
        lastPressedValue = KeypadButtons::DOWN;
    }else if(buttonValue < 200){
        lastPressedValue = KeypadButtons::UP;
    }else if(buttonValue < 60){
        lastPressedValue = KeypadButtons::RIGHT;
    }
    return lastPressedValue;
}

KeypadButtons LCDButtons::lastPressedButton(void){
    return lastPressedValue;
}