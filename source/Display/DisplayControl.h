#ifndef DISPLAYCONTROL_H
#define DISPLAYCONTROL_H

namespace dsplCtrl{

    class DisplayControl {
        static const int motor1Col=0;
        static const int motor1Row=0;
        static const int motor2Col=4;
        static const int motor2Row=0; 
        static MicroBitImage displayImage;       
        public:
            DisplayControl(void);
            ~DisplayControl(void){};
            void showMotorsFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2);
        private:
            void clearDisplay(void);
            void displayImage(MicroBitImage image);
            void pasteMotorImage(mtrCtrl::MTRFUNCTIONS funcM, int col, int row);
    }

} /*dsplCtrl*/

#endif /*DISPLAYCONTROL_H*/