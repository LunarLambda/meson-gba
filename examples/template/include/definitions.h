#pragma once

#include <stdbool.h>
#include <stdint.h>

#define REG_DISPCNT             (*(volatile uint16_t *)(0x04000000))
#define VIDEO_MODE_3            3
#define VIDEO_BG2_ENABLE        (1 << 10)
#define COLOR_RED               0x001F
#define COLOR_GREEN             0x03E0
#define COLOR_BLUE              0x7C00
#define MODE3_SCREEN            (*(uint16_t (*)[160][240])(0x06000000))
