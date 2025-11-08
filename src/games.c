#include <genesis.h>
#include "game.h"
#include "resources.h"

GameState game_state;

void game_init() {
    // Réinitialiser l'état du jeu


     // Initialiser le joueur
    game_state.player.x = SCREEN_WIDTH / 2 - 8;
    game_state.player.y = SCREEN_HEIGHT-70;
    game_state.player.lives = 3;
    game_state.player.active = TRUE;
    game_state.player.sprite = NULL;
    
    // Créer le sprite du joueur
    SPR_init();
    game_state.player.sprite = SPR_addSprite(&player_sprite, 
                                              game_state.player.x, 
                                              game_state.player.y, 
                                              TILE_ATTR(PAL0, TRUE, FALSE, FALSE));

}
