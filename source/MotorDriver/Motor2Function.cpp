#include "Motor2Function.h"

//https://docs.mbed.com/docs/mbed-drivers-api/en/latest/api/classmbed_1_1DigitalInOut.html

Motor2Function::Motor2Function(void):P0(MICROBIT_PIN_P0),P16(MICROBIT_PIN_P16){
    normalDirection=true;
};

void Motor2Function::write(int valueP0, int valueP16){
    P0.write(valueP0);
    P16.write(valueP16);
};

void Motor2Function::read(int &valueP0, int &valueP16){
    valueP0=P0.read();
    valueP16=P16.read();
};

void Motor2Function::reverseDirections(void){
    normalDirection=!normalDirection;
};

void Motor2Function::coast(void){
    write(0,0);
};

void Motor2Function::forward(void){
    normalDirection==true?write(1,0):write(0,1)
};

void Motor2Function::reverse(void){
    normalDirection==true?write(0,1):write(1,0)
};

void Motor2Function::brake(void){
    write(1,1);
};

mtrCtrl::MTRFUNCTIONS Motor2Function::getFunction(void){
    int P0;
    int P16;
    read(P0,P16);
    int function;
    normalDirection==true?function=P0*2+P16*1:function=P16*2+P0*1;
    switch (function){
        case 0:
            return mtrCtrl::MTRFUNCTIONS::COAST; break;
        case 1:
            return mtrCtrl::MTRFUNCTIONS::REVERSE; break;
        case 2:
            return mtrCtrl::MTRFUNCTIONS::FORWARD; break;
        case 3:
            return mtrCtrl::MTRFUNCTIONS::BRAKE; break;
        default:
    };
    return mtrCtrl::MTRFUNCTIONS::COAST;
};