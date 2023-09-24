#ifndef __BATTLE_UI_H__
#define __BATTLE_UI_H__

#include "ui.h"
#include "battle_setup.h"

typedef struct battleui_s {
	struct nk_image monSprite[6];
	struct nk_panel hpBar[6];
} BattleUI;

#endif // !__BATTLE_UI_H__
