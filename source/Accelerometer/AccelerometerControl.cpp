#include "AccelerometerControl.h"


    AccelerometerControl::AccelerometerControl(MicroBitAccelerometer *accelerometer)
    {
        sendSerial("AccelerometerControl::AccelerometerControl");
        ubitAccelerometer=accelerometer;
        ubitAccelerometer->setRange(5);
        ubitAccelerometer->setPeriod(sampleRate_ms);
        lastAcceleration_mg=0.0;
        isUpdating=false;
        nextUpdateTime=0;
        isCalibrated=doCalibration();
        systemTimerAddComponent();
    };

    AccelerometerControl::~AccelerometerControl(void)
    {
        system_timer_remove_component(this);// fiber_remove_idle_component(this);  //DOES NOT WORK, NO SYSTEM IDLE TICKS RECIEVED
    };

    bool AccelerometerControl::doCalibration(void)
    {
        MicroBitEvent evt1(ACCELEROMETER_ID,ACCELEROMETER_EVT_CALIBRATING);
        const int calibrationSamples=512;
        double Xsum_mg=0;
        double Ysum_mg=0;
        double Zsum_mg=0;
        for (int sample=0; sample<calibrationSamples; sample++){
            Xsum_mg=Xsum_mg+ubitAccelerometer->getX();
            Ysum_mg=Ysum_mg+ubitAccelerometer->getY();
            Zsum_mg=Zsum_mg+ubitAccelerometer->getZ();
            fiber_sleep(sampleRate_ms);
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
        if (isUpdating==false)
            if (isNewUpdateNeeded()==true) startUpdate();
    };

    bool AccelerometerControl::isNewUpdateNeeded(void)
    {
        return system_timer_current_time() >= nextUpdateTime;
    };

    void AccelerometerControl::startUpdate(void)
    {
        isUpdating=true;
        double speed_ms=calcSpeed_ms();
        fireStatusEvent(speed_ms);        
        isUpdating=false;
        nextUpdateTime=system_timer_current_time()+updatePeriod_ms;
    };

    double AccelerometerControl::calcSpeed_ms(void)
    {   //integrate acceleration over sampleRate time
        double speed_ms=0.0;
        for (int step=0; i<integrationSteps; step++){
            speed_ms+=(calcAcceleration_mg()*0.001)*(sampleRate_ms*0.001);//area
            fiber_sleep(sampleRate_ms);//ms
        }
        return speed_ms;
    };

    double AccelerometerControl::calcAcceleration_mg(void)
    {
        MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_VECTORING);
        double X_mg=ubitAccelerometer->getX()-Xcal_mg;
        double Y_mg=ubitAccelerometer->getY()-Ycal_mg;
        double Z_mg=ubitAccelerometer->getZ()-Zcal_mg;
        double acceleration_mg=sqrt(pow(X_mg,2.0)+pow(Y_mg,2.0)+pow(Z_mg,2.0));
        // sendSerial("acceleration_mg");sendSerial(acceleration_mg);   
        return acceleration_mg;
    };
    
    void AccelerometerControl::fireStatusEvent(const double speed_ms)
    {
        const double speedThreshold_ms=0.01;//=3cm/s
        if (speed_ms>=speedThreshold_ms)
            MicroBitEvent evt(ACCELEROMETER_ID,ACCELEROMETER_EVT_MOVING);
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
