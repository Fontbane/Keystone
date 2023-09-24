#ifndef __GAME_H__
#define __GAME_H__

#include "vulkan/vulkan.h"
#include "SDL.h"
#include "SDL_image.h"
#include "constants/bf_types.h"

enum {
	GAME_STATE_MAIN_MENU,
	GAME_STATE_FIELD,
	GAME_STATE_CUTSCENE,
	GAME_STATE_MENU,
	GAME_STATE_BATTLE
};

void init_game();
u32 GetRand32();
u16 GetRand16();
u8 GetRand8();
u8 GetRandOutOf100();

extern u32 gInput;
extern u8 gGameState;
u32 gRandSeed;
u32 gLastRand;

#endif /*__GAME_H__*/
