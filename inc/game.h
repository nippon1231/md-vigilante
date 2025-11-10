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
    bool crouch;
    bool jump;
    u8 ani_frame;
    u8 action;
    Sprite* sprite;
} Player;
typedef struct {
	u16 joy;
	u16 changed;
	u16 state;
} InputType;


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
extern InputType input;

#define ANIM_IDLE  0
#define ANIM_WALK  1
#define ANIM_KICK  2
#define ANIM_CROUCH  3
#define ANIM_CROUCHKICK  4
#define ANIM_PUNCH  5

#endif // _GAME_H_