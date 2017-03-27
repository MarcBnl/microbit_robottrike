#include "Sonar.h"

    Sonar::Sonar(void):
        trigger(MICROBIT_PIN_P1),
        echo(MICROBIT_PIN_P2)
    {
        sendSerial("Sonar::Sonar");
        trigger.output();
        trigger.write(0);
        status=0;
        nextPingTime=0;
        int result=system_timer_add_component(this);// fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        if (result==MICROBIT_OK) status |=SONAR_COMPONENT_RUNNING;
        echo.mode(PullUp);//FIXME:NEEDED??? or is PullNone oke?
        echo.rise(this,&Sonar::onEchoRise);
        echo.fall(this,&Sonar::onEchoFall);

        if (result==MICROBIT_OK)sendSerial("MICROBIT_OK:fiber_add_idle_component");
        if (result==MICROBIT_NO_RESOURCES)sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
    };

    Sonar::~Sonar(void)
    {
        system_timer_remove_component(this);// fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        status &= ~SONAR_COMPONENT_RUNNING;
    };

    void Sonar::systemTick(void)
    {
        // sendSerial("Sonar::systemTick");
        if (isNewPingNeeded()==true) startNewMeasurement();
    };

    void Sonar::onEchoRise(void)
    {
        sendSerial("Sonar::onEchoRise");
    };

    void Sonar::onEchoFall(void)
    {
        sendSerial("Sonar::onEchoFall");
    };

    void Sonar::startNewMeasurement(void)
    {
        newPing();
        nextPingTime=system_timer_current_time()+triggerPeriod_ms;
    };

    bool Sonar::isNewPingNeeded(void)
    {
        return system_timer_current_time() >= nextPingTime;
    };

    void Sonar::newPing(void)
    {
        sendSerial("Sonar::fireTrigger");
        trigger.write(0); wait_us(3);
        trigger.write(1); wait_us(triggerDuration_us);
        trigger.write(0);
    };

    void Sonar::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };
