#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "MicroBit.h"
#include "MicroBitEvent.h"
#include "MicroBitComponent.h"
#include "MicroBitSerial.h"
#include "MicroBitSystemTimer.h"
#include "TimedInterruptIn.h"
#include "mbed.h"
#include "math.h"
#include "Defines.h"

    class AccelerometerControl : public MicroBitComponent
    {
        static const bool isDebugOn=false;
        static const int sampleRate_ms=25;//30;
        static const uint64_t updatePeriod_ms=sampleRate_ms*15; 
        static const int integrationSteps=5;
        public:
            AccelerometerControl(MicroBitAccelerometer *accelerometer);
            ~AccelerometerControl(void);
            //virtual void idleTick(void){sendSerial("Accelerometer::idleTick");};
            virtual void systemTick(void);
            bool isCalibrated;
            bool isMoving;
        private:
            MicroBitAccelerometer *ubitAccelerometer;
            double lastAcceleration_mg;
            double Xcal_mg;
            double Ycal_mg;
            double Zcal_mg;
            unsigned int nextUpdateTime;
            int systemTimerAddComponent(void);
            bool doCalibration(void);
            bool isNewUpdateNeeded(void);
            void startUpdate(void);
            void determineMovement(const double speed_ms);
            double calcAcceleration_mg(void);
            double calcSpeed_ms(void);//integral
            void fireStatusEvent(void);
            void sendSerial(const char* text);
            void sendSerial(const int number);
    };

#endif /*ACCELEROMETER_H*/