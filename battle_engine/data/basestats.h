#ifndef __BASE_STATS_H__
#define __BASE_STATS_H__

#include "include/species.h"
#define GENDER_RATIO_ALL_FEMALE	0
#define GENDER_RATIO_THREE_QUARTER_FEMALE 63
#define GENDER_RATIO_HALF 127
#define GENDER_RATIO_QUARTER_FEMALE 191
#define GENDER_RATIO_ALL_MALE 255

const BaseStats gBaseStats[NUM_SPECIES] = {
	[SPECIES_SAPPURR] =
	{
		.id=1,

		.type1=TYPE_GRASS,
		.type2=TYPE_MYSTERY,

		.hp=54,
		.attack=60,
		.defense=40,
		.mag_attack=46,
		.mag_defense=40,
		.agility=72,
		
		.height=4,
		.weight=14,

		.rarity=RARITY_RARE,
		.gender_ratio=GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate=GROWTH_SLOW,
		.baseXPYield=52
	},
	[SPECIES_SAPPURR3] =
	{
		.id = 3,

		.type1 = TYPE_GRASS,
		.type2 = TYPE_MIND,

		.hp = 72,
		.attack = 110,
		.defense = 85,
		.mag_attack = 84,
		.mag_defense = 70,
		.agility = 109,

		.height = 16,
		.weight = 630,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 133
	},
	[SPECIES_PYRUFF] =
	{
		.id = 4,

		.type1 = TYPE_FLAME,
		.type2 = TYPE_MYSTERY,

		.hp = 50,
		.attack = 56,
		.defense = 45,
		.mag_attack = 56,
		.mag_defense = 45,
		.agility = 60,

		.height = 5,
		.weight = 28,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 52
	},
	[SPECIES_LYCANFERNO] =
	{
		.id = 6,

		.type1 = TYPE_FLAME,
		.type2 = TYPE_BRAWL,

		.hp = 80,
		.attack = 106,
		.defense = 72,
		.mag_attack = 96,
		.mag_defense = 91,
		.agility = 85,

		.height = 14,
		.weight = 700,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 133
	},
	[SPECIES_SQUOINK] =
	{
		.id = 7,

		.type1 = TYPE_AQUA,
		.type2 = TYPE_MYSTERY,

		.hp = 70,
		.attack = 50,
		.defense = 44,
		.mag_attack = 60,
		.mag_defense = 44,
		.agility = 44,

		.height = 6,
		.weight = 48,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 52
	},
	[SPECIES_SOLUBOAR] =
	{
		.id = 9,

		.type1 = TYPE_AQUA,
		.type2 = TYPE_TOXIC,

		.hp = 110,
		.attack = 80,
		.defense = 82,
		.mag_attack = 100,
		.mag_defense = 97,
		.agility = 66,

		.height = 19,
		.weight = 980,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 133
	},
	[SPECIES_REAGLE] =
	{
		.id = 10,

		.type1 = TYPE_AIR,
		.type2 = TYPE_MYSTERY,

		.hp = 50,
		.attack = 56,
		.defense = 40,
		.mag_attack = 50,
		.mag_defense = 40,
		.agility = 76,

		.height = 3,
		.weight = 12,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 52
	},
	[SPECIES_DONZEREAGAL] =
	{
		.id = 12,

		.type1 = TYPE_AIR,
		.type2 = TYPE_MYSTERY,

		.hp = 82,
		.attack = 116,
		.defense = 76,
		.mag_attack = 90,
		.mag_defense = 76,
		.agility = 100,

		.height = 17,
		.weight = 247,

		.rarity = RARITY_RARE,
		.gender_ratio = GENDER_RATIO_QUARTER_FEMALE,
		.growth_rate = GROWTH_SLOW,
		.baseXPYield = 135
	}
};

#endif // !__BASE_STATS_H__
