#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "TimedInterruptIn.h"
#include "MicroBitEvent.h"
#include "MicroBitSerial.h"
#include "MicroBitConfig.h"
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
            virtual void systemTick(void);
            void fireTrigger(void);
            void sendSerial(const char* test);
        private:
            
    };

#endif /*SONAR_H*/