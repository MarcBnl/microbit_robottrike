#include "Sonar.h"

    Sonar::Sonar(void):
        trigger(MICROBIT_PIN_P1),
        echo(MICROBIT_PIN_P2)
    {
        sendSerial("Sonar::Sonar");
        trigger.output();
        trigger.write(0);

        int result=fiber_add_idle_component(this);
        if (result==MICROBIT_OK)sendSerial("MICROBIT_OK:fiber_add_idle_component");
    };

    void Sonar::idleTick(void)
    {
        sendSerial("Sonar::idleTick");
    };

    Sonar::~Sonar(void)
    {
        sendSerial("Sonar::~Sonar");
        fiber_remove_idle_component(this);
    };

    void Sonar::fireTrigger(void)
    {
        sendSerial("Sonar::fireTrigger");
        trigger.write(0); wait_us(3);
        trigger.write(1); wait_us(triggerDuration_us);
        trigger.write(0);
    };

    void Sonar::sendSerial(const char* text)
    {
        if (!debugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };
