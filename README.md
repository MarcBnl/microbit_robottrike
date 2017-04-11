# microbit_robottrike
project to create a robot trike with the BBC micro:bit, kitronik V2 motordriver and the HC-SR04 sonar sensor
kitronik V2 motor driver: https://www.kitronik.co.uk/blog/introducing-motor-driver-board-v2/
HC-SR04 sonar sensor: https://docs.google.com/document/d/1Y-yZnNhMYy7rwhAgyL_pfa39RsB-x2qR4vP8saG73rE/edit

# -----------------------------------------------------------

# Yotta creating mbed OS applications:
https://docs.mbed.com/docs/getting-started-mbed-os/en/latest/Full_Guide/app_on_yotta/#writing-applications-for-mbed-os
# Testing With yotta:
http://yottadocs.mbed.com/tutorial/testing.html
# CheatSheet yotta:
http://yottadocs.mbed.com/reference/cheatsheet.html

# -----------------------------------------------------------

# Micro:Bit info
https://github.com/lancaster-university/microbit-dal
https://lancaster-university.github.io/microbit-docs/
https://developer.mbed.org/teams/Lancaster-University/code/microbit-dal/file/ee44932401cb/inc/drivers/MicroBitPin.h
https://developer.mbed.org/teams/Lancaster-University/code/microbit-dal/docs/tip/
https://developer.mbed.org/teams/Lancaster-University/code/microbit-dal/docs/eb91bba49623/classMicroBitComponent.html
https://github.com/lancaster-university/microbit-dal/blob/master/source/core/MicroBitSystemTimer.cpp
http://microbit-challenges.readthedocs.io/en/latest/tutorials/accelerometer.html


# -----------------------------------------------------------

# ARM mbed
https://www.mbed.com/en/
https://docs.mbed.com/docs/mbed-os-api-reference/en/latest/
https://developer.mbed.org/handbook/Ticker
https://docs.mbed.com/docs/mbed-os-api/en/mbed-os-5.1.0/api/classmbed_1_1DigitalInOut.html
https://developer.mbed.org/handbook/InterruptIn
https://developer.mbed.org/teams/Lancaster-University/code/microbit-dal/docs/eb91bba49623/TimedInterruptIn_8h_source.html
# ARM examples
https://developer.mbed.org/users/isaeldiaz/code/MicrobitUltrasound/


# -----------------------------------------------------------

unsigned int status=0;
unsigned int PING_SEND_NEW=0x2; //#define
unsigned int PING_ONGOING=0x4; //#define
unsigned int ECHO_HIGH=0x8; //#define
unsigned int ECHO_LOW=0x10; //#define
cout << "status=" << status << endl;  //status=0
status |= PING_SEND_NEW;
cout << "status=" << status << endl;  //status=2
status |= PING_ONGOING;
cout << "status=" << status << endl;  //status=6
cout << "~PING_ONGOING=" << (~PING_ONGOING) << endl;  //~PING_ONGOING=4294967291
status &= ~PING_ONGOING;
cout << "status=" << status << endl;  //status=2
if (status & PING_SEND_NEW) cout << "PING_SEND_NEW" << endl; //PING_SEND_NEW
if (status & PING_ONGOING) cout << "PING_ONGOING" << endl;   //<nothing printed>