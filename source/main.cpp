/*
WARNING
=======
micro:bit runtime components should always be brought up as global variables.
They should not be created as local variables - either in your main method or 
anywhere else. The reason for this is the the runtime is a multi-threaded 
environment, and any variables created in stack memory (like local variables) 
may be paged out by the scheduler, and result in instability if they utilise 
interrupts or are accessed by other threads. So... don't do it!
*/

#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "DigitalInOut.h"
#include "mbed.h"

#include "Defines.h"
#include "source/Display/DisplayControl.h"
#include "source/Motors/MotorControl.h"
#include "source/Sonar/SonarControl.h"
#include "source/Sonar/Sonar.h"
#include "source/Accelerometer/AccelerometerControl.h"
#include "source/RobotTrikeManager/RobotTrikeManager.h"

/*GLOBAL RUNTIME COMPONENTS*/
MicroBitMessageBus msgBus;
MicroBitDisplay display;
MicroBitI2C i2c = MicroBitI2C(I2C_SDA0, I2C_SCL0);
MicroBitAccelerometer accelerometer = MicroBitAccelerometer(i2c); 

int main() {

    DisplayControl displCtrl(&msgBus,&display);
    MotorControl mtrCtrl(FRONT_IS_FLAT_SIDE);
    AccelerometerControl accelerometerCtrl(&accelerometer);
    //SonarControl snrCtrl;

    while (accelerometerCtrl.isCalibrated == false){fiber_sleep(1);}

    int const collisionsMax=5;
    int collisions=0;
    int notMovingDebounceCounter=0;
    while(collisions<=collisionsMax){
        mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_FORWARD);
        fiber_sleep(3);//ms 

        if (accelerometerCtrl.isMoving == false) notMovingDebounceCounter+=1;

        if (notMovingDebounceCounter==2){
            collisions+=1;
            mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST,100);
            mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_REVERSE,200);
            mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_SPIN,100);
            notMovingDebounceCounter=0;
        }
    }

    /*DON'T JUMP OUT OF MAIN*/
    displCtrl.clearDisplay();
    while(1){
        display.print("+");
        fiber_sleep(1000);//ms   
        display.print("x");
    }
	release_fiber();
}
