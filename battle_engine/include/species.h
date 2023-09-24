#ifndef __SPECIES_H__
#define __SPECIES_H__

#include "bf_types.h"

#define SPECIES_NONE 0
#define SPECIES_SAPPURR 1
#define SPECIES_SAPPURR2 2
#define SPECIES_SAPPURR3 3
#define SPECIES_PYRUFF 4
#define SPECIES_HOWLIT 5
#define SPECIES_LYCANFERNO 6
#define SPECIES_SQUOINK 7
#define SPECIES_WOGHASH 8
#define SPECIES_SOLUBOAR 9
#define SPECIES_REAGLE 10
#define SPECIES_REAGALIA 11
#define SPECIES_DONZEREAGAL 12
#define SPECIES_MUKCHUK 13
#define SPECIES_DIRTSKRT 14

#define NUM_SPECIES 190

enum {
	TYPE_MYSTERY,
	TYPE_BASIC,
	TYPE_GRASS,
	TYPE_FLAME,
	TYPE_AQUA,
	TYPE_AIR,
	TYPE_TOXIC,
	TYPE_ELECTRIC,
	TYPE_BUG,
	TYPE_MIND,
	TYPE_GHOST,
	TYPE_EARTH,
	TYPE_METAL,
	TYPE_ICE,
	TYPE_BRAWL,
	TYPE_DRAGON,
	TYPE_MAX
};

u8 gTypeEffectiveness[TYPE_MAX][TYPE_MAX];

enum {
	GROWTH_SLOW,
	GROWTH_MEDIUM,
	GROWTH_FAST
};

enum {
	RARITY_NORMAL,	//Most mons, BST<=540
	RARITY_SPECIAL,	//Starters, gift mons BST<=540
	RARITY_PSEUDOLEGEND,	//BST 600
	RARITY_CRYPTID,	//BST 550
	RARITY_SUBLEGEND,	//BST 570-600
	RARITY_LEGEND,	//BST 600-680
	RARITY_MYTHICAL	//BST 580-600
};

enum {
	STATSTAGE_ATTACK,
	STATSTAGE_DEFENSE,
	STATSTAGE_MAG_ATTACK,
	STATSTAGE_MAG_DEFENSE,
	STATSTAGE_AGILITY,
	STATSTAGE_LUCK
};

typedef struct baseStats_s {
	u16 id; //id number of species for sanity checking
	u8 formNum;
	u8 forms;

	u8 type1;
	u8 type2;
	u8 hp;
	u8 attack;
	u8 defense;
	u8 mag_attack;
	u8 mag_defense;
	u8 agility;

	u16 babyForm;
	u8 eggFamily1;
	u8 eggFamily2;

	u8 rarity;
	u8 cyclesToHatch;
	u8 catchRate;
	u8 tameness;

	u8 perk1;
	u8 perk2;
	u8 perkHidden;
	u8 perkHidden2;

	u16 height;	//in decimeters
	u16 weight;	//in decigrams

	u8 gfxFlags;
	u8 genderRatio;//threshold to pass for mon to be female
	u8 growthRate;
	u8 baseXPYield;//first stage: bst/6 second stage or standalone: bst/5 third stage or legendary/cryptid: bst/4
}BaseStats;

typedef struct evodata_s {
	u16 id;//Species id of evolution
	u8 method;
	u8 parameter;
	u32 parameter2;
}EvolutionData;

#endif /*!__SPECIES_H__!*/
