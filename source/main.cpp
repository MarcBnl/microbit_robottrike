#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "DigitalInOut.h"
#include "mbed.h"

#include "Defines.h"
#include "source/Display/DisplayControl.h"
#include "source/Motors/MotorControl.h"


// #define MICROBIT_ID_MOTOR1 151
// #define MICROBIT_ID_MOTOR2 152
// #define MICROBIT_MOTOR_FUNCTION_EVT_COAST   0
// #define MICROBIT_MOTOR_FUNCTION_EVT_REVERSE 1
// #define MICROBIT_MOTOR_FUNCTION_EVT_FORWARD 2
// #define MICROBIT_MOTOR_FUNCTION_EVT_BRAKE   3

// void displayUpdate(MicroBitEvent);

InterruptIn buttonA(MICROBIT_PIN_BUTTON_A);
DigitalOut led(MICROBIT_PIN_P1);
void flipLed(void){
    led.write(!led.read());
};

/*GLOBAL RUNTIME COMPONENTS*/
MicroBitMessageBus msgBus;
MicroBitDisplay display;
/*GLOBAL OBJECTS*/
DisplayControl displCtrl(&msgBus,&display);

int main() {
    display.scroll("321");    

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
    mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_FORWARD);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_REVERSE);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_COAST);fiber_sleep(1000);//ms
    mtrCtrl.setMotorFunction(MOTOR_FUNCTION_EVT_SPIN);

    /*InterruptIn trail*/
    buttonA.rise(&flipLed)
    led.output();
    led.write(1);


    /*DON'T JUMP OUT OF MAIN*/
    while(1){
        fiber_sleep(500);//ms        
    }
	release_fiber();
}


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