#include <genesis.h>
#include "game.h"
#include "resources.h"

int main() {
    JOY_init();

    VDP_setScreenWidth320();
    VDP_setScreenHeight224();

        game_init();


        while(1) {
            player_update();
            SPR_update();
            SYS_doVBlankProcess();
        }      
        
}   