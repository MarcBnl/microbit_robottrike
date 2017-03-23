#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "Defines.h"
#include "source/Motors/Motor1Function.h"
#include "source/Motors/Motor2Function.h"

// namespace mtrCtrl{

    enum MOTORFUNCTIONS {COAST=0,REVERSE=1,FORWARD=2,BRAKE=3,SPIN=4};

    class MotorControl 
    {
        static const int spinDuration_us=90000;
        Motor1Function motor1F;
        Motor2Function motor2F;
        public:
            MotorControl(void);
            ~MotorControl(void){};
            void setMotorFunction(int function);
            void getMotorFunction(int &funcM1, int &funcM2);
        private:
    };

// } /*mtrCtrl*/

#endif /*MOTORCONTROL_H*/
