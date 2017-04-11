#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "MicroBitSerial.h"
#include "MicroBitSystemTimer.h"
#include "TimedInterruptIn.h"
#include "mbed.h"
#include "Defines.h"

#define ACCELEROMETER_COMPONENT_RUNNING 0x1

    class Accelerometer : public MicroBitComponent
    {
        public:
            Accelerometer(void);
            ~Accelerometer(void);
            virtual void idleTick(void){sendSerial("Accelerometer::idleTick");};
            virtual void systemTick(void){sendSerial("Accelerometer::systemTick");};
        private:
            unsigned int status;
            int systemTimerAddComponent(void);
            void sendSerial(const char* text);
    };

#endif /*ACCELEROMETER_H*/