#include "MotorControl.h"

// namespace mtrCtrl{

    MotorControl::MotorControl(void):
        motor1F(),
        motor2F()
    {      
        //FIXME
        motor1F.reverseDirections();
        //OR
        //motor2F.reverseDirections();
    };

    void MotorControl::setMotorFunction(int function)
    {
        switch (function){
            case MOTOR_FUNCTION_EVT_COAST:
                motor1F.coast();
                motor2F.coast();
                break;
            case MOTOR_FUNCTION_EVT_REVERSE:
                motor1F.reverse();
                motor2F.reverse();
                break;
            case MOTOR_FUNCTION_EVT_FORWARD:
                motor1F.forward();
                motor2F.forward();
                break;
            case MOTOR_FUNCTION_EVT_BRAKE:
                motor1F.brake();
                motor2F.brake();
                break;
            case MOTOR_FUNCTION_EVT_SPIN:
                motor1F.forward();
                motor2F.reverse();
                wait_us(spinDuration_us);
                motor1F.coast();
                motor2F.coast();
                break;
            default:
                motor1F.coast();
                motor2F.coast();
                break;
        }
    };

    void MotorControl::getMotorFunction(int &funcM1, int &funcM2)
    {
        funcM1=motor1F.getFunction();
        funcM2=motor2F.getFunction();
    };

// } /*mtrCtrl*/    