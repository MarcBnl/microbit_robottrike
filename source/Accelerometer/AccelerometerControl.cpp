#include "AccelerometerControl.h"


    AccelerometerControl::AccelerometerControl(MicroBitAccelerometer *accelerometer)
    {
        ubitAccelerometer=accelerometer;
        sendSerial("AccelerometerControl::AccelerometerControl");
        isCalibrated=doCalibration();
        systemTimerAddComponent();
        ubitAccelerometer->setRange(3);
    };

    AccelerometerControl::~AccelerometerControl(void)
    {
        system_timer_remove_component(this);// fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
    };

    int AccelerometerControl::systemTimerAddComponent(void)
    {
        int result=system_timer_add_component(this);// fiber_add_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
        if (result==MICROBIT_OK){
            sendSerial("MICROBIT_OK:fiber_add_idle_component");
            return MICROBIT_OK;
        }
        sendSerial("MICROBIT_NO_RESOURCES:fiber_add_idle_component");
        return result;
    };


    bool AccelerometerControl::doCalibration(void)
    {
        const int calibrationSamples=1024;
        double Xsum_mg=0;
        double Ysum_mg=0;
        double Zsum_mg=0;
        for (int sample=0; sample<calibrationSamples; sample++){
            Xsum_mg=Xsum_mg+ubitAccelerometer->getX();
            Ysum_mg=Ysum_mg+ubitAccelerometer->getY();
            Zsum_mg=Zsum_mg+ubitAccelerometer->getZ();
            fiber_sleep(2);//ms
        }
        Xcal_mg=Xsum_mg/calibrationSamples;
        Ycal_mg=Ysum_mg/calibrationSamples;
        Zcal_mg=Zsum_mg/calibrationSamples;
        sendSerial("Xcal_mg");sendSerial(Xcal_mg);
        sendSerial("Ycal_mg");sendSerial(Ycal_mg);
        sendSerial("Zcal_mg");sendSerial(Zcal_mg);
        return true;
    };

    void AccelerometerControl::sendSerial(const char* text)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        uBit.serial.printf(text);
        uBit.serial.printf("\r\n");
    };

    void AccelerometerControl::sendSerial(const int number)
    {
        if (!isDebugOn) return;
        MicroBit uBit;
        char buffer [32];
        itoa (number,buffer);
        uBit.serial.printf(buffer);
        uBit.serial.printf("\r\n");
    };