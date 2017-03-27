#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "TimedInterruptIn.h"
#include "MicroBitSerial.h"
#include "mbed.h"

#define SONAR_PING_ACTIVE 0x1
#define SONAR_PING_FIRE   0x2

    class Sonar : public MicroBitComponent
    {
        static const bool isDebugOn=true;
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
            unsigned int status;
            unsigned int nextPingTime;//system_timer_current_time()

    };

#endif /*SONAR_H*/