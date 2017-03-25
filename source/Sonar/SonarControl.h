#ifndef SONARCONTROL_H
#define SONARCONTROL_H

#include "source/Sonar/Sonar.h"

    class SonarControl 
    {
        Sonar mySonar;
        public:
            SonarControl(void):mySonar(){mySonar.fireTrigger();};
        private:
    };

#endif /*SONARCONTROL_H*/