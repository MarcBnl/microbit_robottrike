#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "TimedInterruptIn.h"
#include "MicroBitEvent.h"
#include "MicroBitSerial.h"
#include "mbed.h"

    class Sonar : public MicroBitComponent
    {
        static const bool debugOn=true;
        static const int triggerDuration_us=2000000;//12;
        static const int triggerPeriod_ms=5000;//100;
        DigitalInOut trigger;
        InterruptIn echo;
        public:
            Sonar(void);
            ~Sonar(void);
            virtual void idleTick(void);
            void fireTrigger(void);
        private:
            void sendSerial(const char* test);
    };

#endif /*SONAR_H*/