#ifndef _GAME_H_
#define _GAME_H_
#include <genesis.h>

// Constantes du jeu
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 224
typedef struct {
    s16 x;
    s16 y;
    u8 lives;
    bool mirroir;
    bool active;
    Sprite* sprite;
} Player;

typedef struct {
    Player player;
    u32 score;
    u16 wave;
    bool game_over;
    bool return_to_boot;

} GameState;
// Fonctions du jeu
void game_init();
void player_init();
void player_update();
extern GameState game_state;

#endif // _GAME_H_