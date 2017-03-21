#include "DisplayControl.h"

DisplayControl::DisplayControl(void):displayImage(){
    clearDisplay(displayImage);
};

void DisplayControl::clearDisplay(MicroBitImage image){
    image.clear();
    displayImage(image);
};

void DisplayControl::displayImage(MicroBitImage image){
    MicroBitDisplay display;
    display.print(image);
};

void DisplayControl::showMotorsFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2){
    pasteMotorImage(funcM1,motor1Col,motor1Row);
    pasteMotorImage(funcM2,motor2Col,motor2Row);
    displayImage(displayImage);
};

void DisplayControl::pasteMotorImage(mtrCtrl::MTRFUNCTIONS funcM, int col, int row){
    static const uint8_t   coast[]={0\n,0\n,1\n,0\n,0\n}; MicroBitImage coastImage(1,5,coast);
    static const uint8_t reverse[]={0\n,0\n,1\n,1\n,1\n}; MicroBitImage reverseImage(1,5,reverse);
    static const uint8_t forward[]={1\n,1\n,1\n,0\n,0\n}; MicroBitImage forwardImage(1,5,forward);
    static const uint8_t   brake[]={0\n,1\n,1\n,1\n,0\n}; MicroBitImage brakeImage(1,5,brake);

    MicroBitImage motorImage();
    case (funcM){
        case mtrCtrl::MTRFUNCTIONS::COAST:
            motorImage=coastImage; break;
        case mtrCtrl::MTRFUNCTIONS::REVERSE:
            motorImage=reverseImage; break;
        case mtrCtrl::MTRFUNCTIONS::FORWARD:
            motorImage=forwardImage; break;
        case mtrCtrl::MTRFUNCTIONS::BRAKE:
            motorImage=brakeImage; break;
        default:
    }
    displayImage.paste(motorImage,col,row);
};