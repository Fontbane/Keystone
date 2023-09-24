#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "species.h"

#define PARTY_SIZE	6

#define STATUS_STUN			1
#define STATUS_DROWSY		2
#define STATUS_DIZZY		3
#define STATUS_BURN			4
#define STATUS_FROSTBITE	5
#define STATUS_POISON		6

#define BATTLESTATUS_FLINCH		0x01
#define BATTLESTATUS_TRAPPED	0x02


typedef struct personal_s {
	u16 species;
	u8 form;
	u8 level;

	TextWord ot;
	TextWord nickname;

	u32 personality;
	u32 otID;

	u32 experience;

	u8 hpTV;
	u8 attackTV;
	u8 defenseTV;
	u8 mag_attackTV;
	u8 mag_defenseTV;
	u8 agilityTV;
	u8 hpReserves : 4;
	u8 agilityReserves : 4;
	u8 bond;

	u32 unlockedTechs[8];

	u16 tech1;
	u16 tech2;
	u16 tech3;
	u16 tech4;

	u8 knack;
	u8 perk;
	u8 originalKnack;
	u8 originalPerk;

	u16 metYear;
	u8 metMonth;
	u8 metDay;

	u8 metLocation;
	u8 metLevel;
	u8 encounterType;
	u8 capsule;

	u16 maxHP;
	u16 currentHP;
	u16 attack;
	u16 defense;
	u16 mag_attack;
	u16 mag_defense;
	u16 agility;
	u8 startingNRG;

	u16 heldItem;

	u8 isTraded : 1;
	u8 isNicknamed : 1;
	u8 isShiny : 1;
	u8 gender : 1;
	u8 isEgg : 1;
	u8 flags : 3;
} PersonalData;

typedef struct battlemon_s {
	PersonalData* personal;

	u32 status;
	u8 majorStatus;
	u8 majorStatusTurns:4;
	u8 firstTurnIn : 1;
	u8 filler : 3;
	u8 nrg;
	u8 isWild : 1;
	u8 tagged : 1;
	u8 participantID : 3;
	u8 tamerID : 3;

	u16 currentItem;
	u16 weight;

	u8 effectiveKnack;
	u8 effectivePerk;

	u16 statMultipliers[6];

	u8 type1;
	u8 type2;
	u8 type3;
	u8 counter;

	u16 species;
	u8 form;

	s8 statStages[6];

	u16 lastUsedTechnique;
	u8 lastAction;
	u8 lastActionResult;

	s16 lastDamageTaken;
	s16 lastDamageDealt;

} BattleMon;

typedef struct tamermoncfg_s {
	u16 species;
	u8 level : 7;
	u8 gender : 1;
	u8 tv;
	u32 custom;
} TamerMonCfg;

typedef struct tamermoncfgitemperkknack_s {
	u16 species;
	u8 level : 7;
	u8 gender : 1;
	u8 tv;
	u16 item;
	u8 perk;
	u8 knack;
	u32 custom;
} TamerMonCfgItemPerkKnack;

typedef struct tamermoncfgitemperkknacktechs_s {
	u16 species;
	u8 level : 7;
	u8 gender : 1;
	u8 tv;
	u16 item;
	u8 perk;
	u8 knack;
	u16 techs[4];
	u32 custom;
} TamerMonCfgItemPerkKnackTechs;

void calculateWriteStats(PersonalData* mon);
BattleMon* battle_BattleMonFromPersonalData(PersonalData* mon);

extern const BaseStats gBaseStats[NUM_SPECIES];

#endif // !__MONSTER_H__!
