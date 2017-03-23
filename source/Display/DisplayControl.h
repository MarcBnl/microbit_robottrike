#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include "MicroBit.h"
#include "Defines.h"

// namespace dsplCtrl{

    class DisplayControl 
    {
        static const int colums=5;
        static const int rows=5;
        static const int motor1Col=0;
        static const int motor1Row=0;
        static const int motor2Col=4;
        static const int motor2Row=0; 
        static const int sonarCol=2;
        static const int sonarRow=0;      
        public:
            DisplayControl(void);
            DisplayControl(MicroBitMessageBus *msgBus);
            ~DisplayControl(void);
            MicroBitImage getDisplayImage(void);
            void updateMotorsInfo(int funcM1,int funcM2);
            // void updateMotor1Info(MicroBitEvent e);
            // void updateMotor2Info(MicroBitEvent e);
            void updateSonarInfo(int distancePercent);
        private:
            MicroBitMessageBus *ubitMsgBus;
            MicroBitImage displayImage;
            void updateMotor1Info(MicroBitEvent e);
            void updateMotor2Info(MicroBitEvent e);            
            void sendMessageToUpdateDisplay(void);
            void updateImageWithMotorInfo(int motorFunction, int col, int row);
    };

// } /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/