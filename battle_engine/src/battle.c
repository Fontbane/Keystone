#include "include/technique.h"
#include "include/battle_setup.h"

u8 gTypeEffectiveness[TYPE_MAX][TYPE_MAX] = {
	//Row: Attacker					Column: Defender
	//? Ba Gr Fl Aq Ai To El Bu Mi Gh Ea Me Ic Br Dr 
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},	//TYPE_MYSTERY
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 1, 2, 2, 2},	//TYPE_BASIC
	{2, 2, 1, 1, 4, 2, 2, 2, 2, 2, 2, 4, 1, 2, 2, 1},	//TYPE_GRASS
	{2, 2, 4, 1, 1, 2, 2, 2, 4, 2, 2, 2, 4, 4, 2, 1},	//TYPE_FLAME
	{2, 2, 1, 1, 4, 2, 2, 2, 2, 2, 2, 4, 2, 1, 2, 1},	//TYPE_AQUA
	{2, 2, 4, 4, 4, 2, 2, 1, 2, 2, 1, 1, 1, 1, 2, 2},	//TYPE_AIR
	{2, 2, 2, 2, 2, 2, 1, 2, 4, 2, 1, 1, 0, 2, 4, 2},	//TYPE_TOXIC
	{2, 2, 1, 2, 4, 4, 2, 1, 2, 2, 2, 0, 2, 2, 2, 1},	//TYPE_ELECTRIC
	{2, 2, 4, 1, 2, 1, 2, 2, 2, 4, 1, 2, 1, 2, 1, 2},	//TYPE_BUG
	{2, 2, 2, 2, 2, 2, 4, 2, 2, 1, 4, 2, 1, 2, 4, 2},	//TYPE_MIND
	{2, 0, 2, 2, 2, 2, 2, 2, 1, 2, 4, 2, 2, 2, 2, 2},	//TYPE_GHOST
	{2, 2, 1, 4, 2, 4, 4, 4, 1, 2, 2, 2, 4, 1, 2, 2},	//TYPE_EARTH
	{2, 2, 2, 1, 1, 2, 2, 1, 2, 2, 2, 4, 1, 4, 2, 2},	//TYPE_METAL
	{2, 2, 4, 1, 1, 4, 2, 2, 4, 2, 2, 4, 1, 1, 2, 4},	//TYPE_ICE
	{2, 4, 2, 2, 2, 1, 1, 2, 1, 1, 0, 4, 4, 4, 2, 2},	//TYPE_BRAWL
	{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 4},	//TYPE_DRAGON
	//? Ba Gr Fl Aq Ai To El Bu Mi Gh Ea Me Ic Br Dr 

	//Immune: 0		NVE: 1		Neutral: 2		SE:4
};

BattleActionResult battleturn_ExecuteBattleAction(u8 actionID) {
	BattleActionResult result = { 0 };
	BattleAction action = gBattle.currentTurn->actionsTried.actionsRequested[actionID];
	PersonalData* actor = gBattle.setup.challengerParties[action.actor];
	result.action = actionID;
	//TODO: Check if tech can be used

	battleEV_CalculateDamage(&action, gBattle.field.inhabitants[action.target]);

	battleEV_UseTechnique(&action, &result);
	
	return result;
}

bool8 battleEV_DetermineCrit(BattleAction* action, BattleMon* target) {
	TechniqueStats tech = gTechniqueStats[action->techToUse];
	BattleMon* attacker = gBattle.field.inhabitants[action->actor];
	if (tech.flags & TECHFLAG_ALWAYSCRIT) {
		return SDL_TRUE;
	}
	return (
		rand() % 10001 + 625
		+ 625 * attacker->statStages[STATSTAGE_LUCK] 
		- 625 * target->statStages[STATSTAGE_LUCK])
		*(tech.flags&TECHFLAG_HICRIT?2:1
	) > 999;
}

s32 battleEV_CalculateDamage(BattleAction* action, BattleMon* target) {
	TechniqueStats tech = gTechniqueStats[action->techToUse];
	BattleMon* attacker = gBattle.field.inhabitants[action->actor];
	//The damage formula!
	s32 dmg = 
		(tech.power
		* (attacker->personal->level/2 + 1)
		* (tech.category==CATEGORY_PHYSICAL)?(attacker->personal->attack):(attacker->personal->mag_attack)
		/ (tech.category == CATEGORY_PHYSICAL) ? (target->personal->defense) : (target->personal->mag_defense)		//Attack/Defense
		/ 50
		+ 1)
		* gTypeEffectiveness[tech.type][target->type1] * gTypeEffectiveness[tech.type][target->type2] / 2			//Type effectiveness
		* (rand() % 16 + 85 + 5*attacker->statStages[STATSTAGE_LUCK]-5*target->statStages[STATSTAGE_LUCK]) / 100	//Random factor w/ luck
		* ((battleEV_DetermineCrit(action,target)?150:100)/100)
		;
	
	return dmg;
}

void battleEV_UseTechnique(BattleAction* action, BattleActionResult* result) {
	TechniqueStats tech = gTechniqueStats[action->techToUse];
	//Damage calculation!



	return;
}