#include <genesis.h>
#include "game.h"
#include "resources.h"
#include "levels.h"
void inGameJoyEvent(u16 joy, u16 changed, u16 state);
InputType input;
u16 ind = TILE_USER_INDEX;
char info[10];
Map* levelmap1;
u16 MAP_WIDTH=768;
#define MAP_HIGHT=242;
#define MUR=1;
const u16 LONG_ARRAY=71;
static void collision();
int main() {

    JOY_init();
levelmap1=level_init(ind);
    PAL_setPalette(PAL1,palettelvl.data,DMA);
    JOY_setEventHandler(inGameJoyEvent);
    game_init();
    MAP_scrollTo(levelmap1,0,242);
    setupCamera(newVector2D_u16(162, 112), 1, 20);
        while(1) {            
            player_update();
            updateCamera();

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
    collision();
    
}

static void collision()
{
    sprintf(info,"%10i",(game_state.player.x>>4)+1);
    VDP_drawTextBG(BG_B,info,28,10);
    sprintf(info,"%10i",(game_state.player.y)>>4);
    VDP_drawTextBG(BG_B,info,28,15);
     sprintf(info,"%10i",((game_state.player.y>>4)*48)+(game_state.player.x>>4)+1);
    VDP_drawTextBG(BG_B,info,28,20);    
    sprintf(info,"%10i",LEVEL1_COLISION[(((game_state.player.y>>4)+4)*48)+(game_state.player.x>>4)+1]);
    VDP_drawTextBG(BG_B,info,28,2);    

}