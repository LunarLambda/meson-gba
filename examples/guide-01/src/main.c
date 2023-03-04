#include <seven/prelude.h>
#include <seven/hw/video.h>
#include <seven/hw/video/bg_bitmap.h>
#include <seven/hw/video/color_constants.h>

int main(void)
{
    // To wait for V-Blank, we need some rudimentary interrupt handling
    irqInitStub();
    irqEnableFull(IRQ_VBLANK);

    // Enable video mode 3, which lets us draw pixels directly to the screen
    REG_DISPCNT = VIDEO_MODE(3) | VIDEO_BG2_ENABLE;

    struct InputState input = inputNew();

    int x = 120;
    int y = 60;

    // Our main game loop runs forever
    while (true)
    {
        // Process inputs
        input = inputPoll(input);
        x += inputAxisX(input);
        y += inputAxisY(input);

        // Make sure x and y stay on the screen (240x160 pixels)
        if (x < 0) x = 0;
        if (x >= 240) x = 239;

        if (y < 0) y = 0;
        if (y >= 160) y = 159;

        // Wait for V-Blank so we can draw to the screen without tearing
        biosVBlankIntrWait();

        // Draw a pixel to the screen
        MODE3_FRAME[y][x] = COLOR_CYAN;
    }
}
