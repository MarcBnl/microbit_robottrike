#ifndef SONARCONTROL_H
#define SONARCONTROL_H

#include "source/Sonar/Sonar.h"

    class SonarControl 
    {
        public:
            SonarControl(void)
            {
                mySonar=new Sonar();
            };
            ~SonarControl(void)
            {
                delete mySonar;
            };
        private:
            Sonar* mySonar;
    };

#endif /*SONARCONTROL_H*/