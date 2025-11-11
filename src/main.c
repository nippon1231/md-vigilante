#include <genesis.h>
#include "game.h"
#include "resources.h"
#include "levels.h"
void inGameJoyEvent(u16 joy, u16 changed, u16 state);
InputType input;
u16 ind = TILE_USER_INDEX;

Map* levelmap1;

int main() {

    JOY_init();
levelmap1=level_init(ind);
    PAL_setPalette(PAL1,palettelvl.data,DMA);
    JOY_setEventHandler(inGameJoyEvent);
    game_init();
    MAP_scrollTo(levelmap1,0,300);

        while(1) {

            
            player_update();
         
            SPR_update();
            SYS_doVBlankProcess();
        }      
        
}   
void inGameJoyEvent(u16 joy, u16 changed, u16 state) {
	input.joy = joy;
	input.changed = changed;
	input.state = state;
    
    if(changed & state & BUTTON_A) 
    {
        if (!game_state.player.crouch) game_state.player.action=ANIM_KICK;
        else game_state.player.action=ANIM_CROUCHKICK;
            game_state.player.ani_frame=8;

    }
    if(changed & state & BUTTON_B)
    {
            game_state.player.action=ANIM_PUNCH;
            game_state.player.ani_frame=30;

    }
     if(changed & state & BUTTON_C)
    {
            game_state.player.action=ANIM_JUMP;
            game_state.player.jump=true;
            game_state.player.ani_frame=4;

    }   
    player_updateBouton(joy);
    
}