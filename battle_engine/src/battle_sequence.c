#include "include/battle_script.h"
#include "include/technique.h"
#include "include/battle_effects.h"

void BattleSequence_Next();
void BattleSequence_Jmp();
void BattleSequence_Goto(BattleScript script);
void BattleSequence_SetCoda(BattleScript coda) {
	gBattle.coda = coda;
}
void BattleSequence_DSAlCoda();

void BattleSequence_Init();

void BattleSequence_Block1() {
	BattleSequence_setfield();
	BattleSequence_startswitchin();
	BattleSequence_startpostswitchin();
}
void BattleSequence_setfield() {
	return;
}
void BattleSequence_startswitchin() {
	int i;
	for (i = 0; i < 4; i++) {
		if (gBattle.field.perkstims[i] == PSTIM_ONSWITCHIN) {
			BattleSequence_Goto(gPerks[gBattle.field.inhabitants[i]->effectivePerk].procscript);
		}
	}
	return;
}
void BattleSequence_startpostswitchin() {
	return;
}

void BattleSequence_Block2();
void BattleSequence_newturn() {
	BattleTurn* turn = malloc(sizeof(BattleTurn));
	turn->prev = gBattle.currentTurn;
	turn->prev->next = turn;
	gBattle.currentTurn = turn;
	gBattle.field.turnCounter++;
	SDL_memcpy(&turn->fieldState, &gBattle.field, sizeof(BattleField));


	return;
}
void BattleSequence_cinematic();
void BattleSequence_wait_preturninput();
void BattleSequence_speedcheck() {
	int i, j, temp;
	u16 speeds[4];
	u8 c[4];
	for (i = 0; i < 4; i++) {
		if (gBattle.field.inhabitants[i]->personal) {
			speeds[i]= gBattle.field.inhabitants[i]->personal->agility;
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (speeds[i] < speeds[j]) {
				c[i]++;
			}
		}
	}
	for (i = 0; i < 4; i++) {
		gBattle.currentTurn->order[c[i]] = i;
		gBattle.currentTurn->actionsTried.actionsRequested[c[i]].calculatedOrder = i;
	}
}

void BattleSequence_Block3();
void BattleSequence_startofturn();
void BattleSequence_preswitchout();
void BattleSequence_switchout();
void BattleSequence_switchin() {
	int i;
	for (i = 0; i < 4; i++) {
		if (gBattle.field.perkstims[i] == PSTIM_ONSWITCHIN) {
			BattleSequence_Goto(gPerks[gBattle.field.inhabitants[i]->effectivePerk].procscript);
		}
	}
	return;
}
void BattleSequence_postswitchin();
void BattleSequence_trytag();
void BattleSequence_tryflee();
void BattleSequence_useitem();

void BattleSequence_Block4();
void BattleSequence_pretechuse();
void BattleSequence_pretechcheckstatus() {
	BattleMon* actor = gBattle.field.inhabitants[gBattle.currentTurn->actionsTried.cursor];
	if (actor->majorStatus == STATUS_STUN) {
		BattleScript_CheckStun();
	}
	else if (actor->majorStatus == STATUS_DROWSY) {
		BattleScript_CheckDrowsy();
	}
	else if (actor->majorStatus == STATUS_DIZZY) {
		BattleScript_CheckDizzy();
	}
	if (actor->status & BATTLESTATUS_FLINCH) {

	}
}
void BattleSequence_techuse();
void BattleSequence_prepdmgattacker();
void BattleSequence_damagetargets();
void BattleSequence_prepdmgtarget();
void BattleSequence_calcdmg();
void BattleSequence_takedmg();
void BattleSequence_postdmg();
void BattleSequence_checkrecoil();

void BattleSequence_wait_midturninput();
void BattleSequence_midturnswitchout();
void BattleSequence_midturnswitchin();
void BattleSequence_postmidturnswitchin();
void BattleSequence_actionscomplete();

void BattleSequence_Block5();
void BattleSequence_turnendstatusdmg();
void BattleSequence_turnendfielddmg();
void BattleSequence_turnenditemperk();
void BattleSequence_turnendcheckfieldstatuschange();

void BattleSequence_End();

void BattleScript_CheckStun() {
	BattleMon* actor = gBattle.field.inhabitants[gBattle.currentTurn->actionsTried.cursor];
	if (rand() % 256 < 128 - actor->statStages[STATSTAGE_LUCK] * 8) {
		//Fail to attack
	}
}
void BattleScript_CheckDrowsy() {
	BattleMon* actor = gBattle.field.inhabitants[gBattle.currentTurn->actionsTried.cursor];
	if (rand() % 256 < 128 - actor->statStages[STATSTAGE_LUCK] * 8) {
		//Fail to attack
	}
}
void BattleScript_CheckDizzy() {
	int r = rand() % 256;
	BattleMon* actor = gBattle.field.inhabitants[gBattle.currentTurn->actionsTried.cursor];
	if (r < 128 - actor->statStages[STATSTAGE_LUCK] * 8) {
		if (r < 64 - actor->statStages[STATSTAGE_LUCK] * 8) {
			//Attack self
		}
		else {
			//Fail to attack
		}
	}
}