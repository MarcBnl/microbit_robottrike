#include "MotorControl.h"

namespace mtrCtrl{

    MotorControl::MotorControl(void):
        motor1F(),
        motor2F()
    {      
        //FIXME
        motor1F.reverseDirections();
        //OR
        motor2F.reverseDirections();
    };

    void MotorControl::setMotorFunction(MOTORFUNCTIONS function)
    {
        switch (function){
            case COAST:
                motor1F.coast();
                motor2F.coast();
                break;
            case REVERSE:
                motor1F.reverse();
                motor2F.reverse();
                break;
            case FORWARD:
                motor1F.forward();
                motor2F.forward();
                break;
            case BRAKE:
                motor1F.brake();
                motor2F.brake();
                break;
            case SPIN:
                motor1F.forward();
                motor2F.reverse();
                wait_us(spinDuration_us);
                motor1F.coast();
                motor2F.coast();
                break;
            default:
        }
    };

    void MotorControl::getMotorFunction(MOTORFUNCTIONS &funcM1, MOTORFUNCTIONS &funcM2)
    {
        funcM1=motor1F.getFunction();
        funcM2=motor2F.getFunction();
    };

} /*mtrCtrl*/    