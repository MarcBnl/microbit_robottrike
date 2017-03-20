#include "MicroBit.h"

MicroBitDisplay display;

int main() {
    display.scroll("Robot-trike");
	release_fiber();
}