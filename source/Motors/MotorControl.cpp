#include "MotorControl.h"

// namespace mtrCtrl{

    MotorControl::MotorControl(int whatIsFront):
        motor1F(),
        motor2F()
    {
        if (whatIsFront==FRONT_IS_ROUND_SIDE) motor1F.reverseDirections();
        if (whatIsFront==FRONT_IS_FLAT_SIDE) motor2F.reverseDirections();
    };

    void MotorControl::setMotorFunction(int function, int waitAfterSet_ms)
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
            case MOTOR_FUNCTION_EVT_TURNBACKRIGHT:
                motor1F.brake();
                motor2F.reverse();
                wait_us(turnDuration_us);
                motor1F.coast();
                motor2F.coast();
                break;
            case MOTOR_FUNCTION_EVT_TURNBACKLEFT:
                motor1F.reverse();
                motor2F.brake();
                wait_us(turnDuration_us);
                motor1F.coast();
                motor2F.coast();
                break;
            default:
                motor1F.coast();
                motor2F.coast();
                break;
        }
        fiber_sleep(waitAfterSet_ms);//ms
    };

    void MotorControl::getMotorFunction(int &funcM1, int &funcM2)
    {
        funcM1=motor1F.getFunction();
        funcM2=motor2F.getFunction();
    };

// } /*mtrCtrl*/    