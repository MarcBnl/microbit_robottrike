#include "Sonar.h"

    Sonar::Sonar(void):
        trigger(MICROBIT_PIN_P1),
        echo(MICROBIT_PIN_P2)
    {
        sendSerial("Sonar::Sonar");
        trigger.output();
        trigger.write(0);
        status=0;

        // fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        int result=system_timer_add_component(this);
        if (result==MICROBIT_OK)sendSerial("MICROBIT_OK:fiber_add_idle_component");
        if (result==MICROBIT_NO_RESOURCES)sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
    };

    void Sonar::systemTick(void)
    {
        // sendSerial("Sonar::systemTick");
    };

    void Sonar::idleTick(void)
    {
        sendSerial("Sonar::idleTick");
    };

    Sonar::~Sonar(void)
    {
        sendSerial("Sonar::~Sonar");
        system_timer_remove_component(this);
        // fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
    };

    void Sonar::fireTrigger(void)
    {
        sendSerial("Sonar::fireTrigger");
        trigger.write(0); wait_us(3);
        trigger.write(1); wait_us(triggerDuration_us);
        trigger.write(0);
        status |= SONAR_PING_ACTIVE;
    };

    void Sonar::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };
