#include "DisplayControl.h"


#define MICROBIT_ID_MOTOR1 151
#define MICROBIT_ID_MOTOR2 152
#define MICROBIT_MOTOR_FUNCTION_EVT_COAST   0
#define MICROBIT_MOTOR_FUNCTION_EVT_REVERSE 1
#define MICROBIT_MOTOR_FUNCTION_EVT_FORWARD 2
#define MICROBIT_MOTOR_FUNCTION_EVT_BRAKE   3
#define MICROBIT_MOTOR_FUNCTION_EVT_SPIN    4

// namespace dsplCtrl{

    DisplayControl::DisplayControl(void):
        displayImage(colums,rows)
    {
        displayImage.clear();
        MicroBitMessageBus msg;
        msg.listen(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        msg.listen(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);
    };

    DisplayControl::~DisplayControl(void)
    {
        MicroBitMessageBus msg;
        msg.ignore(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR1, MICROBIT_MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        msg.ignore(MICROBIT_ID_MOTOR2, MICROBIT_MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);        
    }

    MicroBitImage DisplayControl::getDisplayImage(void)
    {
        return displayImage;
    };

    void DisplayControl::sendMessageToUpdateDisplay(void)
    {
        MicroBitEvent evt(4321,1);//MICROBIT_ID_TEST, MICROBIT_DISPLAY_EVT_UPDATE);
    };

    void DisplayControl::updateMotorsInfo(int funcM1, int funcM2)
    {
        updateImageWithMotorInfo(funcM1,motor1Col,motor1Row);
        updateImageWithMotorInfo(funcM2,motor2Col,motor2Row);
    };

    void DisplayControl::updateMotor1Info(MicroBitEvent e)
    {
        if (e.value==2)//MICROBIT_MOTOR_FUNCTION_EVT_FORWARD)
            updateImageWithMotorInfo(2,motor1Col,motor1Row);
        else if (e.value==1)//MICROBIT_MOTOR_FUNCTION_EVT_REVERSE)
            updateImageWithMotorInfo(1,motor1Col,motor1Row);
        else if (e.value==0)//MICROBIT_MOTOR_FUNCTION_EVT_COAST) 
            updateImageWithMotorInfo(0,motor1Col,motor1Row);
        else if (e.value==3)//MICROBIT_MOTOR_FUNCTION_EVT_BRAKE)
            updateImageWithMotorInfo(3,motor1Col,motor1Row);
        else{};
    };

    void DisplayControl::updateMotor2Info(MicroBitEvent e)
    {
        if (e.value==2)//MICROBIT_MOTOR_FUNCTION_EVT_FORWARD)
            updateImageWithMotorInfo(2,motor2Col,motor2Row);
        else if (e.value==1)//MICROBIT_MOTOR_FUNCTION_EVT_REVERSE)
            updateImageWithMotorInfo(1,motor2Col,motor2Row);
        else if (e.value==0)//MICROBIT_MOTOR_FUNCTION_EVT_COAST) 
            updateImageWithMotorInfo(0,motor2Col,motor2Row);
        else if (e.value==3)//MICROBIT_MOTOR_FUNCTION_EVT_BRAKE)
            updateImageWithMotorInfo(3,motor2Col,motor2Row);
        else{};
    };

    void DisplayControl::updateSonarInfo(int distancePercent)
    {
        static const uint8_t _100[]={1,1,1,1,1}; MicroBitImage _100Image(1,5,_100);
        static const uint8_t  _75[]={0,1,1,1,1}; MicroBitImage _75Image(1,5,_75);
        static const uint8_t  _50[]={0,0,1,1,1}; MicroBitImage _50Image(1,5,_50);
        static const uint8_t  _25[]={0,0,0,1,1}; MicroBitImage _25Image(1,5,_25);
        static const uint8_t  _20[]={0,0,0,0,1}; MicroBitImage _20Image(1,5,_20);
        static const uint8_t   _0[]={0,0,0,0,0}; MicroBitImage _0Image(1,5,_0);
        if (distancePercent<=20) 
            displayImage.paste(_0Image,sonarCol,sonarRow);
        else if (distancePercent<=25) 
            displayImage.paste(_20Image,sonarCol,sonarRow);
        else if (distancePercent<=50) 
            displayImage.paste(_25Image,sonarCol,sonarRow);
        else if (distancePercent<=75) 
            displayImage.paste(_50Image,sonarCol,sonarRow);
        else if (distancePercent<=100) 
            displayImage.paste(_75Image,sonarCol,sonarRow);
        else 
            displayImage.paste(_100Image,sonarCol,sonarRow);
        sendMessageToUpdateDisplay();
    };

    void DisplayControl::updateImageWithMotorInfo(int motorFunction, int col, int row)
    {
        static const uint8_t   coast[]={0,0,1,0,0}; MicroBitImage coastImage(1,5,coast);
        static const uint8_t reverse[]={0,0,1,1,1}; MicroBitImage reverseImage(1,5,reverse);
        static const uint8_t forward[]={1,1,1,0,0}; MicroBitImage forwardImage(1,5,forward);
        static const uint8_t   brake[]={0,1,1,1,0}; MicroBitImage brakeImage(1,5,brake);

        //FIXME:
        //USE THE ENUM MOTORFUNCTIONS FROM MOTORCONTROL
        MicroBitImage motorImage();
        switch (motorFunction){
            case 0://MICROBIT_MOTOR_FUNCTION_EVT_COAST:
                displayImage.paste(coastImage,col,row); break;
            case 1://MICROBIT_MOTOR_FUNCTION_EVT_REVERSE:
                displayImage.paste(reverseImage,col,row); break;
            case 2://MICROBIT_MOTOR_FUNCTION_EVT_FORWARD:
                displayImage.paste(forwardImage,col,row); break;
            case 3://MICROBIT_MOTOR_FUNCTION_EVT_BRAKE:
                displayImage.paste(brakeImage,col,row); break;
            default:
                break;
        }
        sendMessageToUpdateDisplay();
    };

// } /*dsplCtrl*/