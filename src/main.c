#include "example.h"

int main(void)
{
    REG_DISPCNT = VIDEO_MODE_3 | VIDEO_BG2_ENABLE;

    MODE3_SCREEN[80][120] = COLOR_RED;
    MODE3_SCREEN[80][136] = COLOR_GREEN;
    MODE3_SCREEN[96][120] = COLOR_BLUE;

    while (true) {}
}
