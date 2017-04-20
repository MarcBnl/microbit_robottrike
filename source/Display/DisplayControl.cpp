#include "DisplayControl.h"

// namespace dsplCtrl{

    DisplayControl::DisplayControl(MicroBitMessageBus *msgBus,MicroBitDisplay *display):
        displayImage(colums,rows)
    {
        displayImage.clear();
        ubitMsgBus=msgBus;
        ubitDisplay=display;

        ubitMsgBus->listen(MOTOR1_ID, MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->listen(MOTOR1_ID, MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->listen(MOTOR1_ID, MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->listen(MOTOR1_ID, MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);

        ubitMsgBus->listen(MOTOR2_ID, MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->listen(MOTOR2_ID, MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->listen(MOTOR2_ID, MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->listen(MOTOR2_ID, MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor2Info);

        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_PING, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_0PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_5PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_25PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_50PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_75PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->listen(SONAR_ID, SONAR_EVT_100PRCNT, this, &DisplayControl::updateSonarInfo);

        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_IDLE, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_STILL, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_CALIBRATING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_VECTORING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_MOVING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->listen(ACCELEROMETER_ID, ACCELEROMETER_EVT_COLLISION, this, &DisplayControl::updateAccelerometerInfo);
    };

    DisplayControl::~DisplayControl(void)
    {
        ubitMsgBus->ignore(MOTOR1_ID, MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->ignore(MOTOR1_ID, MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->ignore(MOTOR1_ID, MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor1Info);
        ubitMsgBus->ignore(MOTOR1_ID, MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor1Info);

        ubitMsgBus->ignore(MOTOR2_ID, MOTOR_FUNCTION_EVT_COAST, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->ignore(MOTOR2_ID, MOTOR_FUNCTION_EVT_REVERSE, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->ignore(MOTOR2_ID, MOTOR_FUNCTION_EVT_FORWARD, this, &DisplayControl::updateMotor2Info);
        ubitMsgBus->ignore(MOTOR2_ID, MOTOR_FUNCTION_EVT_BRAKE, this, &DisplayControl::updateMotor2Info); 

        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_PING, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_0PRCNT, this, &DisplayControl::updateSonarInfo); 
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_5PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_25PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_50PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_75PRCNT, this, &DisplayControl::updateSonarInfo);
        ubitMsgBus->ignore(SONAR_ID, SONAR_EVT_100PRCNT, this, &DisplayControl::updateSonarInfo);   

        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_IDLE, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_STILL, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_CALIBRATING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_VECTORING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_MOVING, this, &DisplayControl::updateAccelerometerInfo);
        ubitMsgBus->ignore(ACCELEROMETER_ID, ACCELEROMETER_EVT_COLLISION, this, &DisplayControl::updateAccelerometerInfo);           
    };

    void DisplayControl::updateMotor1Info(MicroBitEvent e)
    {
        updateImageWithMotorInfo(e.value,motor1Col,motor1Row);
    };

    void DisplayControl::updateMotor2Info(MicroBitEvent e)
    {
        updateImageWithMotorInfo(e.value,motor2Col,motor2Row);
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
            case MOTOR_FUNCTION_EVT_COAST:
                displayImage.paste(coastImage,col,row); break;
            case MOTOR_FUNCTION_EVT_REVERSE:
                displayImage.paste(reverseImage,col,row); break;
            case MOTOR_FUNCTION_EVT_FORWARD:
                displayImage.paste(forwardImage,col,row); break;
            case MOTOR_FUNCTION_EVT_BRAKE:
                displayImage.paste(brakeImage,col,row); break;
            default:
                break;
        }
        ubitDisplay->printAsync(displayImage);
    };

    void DisplayControl::updateSonarInfo(MicroBitEvent e)
    {
        updateImageWithSonarInfo(e.value);
    };

    void DisplayControl::updateImageWithSonarInfo(int distanceNr)
    {
        static const uint8_t _100[]={1,1,1,1,1}; MicroBitImage _100Image(1,5,_100);
        static const uint8_t  _75[]={0,1,1,1,1}; MicroBitImage _75Image(1,5,_75);
        static const uint8_t  _50[]={0,0,1,1,1}; MicroBitImage _50Image(1,5,_50);
        static const uint8_t  _25[]={0,0,0,1,1}; MicroBitImage _25Image(1,5,_25);
        static const uint8_t   _5[]={0,0,0,0,1}; MicroBitImage _5Image(1,5,_5);
        static const uint8_t   _0[]={0,0,0,0,0}; MicroBitImage _0Image(1,5,_0);
        if (distanceNr==SONAR_EVT_0PRCNT) 
            displayImage.paste(_0Image,sonarCol,sonarRow);
        else if (distanceNr==SONAR_EVT_5PRCNT) 
            displayImage.paste(_5Image,sonarCol,sonarRow);
        else if (distanceNr==SONAR_EVT_25PRCNT) 
            displayImage.paste(_25Image,sonarCol,sonarRow);
        else if (distanceNr==SONAR_EVT_50PRCNT) 
            displayImage.paste(_50Image,sonarCol,sonarRow);
        else if (distanceNr==SONAR_EVT_75PRCNT) 
            displayImage.paste(_75Image,sonarCol,sonarRow);
        else 
            displayImage.paste(_100Image,sonarCol,sonarRow);
        ubitDisplay->printAsync(displayImage);
    };

    void DisplayControl::updateAccelerometerInfo(MicroBitEvent e)
    {
        static const uint8_t        idle[]={0,1,1,1,0}; MicroBitImage idleImage(1,5,idle);
        static const uint8_t calibrating[]={1,0,0,0,1}; MicroBitImage calibratingImage(1,5,calibrating);
        static const uint8_t   vectoring[]={0,1,0,1,0}; MicroBitImage vectoringImage(1,5,vectoring);
        static const uint8_t       still[]={0,0,1,0,0}; MicroBitImage stillImage(1,5,still);
        static const uint8_t      moving[]={1,1,0,0,0}; MicroBitImage movingImage(1,5,moving);
        static const uint8_t   collision[]={0,0,0,1,1}; MicroBitImage collisionImage(1,5,collision);
        if (e.value==ACCELEROMETER_EVT_MOVING)
            displayImage.paste(movingImage,acceloCol,acceloRow);
        else if (e.value==ACCELEROMETER_EVT_COLLISION)
            displayImage.paste(collisionImage,acceloCol,acceloRow);
        else if (e.value==ACCELEROMETER_EVT_VECTORING)
            displayImage.paste(vectoringImage,acceloCol,acceloRow);
        else if (e.value==ACCELEROMETER_EVT_CALIBRATING)
            displayImage.paste(calibratingImage,acceloCol,acceloRow);
        else if (e.value==ACCELEROMETER_EVT_STILL)
            displayImage.paste(stillImage,acceloCol,acceloRow);
        else
            displayImage.paste(idleImage,acceloCol,acceloRow);
        ubitDisplay->printAsync(displayImage);
    };

// } /*dsplCtrl*/