#include <genesis.h>
#include "game.h"
#include "resources.h"

int main() {
    JOY_init();
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();
        game_init();
        while(1) {
        VDP_setWindowHPos(FALSE, 0);
        VDP_setWindowVPos(FALSE, 1);
        PAL_setPalette(PAL0, palette_main.data, DMA) ;
        while(1) {

            SPR_update();
            SYS_doVBlankProcess();
        }      
        }
}   