#include "AccelerometerControl.h"


    AccelerometerControl::AccelerometerControl(MicroBitAccelerometer *accelerometer)
    {
        ubitAccelerometer=accelerometer;
        ubitAccelerometer->setRange(3);
        lastAcceleration_mg=0.0;
        nextUpdateTime=0;
        sendSerial("AccelerometerControl::AccelerometerControl");
        isCalibrated=doCalibration();
        systemTimerAddComponent();
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

    void AccelerometerControl::systemTick(void)
    {
        // sendSerial("AccelerometerControlSonar::systemTick");
        if (isNewUpdateNeeded()==true) startUpdate();
    };

    bool AccelerometerControl::doCalibration(void)
    {
        MicroBitEvent evt1(ACCELEROMETER_ID,ACCELEROMETER_EVT_CALIBRATING);
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
        MicroBitEvent evt2(ACCELEROMETER_ID,ACCELEROMETER_EVT_IDLE);
        return true;
    };

    bool AccelerometerControl::isNewUpdateNeeded(void)
    {
        return system_timer_current_time() >= nextUpdateTime;
    };

    void AccelerometerControl::startUpdate(void)
    {
        double acceleration_mg=calcAcceleration_mg();
        fireStatusEvent(acceleration_mg);
        lastAcceleration_mg=acceleration_mg;
        nextUpdateTime=system_timer_current_time()+updatePeriod_ms;
    };

    double AccelerometerControl::calcAcceleration_mg(void)
    {
        MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_VECTORING);
        const int vectoringSamples=2;//512;
        double Xsum_mg=0;
        double Ysum_mg=0;
        double Zsum_mg=0;
        for (int sample=0; sample<vectoringSamples; sample++){
            Xsum_mg=Xsum_mg+ubitAccelerometer->getX();
            Ysum_mg=Ysum_mg+ubitAccelerometer->getY();
            Zsum_mg=Zsum_mg+ubitAccelerometer->getZ();
            //fiber_sleep(2);//ms
        }
        double X_mg=(Xsum_mg/vectoringSamples)-Xcal_mg;
        double Y_mg=(Ysum_mg/vectoringSamples)-Ycal_mg;
        double Z_mg=(Zsum_mg/vectoringSamples)-Zcal_mg;
        sendSerial("X_mg");sendSerial(X_mg);
        sendSerial("Y_mg");sendSerial(Y_mg);
        sendSerial("Z_mg");sendSerial(Z_mg);        
        double acceleration_mg=sqrt(pow(X_mg,2.0)+pow(Y_mg,2.0)+pow(Z_mg,2.0));
        sendSerial("acceleration_mg");sendSerial(acceleration_mg);   
        return acceleration_mg;
    };
    
    void AccelerometerControl::fireStatusEvent(const double acceleration_mg)
    {
        const double diffMovingAcceleration_mg=100.0;
        const double diffCollisionAcceleration_mg=1000.0;
        // <---COLLISION---(-Value)lastAcceleration(+Value)---MOVING--->
        if (acceleration_mg>=(lastAcceleration_mg+diffMovingAcceleration_mg)) 
            MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_MOVING);
        else if (acceleration_mg<=(lastAcceleration_mg-diffCollisionAcceleration_mg))
            MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_COLLISION);
        else
            MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_STILL);
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
