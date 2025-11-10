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
            VDP_drawText("Hello Genny World!", 10, 13);
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