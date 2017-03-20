#include "MicroBit.h"

MicroBitDisplay display;

int main() {
	while(1){
        display.scroll(":-)");
    }
	release_fiber();
}