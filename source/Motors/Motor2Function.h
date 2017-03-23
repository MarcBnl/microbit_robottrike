#ifndef MOTOR2FUNCTION_H
#define MOTOR2FUNCTION_H

#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "mbed.h"
#include "DigitalInOut.h"
#include "Defines.h"

// namespace mtrCtrl{

    class Motor2Function
    {
        DigitalInOut P0;
        DigitalInOut P16;
        public:
            Motor2Function(void);
            ~Motor2Function(void){coast();};
            void reverseDirections(void);
            void coast(void);
            void forward(void);
            void reverse(void);
            void brake(void);
            int getFunction(void);
        private:
            bool normalDirection;
            void writeToPins(int valueP0, int valueP16);
            void readFromPins(int &valueP0, int &valueP16);
    };

// } /*mtrCtrl*/

#endif /*MOTOR2FUNCTION_H*/