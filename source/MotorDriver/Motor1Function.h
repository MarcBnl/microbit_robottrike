#ifndef MOTOR1FUNCTION_H
#define MOTOR1FUNCTION_H

#include <DigitalInOut.h>

namespace mtrCtrl{

    class Motor1Function {
        DigitalInOut P8;
        DigitalInOut P12;
        public:
            Motor1Function(void);
            ~Motor1Function(void){};
            void reverseDirections(void);
            void coast(void);
            void forward(void);
            void reverse(void);
            void brake(void);
            mtrCtrl::MTRFUNCTIONS getFunction(void);
        private:
            bool normalDirection;
            void write(int valueP8, int valueP12);
            void read(int &valueP8, int &valueP12);
    }

} /*mtrCtrl*/

#endif /*MOTOR1FUNCTION_H*/