#include "include/monster.h"

void calculateWriteStats(PersonalData* mon) {
	BaseStats* baseStats = &gBaseStats[mon->species];
	mon->maxHP = mon->level * (2*baseStats->hp + mon->hpTV / 4) / 100 + mon->level;
	if (mon->maxHP > mon->hpReserves) {
		mon->maxHP -= mon->hpReserves;
	}
	if (mon->currentHP > mon->maxHP) {
		mon->currentHP = mon->maxHP;
	}
	mon->attack = mon->level * (2*baseStats->attack + mon->attackTV / 4) / 100 ;
	mon->defense = mon->level * (2*baseStats->defense + mon->defenseTV / 4) / 100 ;
	mon->mag_attack = mon->level * (2*baseStats->mag_attack + mon->mag_attackTV / 4) / 100 ;
	mon->mag_defense = mon->level * (2*baseStats->mag_defense + mon->mag_defenseTV / 4) / 100 ;
	mon->agility = mon->level * (2*baseStats->agility + mon->agilityTV / 4) / 100 ;
	if (mon->agility > mon->agilityReserves) {
		mon->agility -= mon->agilityReserves;
	}
	mon->startingNRG = (mon->hpReserves + mon->agilityReserves) / 4 + 4;

}
BattleMon* battle_BattleMonFromPersonalData(PersonalData* mon) {
	BattleMon* b = SDL_malloc(sizeof(BattleMon));
	b->personal = mon;
	b->type1 = gBaseStats[mon->species].type1;
	b->type2 = gBaseStats[mon->species].type2;
	b->form = mon->form;
	b->nrg = mon->startingNRG;
	b->weight = gBaseStats[mon->species].weight;
	b->currentItem = mon->heldItem;
	b->effectiveKnack = mon->knack;
	b->effectivePerk = mon->perk;
	
	return b;
}