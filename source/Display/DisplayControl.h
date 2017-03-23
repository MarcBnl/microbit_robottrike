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
            DisplayControl(MicroBitMessageBus *msgBus,MicroBitDisplay *display);
            ~DisplayControl(void);
        private:
            MicroBitMessageBus *ubitMsgBus;
            MicroBitDisplay *ubitDisplay;
            MicroBitImage displayImage;
            void updateMotor1Info(MicroBitEvent e);
            void updateMotor2Info(MicroBitEvent e);            
            void updateImageWithMotorInfo(int motorFunction, int col, int row);
            void updateSonarInfo(MicroBitEvent e);
            void updateImageWithSonarInfo(int distanceNr);
    };

// } /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/