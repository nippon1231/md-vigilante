#include <genesis.h>
#include "game.h"
#include "resources.h"
#include "camera.h"

#define PLAYER_SPEED 1
u16 joy, oldJoy = 0;
u8 ani_currentFrame;
void player_init() {
    game_state.player.x = SCREEN_WIDTH / 2 - 8;
    game_state.player.y = SCREEN_HEIGHT - 90;
    game_state.player.lives = 3;
    game_state.player.active = TRUE;
    game_state.player.mirroir = FALSE;
    game_state.player.jump = FALSE;
    game_state.player.crouch = FALSE;
    game_state.player.action = ANIM_IDLE;
     game_state.player.ani_frame = 0;
     game_state.player.action_anim=FALSE;
    // Créer le sprite du joueur
    game_state.player.sprite = SPR_addSprite(&player_sprite, 
                                              game_state.player.x, 
                                              game_state.player.y, 
                                              TILE_ATTR(PAL0, TRUE, FALSE, FALSE));  
                                                               
}
void player_update() {
    if (game_state.player.action_anim)
    {
        if (ani_currentFrame >0 && ani_currentFrame< game_state.player.ani_frame) ani_currentFrame+=1;
        else if (ani_currentFrame == game_state.player.ani_frame) 
            {
                game_state.player.ani_frame=0;
                game_state.player.action_anim=FALSE;
                ani_currentFrame=0;
                game_state.player.action=ANIM_IDLE;
            }
        return;
    }
    else {
        joy = JOY_readJoypad(JOY_1);     

        // Déplacement gauche/droite
        // bouton bas lacher
        if(!joy)
        {
                game_state.player.action=ANIM_IDLE;
        }
        if ((oldJoy & BUTTON_DOWN) && !(joy & BUTTON_DOWN))
        {
                game_state.player.crouch= FALSE;
                game_state.player.action=ANIM_IDLE;
        }
         
        if (joy & BUTTON_LEFT) {
            game_state.player.mirroir=true;
            if (!game_state.player.crouch){ 
                game_state.player.x -= PLAYER_SPEED;
                if (game_state.player.x < 0) game_state.player.x = 0;
                game_state.player.action=ANIM_WALK;
            }

        }
        if (joy & BUTTON_UP) {
            if (!game_state.player.crouch){ 
                game_state.player.y -= PLAYER_SPEED;
                if (game_state.player.y < 0) game_state.player.y = 0;
                game_state.player.action=ANIM_WALK;
            }

        }        
        if (joy & BUTTON_RIGHT) {

            game_state.player.mirroir=FALSE;
            if (!game_state.player.crouch){   
                game_state.player.x += PLAYER_SPEED;
                if (game_state.player.x > 300) game_state.player.x += PLAYER_SPEED;
                game_state.player.action= ANIM_WALK;  
            } 

        }
        if (joy & BUTTON_DOWN) {
        //    game_state.player.crouch=TRUE;
        //    game_state.player.action=ANIM_CROUCH;

                game_state.player.y += PLAYER_SPEED;
                if (game_state.player.y < 0) game_state.player.y = 0;
                game_state.player.action=ANIM_WALK;
            
        }     
        // Mettre à jour la position du sprite
        SPR_setHFlip(game_state.player.sprite, game_state.player.mirroir); 
        SPR_setAnim(game_state.player.sprite,game_state.player.action); 
        SPR_setPosition(game_state.player.sprite, game_state.player.x, game_state.player.y);
        oldJoy=joy;
    }
}
void player_updateBouton (u16 joy)
{

    if (game_state.player.action_anim)
    {
        if (ani_currentFrame>0 && ani_currentFrame< game_state.player.ani_frame) ani_currentFrame+=1;
        else if (ani_currentFrame == game_state.player.ani_frame) 
            {
                game_state.player.ani_frame=0;
                game_state.player.action_anim=false;
                ani_currentFrame=0;
                game_state.player.action=ANIM_IDLE;
            }
        return;
    }
    else {
        game_state.player.action_anim=true;
        game_state.player.ani_frame+=1;
        ani_currentFrame+=1;
    }
        if(game_state.player.jump)
        {
            SPR_setPosition(game_state.player.sprite, game_state.player.x, game_state.player.y-30);
            game_state.player.jump=false;
        }
        SPR_setHFlip(game_state.player.sprite, game_state.player.mirroir); 
        SPR_setAnim(game_state.player.sprite,game_state.player.action); 
}
