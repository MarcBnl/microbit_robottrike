#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "Defines.h"
#include "source/Motors/Motor1Function.h"
#include "source/Motors/Motor2Function.h"

// namespace mtrCtrl{

    class MotorControl 
    {
        static const int spinDuration_us=200000;
        static const int turnDuration_us=200000;
        Motor1Function motor1F;
        Motor2Function motor2F;
        public:
            MotorControl(int whatIsFront=FRONT_IS_ROUND_SIDE);
            ~MotorControl(void){};
            void setMotorFunction(int function, int waitAfterSet_ms=0);
            void getMotorFunction(int &funcM1, int &funcM2);
        private:
    };

// } /*mtrCtrl*/

#endif /*MOTORCONTROL_H*/
