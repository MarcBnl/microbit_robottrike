#ifndef SONARCONTROL_H
#define SONARCONTROL_H

#include "source/Sonar/Sonar.h"

    class SonarControl 
    {
        public:
            SonarControl(void)
            {
                mySonar=new Sonar();
                int result=system_timer_add_component(mySonar);
                if (result==MICROBIT_OK)mySonar->sendSerial("MICROBIT_OK:fiber_add_idle_component");
                if (result==MICROBIT_NO_RESOURCES)mySonar->sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
            };
            ~SonarControl(void)
            {
                system_timer_remove_component(mySonar);
            };
        private:
            Sonar* mySonar;
    };

#endif /*SONARCONTROL_H*/