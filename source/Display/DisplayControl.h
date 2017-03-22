#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include "MicroBit.h"

namespace dsplCtrl{

    class DisplayControl 
    {
        static const int colums=5;
        static const int rows=5;
        static const int motor1Col=0;
        static const int motor1Row=0;
        static const int motor2Col=4;
        static const int motor2Row=0; 
        static const int sonarCol=3;
        static const int sonarRow=1;      
        public:
            DisplayControl(void);
            ~DisplayControl(void);
            MicroBitImage getDisplayImage(void);
            void updateMotorsInfo(int funcM1,int funcM2);
            void updateMotor1Info(MicroBitEvent e);
            void updateMotor2Info(MicroBitEvent e);
            void updateSonarInfo(int distancePercent);
        private:
            MicroBitImage displayImage;
            void sendMessageToUpdateDisplay(void);
            void updateGlobalDisplay(void);
            void updateImageWithMotorInfo(int motorFunction, int col, int row);
    };

} /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/