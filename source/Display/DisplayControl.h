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
        public:
            DisplayControl(void);
            ~DisplayControl(void){};
            MicroBitImage getDisplayImage(void);
            void updateMotorsInfo(int funcM1,int funcM2);
        private:
            MicroBitImage displayImage;
            void updateImageWithMotorInfo(int funcM, int col, int row);
    };

} /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/