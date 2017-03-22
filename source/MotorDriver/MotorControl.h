#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "source/MotorDriver/Motor1Function.h"
#include "source/MotorDriver/Motor2Function.h"

namespace mtrCtrl{

    enum MOTORFUNCTIONS {COAST=0,REVERSE=1,FORWARD=2,BRAKE=3,SPIN};

    class MotorControl 
    {
        static const int spinDuration_us=50;
        Motor1Function motor1F;
        Motor2Function motor2F;
        public:
            MotorControl(void);
            ~MotorControl(void){};
            void setMotorFunction(MOTORFUNCTIONS function);
            void getMotorFunction(MOTORFUNCTIONS &funcM1, MTRFUNCTIONS &funcM2);
        private:
    };

} /*mtrCtrl*/

#endif /*MOTORCONTROL_H*/