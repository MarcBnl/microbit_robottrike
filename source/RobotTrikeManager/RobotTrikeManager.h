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
        public:
            RobotTrikeManager(void);
            ~RobotTrikeManager(void);
            virtual void idleTick(void){};
            virtual void systemTick(void){};
        private:

    };

#endif /*ROBOTTRIKEMANAGER_H*/