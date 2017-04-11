#include "Accelerometer.h"


    Accelerometer::Accelerometer(void)
    {
        sendSerial("Accelerometer::Accelerometer");
        systemTimerAddComponent();
    };

    Accelerometer::~Accelerometer(void)
    {
        system_timer_remove_component(this);// fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        status &= ~ACCELEROMETER_COMPONENT_RUNNING;
    };

    int Accelerometer::systemTimerAddComponent(void)
    {
        int result=system_timer_add_component(this);// fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        if (result==MICROBIT_OK){
            sendSerial("MICROBIT_OK:fiber_add_idle_component");
            status |=ACCELEROMETER_COMPONENT_RUNNING;
            return MICROBIT_OK;
        }
        sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
        return result;
    };

    void Accelerometer::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };