#include "Sonar.h"

    Sonar::Sonar(void):
        trigger(MICROBIT_PIN_P1),
        echo(MICROBIT_PIN_P2)
    {
        trigger.output();
        trigger.write(0);
        nextTriggerTime=0;
    };


    bool Sonar::isNextTriggerNeeded(void)
    {
        return system_timer_current_time() >= nextTriggerTime;
    };

    Sonar::~Sonar(void)
    {
        fiber_remove_idle_component(this);
    };

    void Sonar::fireTrigger(void)
    {
        trigger.write(0); wait_us(3);
        trigger.write(1); wait_us(triggerDuration_us);
        trigger.write(0);
    };