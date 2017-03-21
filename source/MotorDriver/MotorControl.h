#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

// #include "source/MotorDriver/Motor1Function.h"
// #include "source/MotorDriver/Motor2Function.h"

namespace mtrCtrl{

    enum class MTRFUNCTIONS:int {COAST=0,REVERSE=1,FORWARD=2,BRAKE=3,SPIN};

    // class MotorControl {
    //     static const int spinDuration_us=5000;
    //     Motor1Function Motor1;
    //     Motor2Function Motor2;
    //     public:
    //         MotorControl(void);
    //         ~MotorControl(void){};
    //         void setMotorFunction(mtrCtrl::MTRFUNCTIONS function);
    //         void getMotorFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2);
    //     private:
    // };

} /*mtrCtrl*/

#endif /*MOTORCONTROL_H*/