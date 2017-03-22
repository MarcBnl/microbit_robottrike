#ifndef MOTOR2FUNCTION_H
#define MOTOR2FUNCTION_H

#include <DigitalInOut.h>

namespace mtrCtrl{

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
            MOTORFUNCTIONS getFunction(void);
        private:
            bool normalDirection;
            void writeToPins(int valueP0, int valueP16);
            void readFromPins(int &valueP0, int &valueP16);
    }

} /*mtrCtrl*/

#endif /*MOTOR2FUNCTION_H*/