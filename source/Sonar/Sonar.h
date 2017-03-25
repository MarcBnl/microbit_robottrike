#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "MicroBitEvent.h"
#include "mbed.h"

    class Sonar : public MicroBitComponent
    {
        static const int triggerDuration_us=3000000;//12;
        static const int triggerPeriod_ms=1000;//100;
        DigitalInOut trigger;
        InterruptIn echo;
        public:
            Sonar(void);
            ~Sonar(void);
            virtual void idleTick(void){};
            void fireTrigger(void);
        private:
            unsigned long nextTriggerTime;//sampleTime;
            bool isNextTriggerNeeded(void);
    };

#endif /*SONAR_H*/