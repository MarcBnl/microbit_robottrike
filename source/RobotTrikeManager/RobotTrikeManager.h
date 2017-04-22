#ifndef ROBOTTRIKEMANAGER_H
#define ROBOTTRIKEMANAGER_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "MicroBitSystemTimer.h"
#include "TimedInterruptIn.h"
#include "mbed.h"
#include "Defines.h"

    class RobotTrikeManager : public MicroBitComponent
    {
        static const bool isDebugOn=false;
        public:
            RobotTrikeManager(void){};
            ~RobotTrikeManager(void){};
            virtual void idleTick(void){};
            virtual void systemTick(void){};
        private:
            int systemTimerAddComponent(void);
            void sendSerial(const char* text);
    };

#endif /*ROBOTTRIKEMANAGER_H*/