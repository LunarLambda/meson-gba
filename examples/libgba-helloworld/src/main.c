#include <stdio.h>
#include <stdlib.h>

#ifdef LIBGBA_HAS_CONSOLE
#include <gba_console.h>
#endif
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

int main(void)
{
    irqInit();
    irqEnable(IRQ_VBLANK);

#ifdef LIBGBA_HAS_CONSOLE
    consoleDemoInit();

    iprintf("\x1b[10;10HHello World!\n");
#endif

    while (1)
    {
        VBlankIntrWait();
    }
}
