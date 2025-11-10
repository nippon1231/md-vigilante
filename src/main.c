#include <genesis.h>
#include "game.h"
#include "resources.h"

void inGameJoyEvent(u16 joy, u16 changed, u16 state);
InputType input;
int main() {
    JOY_init();

    VDP_setScreenWidth320();
    VDP_setScreenHeight224();
    JOY_setEventHandler(inGameJoyEvent);
        game_init();


        while(1) {
         //   player_update();

            player_update();
         
            SPR_update();
            SYS_doVBlankProcess();
        }      
        
}   
void inGameJoyEvent(u16 joy, u16 changed, u16 state) {
	input.joy = joy;
	input.changed = changed;
	input.state = state;

	player_update();

}