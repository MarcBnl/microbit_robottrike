#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "source/MotorDriver/Motor1Function.h"
#include "source/MotorDriver/Motor2Function.h"

#define MICROBIT_ID_MOTOR1 151
#define MICROBIT_ID_MOTOR2 152
#define MICROBIT_MOTOR_FUNCTION_EVT_COAST   0
#define MICROBIT_MOTOR_FUNCTION_EVT_REVERSE 1
#define MICROBIT_MOTOR_FUNCTION_EVT_FORWARD 2
#define MICROBIT_MOTOR_FUNCTION_EVT_BRAKE   3
#define MICROBIT_MOTOR_FUNCTION_EVT_SPIN    4

namespace mtrCtrl{

    enum MOTORFUNCTIONS {COAST=0,REVERSE=1,FORWARD=2,BRAKE=3,SPIN=4};

    class MotorControl 
    {
        static const int spinDuration_us=50;
        Motor1Function motor1F;
        Motor2Function motor2F;
        public:
            MotorControl(void);
            ~MotorControl(void){};
            void setMotorFunction(MOTORFUNCTIONS function);
            void getMotorFunction(MOTORFUNCTIONS &funcM1, MOTORFUNCTIONS &funcM2);
        private:
    };

} /*mtrCtrl*/

#endif /*MOTORCONTROL_H*/
