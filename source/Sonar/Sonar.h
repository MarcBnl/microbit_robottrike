#ifndef SONAR_H
#define SONAR_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "MicroBitSerial.h"
#include "MicroBitSystemTimer.h"
#include "TimedInterruptIn.h"
#include "mbed.h"

#define SONAR_COMPONENT_RUNNING 0x1
#define SONAR_EVT_ECHO_RISE 1
#define SONAR_EVT_ECHO_FALL 2

    class Sonar : public MicroBitComponent
    {
        static const bool isDebugOn=true;
        static const int triggerDuration_us=2000000;//12;
        static const uint64_t triggerPeriod_ms=5000;//100;
        static const double speedOfSoundInAir_mps=331.2;//meters per sec
        static const double maxSonarRange_cm=400;
        DigitalInOut trigger;
        TimedInterruptIn echo;//InterruptIn echo;
        public:
            Sonar(void);
            ~Sonar(void);
            virtual void idleTick(void){ sendSerial("Sonar::idleTick");};
            virtual void systemTick(void);
            double distance_cm;
        private:
            unsigned int status;
            unsigned int nextTriggerTime;
            int systemTimerAddComponent(void);
            void echoPulseEvent(int eventValue);
            void onEchoRise(void);
            void onEchoFall(void);
            void startNewMeasurement(void);
            bool isNewTriggerNeeded(void);
            void newTrigger(void);
            void sendEvent(void);
            void sendSerial(const char* test);
    };

#endif /*SONAR_H*/
