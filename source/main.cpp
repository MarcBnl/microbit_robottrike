#include "MicroBit.h"
#include <DigitalInOut.h>

#include "source/Display/DisplayControl.h"
#include "source/MotorDriver/MotorControl.h"

MicroBitDisplay display;

int main() {
    display.scroll("321");

    // DigitalInOut P0(MICROBIT_PIN_P0);P0.output();
    // DigitalInOut P16(MICROBIT_PIN_P16);P16.output();
    // DigitalInOut P8(MICROBIT_PIN_P8);P8.output();
    // DigitalInOut P12(MICROBIT_PIN_P12);P12.output();
    // P0.write(1);
    // P16.write(0);
    // P8.write(1);
    // P12.write(0);

// const uint8_t   coast[]={0,0,1,0,0}; MicroBitImage coastImage(1,5,coast);
// const uint8_t reverse[]={0,0,1,1,1}; MicroBitImage reverseImage(1,5,reverse);
// MicroBitImage displayImage(5,5);
// displayImage.paste(coastImage,0,0);
// displayImage.paste(reverseImage,4,0);
// display.print(displayImage);
// fiber_sleep(50000);

    dsplCtrl::DisplayControl dpc;
    dpc.showMotorsFunction(1,2);
// fiber_sleep(50000);

    display.print(dpc.getDisplayImage());

    while(1){
        fiber_sleep(500);
    }


	release_fiber();
}