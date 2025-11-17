#include <genesis.h>
#include "game.h"
#include "resources.h"

GameState game_state;

void game_init() {
    // Réinitialiser l'état du jeu

    PAL_setPalette(PAL0, palette_main.data, DMA) ;
     // Initialiser le joueur
    game_state.player.x = SCREEN_WIDTH / 2 ;
    game_state.player.y = SCREEN_HEIGHT-80;
    game_state.player.lives = 3;
    game_state.player.active = TRUE;
    game_state.player.sprite = NULL;
    game_state.player.mirroir=false;
    game_state.player.crouch=FALSE;
    // Créer le sprite du joueur
    SPR_init();
    player_init();
}
