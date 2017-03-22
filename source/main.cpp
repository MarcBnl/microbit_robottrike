#include "MicroBit.h"
#include <DigitalInOut.h>

#include "source/Display/DisplayControl.h"
#include "source/MotorDriver/MotorControl.h"

#define MICROBIT_ID_TEST 1234
#define MICROBIT_DISPLAY_EVT_UPDATE 1

void displayUpdate(MicroBitEvent);

/*GLOBAL RUNTIME COMPONENTS*/
MicroBitMessageBus msgBus;
MicroBitDisplay display;
/*GLOBAL OBJECTS*/
dsplCtrl::DisplayControl displCtrl;

int main() {
    display.scroll("321");

    msgBus.listen(MICROBIT_ID_TEST,MICROBIT_DISPLAY_EVT_UPDATE,displayUpdate);
    
    displCtrl.updateMotorsInfo(MICROBIT_MOTOR_FUNCTION_EVT_FORWARD,mtrCtrl::MOTORFUNCTIONS.REVERSE);
    displCtrl.updateSonarInfo(150);
    display.print(displCtrl.getDisplayImage());
    fiber_sleep(3000);//ms 

    displCtrl.updateSonarInfo(15);
    MicrobitEvent evt(MICROBIT_ID_TEST, MICROBIT_DISPLAY_EVT_UPDATE);//creates and sends
    fiber_sleep(3000);//ms 

    while(1){
        fiber_sleep(500);//ms        
    }
	release_fiber();
}

void displayUpdate(MicroBitEvent)
{
    //https://lancaster-university.github.io/microbit-docs/ubit/messageBus/
    display.print(displCtrl.getDisplayImage());
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