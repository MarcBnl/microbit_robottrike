#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "DigitalInOut.h"

#include "Defines.h"
#include "source/Display/DisplayControl.h"
#include "source/Motors/MotorControl.h"

#define MICROBIT_ID_TEST 4321
#define MICROBIT_DISPLAY_EVT_UPDATE 1

#define MICROBIT_ID_MOTOR1 151
#define MICROBIT_ID_MOTOR2 152
#define MICROBIT_MOTOR_FUNCTION_EVT_COAST   0
#define MICROBIT_MOTOR_FUNCTION_EVT_REVERSE 1
#define MICROBIT_MOTOR_FUNCTION_EVT_FORWARD 2
#define MICROBIT_MOTOR_FUNCTION_EVT_BRAKE   3

void displayUpdate(MicroBitEvent);
// void motor1DisplayUpdate(MicroBitEvent e);
// void motor2DisplayUpdate(MicroBitEvent e);

/*GLOBAL RUNTIME COMPONENTS*/
MicroBitMessageBus msgBus;
MicroBitDisplay display;
/*GLOBAL OBJECTS*/
// DisplayControl displCtrl;//MOVED INTO MAIN FOR THE NEW CONSTRUCTOR WITH MESSAGEBUS

int main() {
    display.scroll("321");

    msgBus.listen(MICROBIT_ID_TEST,MICROBIT_DISPLAY_EVT_UPDATE,displayUpdate); 

    DisplayControl displCtrl(&msgBus);
    // msgBus.listen(MICROBIT_ID_MOTOR1,MICROBIT_MOTOR_FUNCTION_EVT_COAST,motor1DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR1,MICROBIT_MOTOR_FUNCTION_EVT_REVERSE,motor1DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR1,MICROBIT_MOTOR_FUNCTION_EVT_FORWARD,motor1DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR1,MICROBIT_MOTOR_FUNCTION_EVT_BRAKE,motor1DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR2,MICROBIT_MOTOR_FUNCTION_EVT_COAST,motor2DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR2,MICROBIT_MOTOR_FUNCTION_EVT_REVERSE,motor2DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR2,MICROBIT_MOTOR_FUNCTION_EVT_FORWARD,motor2DisplayUpdate);
    // msgBus.listen(MICROBIT_ID_MOTOR2,MICROBIT_MOTOR_FUNCTION_EVT_BRAKE,motor2DisplayUpdate);    

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

    MotorControl mtrCtrl;
    mtrCtrl.setMotorFunction(2);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(0);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(1);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(0);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(4);fiber_sleep(1000);//ms

    /*DON'T JUMP OUT OF MAIN*/
    while(1){
        fiber_sleep(500);//ms        
    }
	release_fiber();
}

void displayUpdate(MicroBitEvent)
{
    //https://lancaster-university.github.io/microbit-docs/ubit/messageBus/
    // display.print(displCtrl.getDisplayImage());
    display.printAsync(displCtrl.getDisplayImage());
}

// void motor1DisplayUpdate(MicroBitEvent e)
// {
//     displCtrl.updateMotor1Info(e);
// }

// void motor2DisplayUpdate(MicroBitEvent e)
// {
//     displCtrl.updateMotor2Info(e);
// }
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