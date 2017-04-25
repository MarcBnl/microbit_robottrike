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
/*GLOBAL OBJECTS*/
// DisplayControl displCtrl(&msgBus,&display);
// MotorControl mtrCtrl;
// AccelerometerControl accelerometerCtrl(&accelerometer);
//SonarControl snrCtrl;

int main() {

    DisplayControl displCtrl(&msgBus,&display);
    MotorControl mtrCtrl;
    AccelerometerControl accelerometerCtrl(&accelerometer);

    while (accelerometerCtrl.isCalibrated == false){fiber_sleep(1);}

    int const collisionsMax=5;
    int collisions=0;
    while(collisions<=collisionsMax){
        mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_FORWARD);
        
        while(accelerometerCtrl.isMoving == true){
            fiber_sleep(3);//ms 
        }

        collisions+=1;
        mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST,100);
        mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_REVERSE,500);
        mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_SPIN,100);
    }

    /*DON'T JUMP OUT OF MAIN*/
    displCtrl.clearDisplay();
    while(1){
        display.print("+");
        fiber_sleep(1000);//ms   
        display.print("x");
    }
	release_fiber();

    //OLD STUFF BELOW FOR DEBUGGING

    //display.scroll("321");   

    // displCtrl.updateSonarInfo(150);fiber_sleep(1000);//ms 
    // displCtrl.updateSonarInfo(80);fiber_sleep(1000);//ms
    // displCtrl.updateSonarInfo(70);fiber_sleep(1000);//ms
    // displCtrl.updateSonarInfo(25);fiber_sleep(1000);//ms
    // displCtrl.updateMotorsInfo(2,3);
    // displCtrl.updateSonarInfo(150);
    // fiber_sleep(3000);//ms 
    // displCtrl.updateMotorsInfo(1,1);
    // fiber_sleep(3000);//ms
    // displCtrl.updateSonarInfo(50);
    // MicroBitEvent evt(MICROBIT_ID_TEST, MICROBIT_DISPLAY_EVT_UPDATE);
    // fiber_sleep(3000);//ms 


    // MotorControl mtrCtrl;
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_FORWARD);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_REVERSE);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_FORWARD);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_REVERSE);
    //  mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);
    // mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_TURNBACKRIGHT);
    // mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_TURNBACKLEFT);
    // mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_SPIN);
}
