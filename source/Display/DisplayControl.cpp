#include "DisplayControl.h"

namespace dsplCtrl{

    DisplayControl::DisplayControl(void):displayImage(5,5){
        // clearDisplay();
        displayImage.clear();
    };

    void DisplayControl::clearDisplay(void){
        // displayImage.clear();
        // updateDisplay();
    };

    void DisplayControl::updateDisplay(void){
        MicroBitDisplay display;
        display.print(displayImage);
        // fiber_sleep(500);
    };

    MicroBitImage DisplayControl::getDisplayImage(void){
        return displayImage;
    };

    // void DisplayControl::showMotorsFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2){
        void DisplayControl::showMotorsFunction(int funcM1, int funcM2){
        pasteMotorImage(funcM1,motor1Col,motor1Row);
        pasteMotorImage(funcM2,motor2Col,motor2Row);
        updateDisplay();
    };

    // void DisplayControl::pasteMotorImage(mtrCtrl::MTRFUNCTIONS funcM, int col, int row){
        void DisplayControl::pasteMotorImage(int funcM, int col, int row){
        static const uint8_t   coast[]={0,0,1,0,0}; MicroBitImage coastImage(1,5,coast);
        static const uint8_t reverse[]={0,0,1,1,1}; MicroBitImage reverseImage(1,5,reverse);
        static const uint8_t forward[]={1,1,1,0,0}; MicroBitImage forwardImage(1,5,forward);
        static const uint8_t   brake[]={0,1,1,1,0}; MicroBitImage brakeImage(1,5,brake);

        MicroBitImage motorImage();
        switch (funcM){
            case 0://mtrCtrl::MTRFUNCTIONS::COAST:
                //motorImage=coastImage; break;
                displayImage.paste(coastImage,col,row); break;
            case 1://mtrCtrl::MTRFUNCTIONS::REVERSE:
                //motorImage=reverseImage; break;
                displayImage.paste(reverseImage,col,row); break;
            case 2://mtrCtrl::MTRFUNCTIONS::FORWARD:
                //motorImage=forwardImage; break;
                displayImage.paste(forwardImage,col,row); break;
            case 3://mtrCtrl::MTRFUNCTIONS::BRAKE:
                //motorImage=brakeImage; break;
                displayImage.paste(brakeImage,col,row); break;
            default:
                break;
        }
    };

} /*dsplCtrl*/