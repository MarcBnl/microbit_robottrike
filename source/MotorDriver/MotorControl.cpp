// #include "MotorControl.h"

// MotorControl::MotorControl(void):Motor1(),Motor2(){
//     //FIXME
//     Motor1.reverseDirections();
//     //OR
//     Motor2.reverseDirections();
// };

// void MotorControl::setMotorFunction(mtrCtrl::MTRFUNCTIONS function){
//     switch (function){
//         case mtrCtrl::MTRFUNCTIONS::COAST:
//             Motor1.coast();
//             Motor2.coast();
//             break;
//         case mtrCtrl::MTRFUNCTIONS::REVERSE:
//             motor1.reverse();
//             motor2.reverse();
//             break;
//         case mtrCtrl::MTRFUNCTIONS::FORWARD:
//             Motor1.forward();
//             Motor2.forward();        
//             break;
//         case mtrCtrl::MTRFUNCTIONS::BRAKE:
//             Motor1.brake();
//             Motor2.brake();
//             break;
//         case mtrCtrl::MTRFUNCTIONS::SPIN:
//             Motor1.forward();
//             motor2.reverse();
//             wait_us(spinDuration_us);
//             Motor1.coast();
//             Motor2.coast();            
//             break;
//         default:
//     }
// };

// void MotorControl::getMotorFunction(mtrCtrl::MTRFUNCTIONS &funcM1, mtrCtrl::MTRFUNCTIONS &funcM2){
//     funcM1=Motor1.getFunction();
//     funcM2=Motor2.getFunction();
// };