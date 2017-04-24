#include "RobotTrikeManager.h"


    RobotTrikeManager::RobotTrikeManager(void)
    {

    };

    int RobotTrikeManager::systemTimerAddComponent(void)
    {
        int result=system_timer_add_component(this);// fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        if (result==MICROBIT_OK){
            sendSerial("RobotTrikeManager::MICROBIT_OK:fiber_add_idle_component");
            return MICROBIT_OK;
        }
        sendSerial("RobotTrikeManager::MICROBIT_NO_RESOURCES:fiber_add_idle_component");
        return result;
    };

    void RobotTrikeManager::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };