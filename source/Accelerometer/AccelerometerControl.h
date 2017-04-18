#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "MicroBit.h"
#include "MicroBitComponent.h"
#include "MicroBitSerial.h"
#include "MicroBitSystemTimer.h"
#include "TimedInterruptIn.h"
#include "mbed.h"
#include "Defines.h"

#define ACCELEROMETER_COMPONENT_RUNNING 0x1

    class AccelerometerControl : public MicroBitComponent
    {
        static const bool isDebugOn=true;
        public:
            AccelerometerControl(MicroBitAccelerometer *accelerometer);
            ~AccelerometerControl(void);
            //virtual void idleTick(void){sendSerial("Accelerometer::idleTick");};
            //virtual void systemTick(void){sendSerial("Accelerometer::systemTick");};
            bool isCalibrated;
        private:
            MicroBitAccelerometer *ubitAccelerometer;
            double Xcal_mg;
            double Ycal_mg;
            double Zcal_mg;
            int systemTimerAddComponent(void);
            void sendSerial(const char* text);
            void sendSerial(const int number);
            bool doCalibration(void);
    };

#endif /*ACCELEROMETER_H*/