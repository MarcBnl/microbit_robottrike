#include "MicroBit.h"

MicroBitDisplay display;

void quickTestMotors(void);

int main() {
    display.scroll("3.2.1");
    display.scrollAsync(Start...);
    quickTestMotors();
    display.scrollAsync(End...);
	release_fiber();
}

void quickTestMotors(void){
    //define pins
    MicroBitPin M1P8(MICROBIT_ID_IO_P8,MICROBIT_PIN_P8,PIN_CAPABILITY_BOTH);
    MicroBitPin M1P12(MICROBIT_ID_IO_P12,MICROBIT_PIN_P12,PIN_CAPABILITY_BOTH);
    MicroBitPin M2P0(MICROBIT_ID_IO_P0,MICROBIT_PIN_P0,PIN_CAPABILITY_BOTH);
    MicroBitPin M1P16(MICROBIT_ID_IO_P16,MICROBIT_PIN_P16,PIN_CAPABILITY_BOTH);
    //coast motors
    M1P8.setDigitalValue(0);
    M1P12.setDigitalValue(0);
    M2P0.setDigitalValue(0);
    M2P16.setDigitalValue(0);
    fiber_sleep(1000);
    //forward motor 1
    M1P8.setDigitalValue(1);
    fiber_sleep(5000);
    M1P8.setDigitalValue(0);
    // //reverse motor 1
    // M1P12.setDigitalValue(1);
    // fiber_sleep(5000);
    // M1P12.setDigitalValue(0);
    // //forward motor 2
    // M2P0.setDigitalValue(1);
    // fiber_sleep(5000);
    // M2P0.setDigitalValue(0);
    // //reverse motor 2
    // M2P16.setDigitalValue(1);
    // fiber_sleep(5000);
    // M2P16.setDigitalValue(0);
    // //coast motors
    M1P8.setDigitalValue(0);
    M1P12.setDigitalValue(0);
    M2P0.setDigitalValue(0);
    M2P16.setDigitalValue(0);    
};