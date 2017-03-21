#include "Motor1Function.h"

//https://docs.mbed.com/docs/mbed-drivers-api/en/latest/api/classmbed_1_1DigitalInOut.html

Motor1Function::Motor1Function(void):P8(MICROBIT_PIN_P8),P12(MICROBIT_PIN_P12){
    normalDirection=true;
};

void Motor1Function::write(int valueP8, int valueP12){
    P8.write(valueP8);
    P12.write(valueP12);
};

void Motor1Function::read(int &valueP8, int &valueP12){
    valueP8=P8.read();
    valueP12=P12.read();
};

void Motor1Function::reverseDirections(void){
    normalDirection=!normalDirection;
};

void Motor1Function::coast(void){
    write(0,0);
};

void Motor1Function::forward(void){
    normalDirection=true?write(1,0):write(0,1);
};

void Motor1Function::reverse(void){
    normalDirection=true?write(0,1):write(1,0);
};

void Motor1Function::brake(void){
    write(1,1);
};

mtrCtrl::MTRFUNCTIONS Motor1Function::getFunction(void){
    int P8;
    int P12;
    read(P8,P12);
    int function;
    normalDirection=true?function=P8*2+P12*1:function=P12*2+P8*1;
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