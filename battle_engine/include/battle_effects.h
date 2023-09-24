#ifndef __BATTLE_EFFECTS_H__
#define __BATTLE_EFFECTS_H__

#include "battle_script.h"

typedef struct techeffect_s {
	BattleScript script;
	BattleScript secondary;
	u8 step;
} TechEffect;

enum {
	PSTIM_NONE,
	PSTIM_PASSIVE,
	PSTIM_ONSWITCHIN,
	PSTIM_ONTURNEND,
	PSTIM_IMMUNITY,
	PSTIM_RESISTANCE,
	PSTIM_SPEEDCHECK,
	PSTIM_BEFOREDAMAGETAKEN,
	PSTIM_BEFOREDAMAGETAKENTYPE,
	PSTIM_BEFOREDAMAGETAKENFLAG,
	PSTIM_ONDAMAGETAKEN,
	PSTIM_ONDAMAGETAKENTYPE,
	PSTIM_ONDAMAGETAKENFLAG,
	PSTIM_BEFOREDEALDAMAGE,
	PSTIM_ONDAMAGESUCCESS,
	PSTIM_ONDAMAGEFAILURE,
	PSTIM_OTHER,
	PSTIM_MAX
};

typedef struct perkeffect_s {
	u16 stimulus;
	u8 step;
	u8 filler;
	BattleScript procscript;
	u16 param1;
	u16 param2;
	u32 flags;
} Perk;

typedef struct itemeffect_s {
	u16 stimulus;
	u8 step;
	u8 param;
	BattleScript procscript;
	u32 flags;
} ItemEffect;

const Perk gPerks[256];
const TechEffect gTechEffects[TECHEFFECT_MAX];

#endif /*!__BATTLE_EFFECTS_H__!*/
