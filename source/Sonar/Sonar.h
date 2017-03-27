#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "TimedInterruptIn.h"
#include "MicroBitSerial.h"
#include "mbed.h"

#define SONAR_COMPONENT_RUNNING 0x1

    class Sonar : public MicroBitComponent
    {
        static const bool isDebugOn=true;
        static const int triggerDuration_us=2000000;//12;
        static const int triggerPeriod_ms=5000;//100;
        static const double speedOfSoundInAir_mps=331.2;//meters/sec
        DigitalInOut trigger;
        InterruptIn echo;
        public:
            Sonar(void);
            ~Sonar(void);
            virtual void idleTick(void){ sendSerial("Sonar::idleTick");};
            virtual void systemTick(void);
        private:
            unsigned int status;
            unsigned int nextPingTime;
            void onEchoRise(void);
            void onEchoFall(void);
            void startNewMeasurement(void);
            bool isNewPingNeeded(void);
            void newPing(void);
            void sendSerial(const char* test);
    };

#endif /*SONAR_H*/