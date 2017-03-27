#include "Sonar.h"

    Sonar::Sonar(void):
        trigger(MICROBIT_PIN_P1),
        echo(MICROBIT_PIN_P2)
    {
        sendSerial("Sonar::Sonar");
        trigger.output();
        trigger.write(0);
        status=0;
        nextTriggerTime=0;
        distance=0.0;
        systemTimerAddComponent();
        echo.mode(PullUp);//FIXME:NEEDED??? or is PullNone oke?
        echo.rise(this,&Sonar::onEchoRise);
        echo.fall(this,&Sonar::onEchoFall);
    };

    Sonar::~Sonar(void)
    {
        system_timer_remove_component(this);// fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        status &= ~SONAR_COMPONENT_RUNNING;
    };

    void Sonar::systemTick(void)
    {
        // sendSerial("Sonar::systemTick");
        if (isNewTriggerNeeded()==true) startNewMeasurement();
    };

    void Sonar::echoPulseEvent(int eventValue)
    {
        // uint64_t now=system_timer_current_time_us();
        // if (eventValue==SONAR_EVT_ECHO_RISE){
        //     echo.setTimestamp(now);
        // };
        // if (eventValue==SONAR_EVT_ECHO_FALL){
        //     uint64_t echoPulseTime_us= now - echo.getTimestamp();
        //     if (echoPulseTime_us < (maxSonarRange_cm/speedOfSoundInAir_mps){
        //         distance_cm=(echoPulseTime_us*0.0000001)*speedOfSoundInAir_mps*(1/2);
        //     }else{
        //         distance_cm=maxSonarRange_cm;
        //     }
        //    sendEvent();
        // };
    };

    void Sonar::onEchoRise(void)
    {
        sendSerial("Sonar::onEchoRise");
        echoPulseEvent(SONAR_EVT_ECHO_RISE);
    };

    void Sonar::onEchoFall(void)
    {
        sendSerial("Sonar::onEchoFall");
        echoPulseEvent(SONAR_EVT_ECHO_FALL);
    };

    void Sonar::startNewMeasurement(void)
    {
        newTrigger();
        nextTriggerTime=system_timer_current_time()+triggerPeriod_ms;
    };

    bool Sonar::isNewTriggerNeeded(void)
    {
        return system_timer_current_time() >= nextTriggerTime;
    };

    void Sonar::newTrigger(void)
    {
        sendSerial("Sonar::newTrigger");
        trigger.write(0); wait_us(3);
        trigger.write(1); wait_us(triggerDuration_us);
        trigger.write(0);
    };

    int Sonar::systemTimerAddComponent(void)
    {
        int result=system_timer_add_component(this);// fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        if (result==MICROBIT_OK){
            sendSerial("MICROBIT_OK:fiber_add_idle_component");
            status |=SONAR_COMPONENT_RUNNING;
            return MICROBIT_OK;
        }
        sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
        return result;
    };

    void Sonar::sendEvent(void)
    {
        // MicroBitEvent evt;
        // double distancePercentage=distance_cm/maxSonarRange_cm;
        // if (distancePercentage < SONAR_EVT_5PRCNT) evt(SONAR_ID, SONAR_EVT_5PRCNT, CREATE_ONLY);
        // if ((distancePercentage > SONAR_EVT_5PRCNT) && (distancePercentage =< SONAR_EVT_25PRCNT)) evt(SONAR_ID, SONAR_EVT_25PRCNT, CREATE_ONLY);
        // if ((distancePercentage > SONAR_EVT_25PRCNT) && (distancePercentage =< SONAR_EVT_50PRCNT)) evt(SONAR_ID, SONAR_EVT_50PRCNT, CREATE_ONLY);
        // if ((distancePercentage > SONAR_EVT_50PRCNT) && (distancePercentage =< SONAR_EVT_75PRCNT)) evt(SONAR_ID, SONAR_EVT_75PRCNT, CREATE_ONLY);
        // if ((distancePercentage > SONAR_EVT_75PRCNT) && (distancePercentage =< SONAR_EVT_100PRCNT)) evt(SONAR_ID, SONAR_EVT_100PRCNT, CREATE_ONLY);
        // evt.fire();
    };

    void Sonar::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };
