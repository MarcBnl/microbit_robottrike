#ifndef MOTOR1FUNCTION_H
#define MOTOR1FUNCTION_H

#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "mbed.h"
#include "DigitalInOut.h"
#include "Defines.h"

// namespace mtrCtrl{

    class Motor1Function 
    {
        DigitalInOut P8;
        DigitalInOut P12;
        public:
            Motor1Function(void);
            ~Motor1Function(void){coast();};
            void reverseDirections(void);
            void coast(void);
            void forward(void);
            void reverse(void);
            void brake(void);
            int getFunction(void);
        private:
            bool normalDirection;
            void writeToPins(int valueP8, int valueP12);
            void readFromPins(int &valueP8, int &valueP12);
    };

// } /*mtrCtrl*/

#endif /*MOTOR1FUNCTION_H*/