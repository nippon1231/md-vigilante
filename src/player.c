#include <genesis.h>
#include "game.h"
#include "resources.h"

void player_init() {
    game_state.player.x = SCREEN_WIDTH / 2 - 8;
    game_state.player.y = SCREEN_HEIGHT - 40;
    game_state.player.lives = 3;
    game_state.player.active = TRUE;

    // Créer le sprite du joueur
    game_state.player.sprite = SPR_addSprite(&player_sprite, 
                                              game_state.player.x, 
                                              game_state.player.y, 
                                              TILE_ATTR(PAL0, TRUE, FALSE, FALSE));
    SPR_setFrame(game_state.player.sprite, 0);                     
}
void player_update() {
    if (!game_state.player.active) return;
    
    u16 joy = JOY_readJoypad(JOY_1);
    SPR_setFrame(game_state.player.sprite, 3);
    // Déplacement gauche/droite
    if (joy & BUTTON_LEFT) {
        game_state.player.x -= PLAYER_SPEED;
        if (game_state.player.x < 0) game_state.player.x = 0;
        SPR_
    }
    if (joy & BUTTON_RIGHT) {
        game_state.player.x += PLAYER_SPEED;
        if (game_state.player.x > SCREEN_WIDTH - 16) 
            game_state.player.x = SCREEN_WIDTH - 16;
        SPR_setFrame(game_state.player.sprite, 2);
    }
    
    
    // Mettre à jour la position du sprite
    SPR_setPosition(game_state.player.sprite, game_state.player.x, game_state.player.y);
    

}