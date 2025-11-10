#include <genesis.h>
#include "game.h"
#include "resources.h"

#define ANIM_IDLE  0
#define ANIM_WALK  1
#define ANIM_CROUCH  3

#define PLAYER_SPEED 1
u16 joy, oldJoy = 0;

void player_init() {
    game_state.player.x = SCREEN_WIDTH / 2 - 8;
    game_state.player.y = SCREEN_HEIGHT - 150;
    game_state.player.lives = 3;
    game_state.player.active = TRUE;
    game_state.player.mirroir = FALSE;
    game_state.player.jump = FALSE;
    game_state.player.crouch = FALSE;
    // Créer le sprite du joueur
    game_state.player.sprite = SPR_addSprite(&player_sprite, 
                                              game_state.player.x, 
                                              game_state.player.y, 
                                              TILE_ATTR(PAL0, TRUE, FALSE, FALSE));  
                                                               
}
void player_update() {
    if (!game_state.player.active) return;
     joy = JOY_readJoypad(JOY_1);     


    // Déplacement gauche/droite
    // bouton bas lacher
        if ((oldJoy & BUTTON_DOWN) && !(joy & BUTTON_DOWN))
        {
                game_state.player.crouch= FALSE;
                SPR_setAnim(game_state.player.sprite,ANIM_IDLE);
        }

    if (joy & BUTTON_LEFT) {
        game_state.player.mirroir=true;
         if (!game_state.player.crouch){ 
            game_state.player.x -= PLAYER_SPEED;
            if (game_state.player.x < 0) game_state.player.x = 0;
            SPR_setHFlip(game_state.player.sprite, game_state.player.mirroir); 
            SPR_setAnim(game_state.player.sprite,ANIM_WALK);
         }

    }
    if (joy & BUTTON_RIGHT) {

        game_state.player.mirroir=FALSE;
        if (!game_state.player.crouch){   
            game_state.player.x += PLAYER_SPEED;
            if (game_state.player.x > SCREEN_WIDTH - 16) 
                game_state.player.x = SCREEN_WIDTH - 16;
             SPR_setAnim(game_state.player.sprite, ANIM_WALK);       
        }
            SPR_setHFlip(game_state.player.sprite, game_state.player.mirroir); 

    }
    if (joy & BUTTON_DOWN) {
        game_state.player.crouch=TRUE;
        SPR_setHFlip(game_state.player.sprite, game_state.player.mirroir); 
        SPR_setAnim(game_state.player.sprite,ANIM_CROUCH);

    }     
    // Mettre à jour la position du sprite
    SPR_setPosition(game_state.player.sprite, game_state.player.x, game_state.player.y);
    oldJoy=joy;

}