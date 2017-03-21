#ifndef MOTOR2FUNCTION_H
#define MOTOR2FUNCTION_H

#include <DigitalInOut.h>

namespace mtrCtrl{

    class Motor2Function {
        DigitalInOut P0;
        DigitalInOut P16;
        public:
            Motor2Function(void);
            ~Motor2Function(void){};
            void reverseDirections(void);
            void coast(void);
            void forward(void);
            void reverse(void);
            void brake(void);
            mtrCtrl::MTRFUNCTIONS getFunction(void);
        private:
            bool normalDirection;
            void write(int valueP0, int valueP16);
            void read(int &valueP0, int &valueP16);
    }

} /*mtrCtrl*/

#endif /*MOTOR2FUNCTION_H*/