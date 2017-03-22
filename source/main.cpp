#include "MicroBit.h"
#include <DigitalInOut.h>

#include "source/Display/DisplayControl.h"
#include "source/MotorDriver/MotorControl.h"

MicroBitDisplay display;

int main() {
    display.scroll("321");

    dsplCtrl::DisplayControl displCtrl;
    displCtrl.updateMotorsInfo(1,2);
    displCtrl.updateSonarInfo(150);
    display.print(displCtrl.getDisplayImage());

    while(1){
        fiber_sleep(500);
    }

	release_fiber();
}