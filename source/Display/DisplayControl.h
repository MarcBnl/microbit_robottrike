#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

#include "MicroBit.h"

namespace dsplCtrl{

    class DisplayControl {
        static const int motor1Col=0;
        static const int motor1Row=0;
        static const int motor2Col=4;
        static const int motor2Row=0;       
        public:
            DisplayControl(void);
            ~DisplayControl(void){};
            MicroBitImage getDisplayImage(void);
    // void updateDisplay(void);
            // void showMotorsFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2);
            void showMotorsFunction(int funcM1,int funcM2);
        private:
            MicroBitImage displayImage;
            void clearDisplay(void);
            void updateDisplay(void);
            // void pasteMotorImage(mtrCtrl::MTRFUNCTIONS funcM, int col, int row);
            void pasteMotorImage(int funcM, int col, int row);
    };

} /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/