#pragma once

#include <stdbool.h>
#include <stdint.h>

#define REG_DISPCNT             (*(volatile uint16_t *)(0x04000000))
#define VIDEO_MODE_3            ( 3 <<  0)
#define VIDEO_BG2_ENABLE        ( 1 << 10)

#define MODE3_SCREEN            (*(uint16_t (*)[160][240])(0x06000000))
#define COLOR_RED               (31 <<  0)
#define COLOR_GREEN             (31 <<  5)
#define COLOR_BLUE              (31 << 10)
