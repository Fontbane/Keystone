#include "include/technique.h"
#include "include/battle_setup.h"

typedef void* (*BattleScript)(void);

void BattleSequence_Next();
void BattleSequence_Jmp();
void BattleSequence_Goto(BattleScript script);
void BattleSequence_SetCoda(BattleScript coda);
void BattleSequence_DSAlCoda();

void BattleSequence_Init();

void BattleSequence_Block1();
	void BattleSequence_setfield();
	void BattleSequence_startswitchin();
	void BattleSequence_startpostswitchin();

void BattleSequence_Block2();
	void BattleSequence_newturn();
	void BattleSequence_cinematic();
	void BattleSequence_wait_preturninput();
	void BattleSequence_speedcheck();

void BattleSequence_Block3();
	void BattleSequence_startofturn();
	void BattleSequence_preswitchout();
	void BattleSequence_switchout();
	void BattleSequence_switchin();
	void BattleSequence_postswitchin();
	void BattleSequence_trytag();
	void BattleSequence_tryflee();
	void BattleSequence_useitem();

void BattleSequence_Block4();
	void BattleSequence_pretechuse();
	void BattleSequence_pretechcheckstatus();
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

void BattleEV_RaiseStats(u8 participant, u8 stat, s8 stages);

void BattleEV_RaiseMultipleStats(u8 participant, s8 atk, s8 def, s8 ma, s8 md, s8 ag, s8 luck);

void BattleEV_ForceSwitchOut(u8 participant);

void BattleEV_ApplyStatus(u8 participant, u32 status);


enum {
	//Block 1: Start battle
	BATTLESEQ_EYECATCH,
	BATTLESEQ_START_SETFIELD,
	BATTLESEQ_START_SWITCHIN,
	BATTLESEQ_START_POSTSWITCHIN,

	//Block 2: Wait for input then check rough order of actions
	BATTLESEQ_NEWTURN,

	BATTLESEQ_CINEMATIC,

	BATTLESEQ_WAIT_INPUT,

	BATTLESEQ_SPEEDCHECK,

	//Block 3: Non-technique actions.
	//Repeat following for every non-technique action in action queue
	//then proceed to block 4 OR skip to block 4 as part of BATTLESEQ_PRESWITCHOUT then return
	BATTLESEQ_PRESWITCHOUT,
	BATTLESEQ_SWITCHOUT,
	BATTLESEQ_SWITCHIN,
	BATTLESEQ_POSTSWITCHIN,
	BATTLESEQ_TRYTAG,
	BATTLESEQ_TRYFLEE,
	BATTLESEQ_ITEMUSE,

	//Block 4: Use techniques.
	//Repeat following for every tech in action queue
	BATTLESEQ_PRETECHUSE,
	//Check if the user heals their status before using tech
	BATTLESEQ_CHECKSTATUSHEAL,
	//Declare the tech will be used
	BATTLESEQ_TECHUSE,
	//Apply effects, events for attacker
	BATTLESEQ_PREPDAMAGEATTACKER,
	//Personalize damage to target,
	BATTLESEQ_PREPDAMAGETARGET,
	BATTLESEQ_CALCDAMAGE,
	BATTLESEQ_TAKEDAMAGE,
	BATTLESEQ_POSTDAMAGE,
	//Loop back to BATTLESEQ_PREPDAMAGETARGET for each target
	BATTLESEQ_CHECKRECOIL,
	//If using a switching move
	BATTLESEQ_WAIT_MIDTURNINPUT,
	BATTLESEQ_MIDTURNSWITCHOUT,
	BATTLESEQ_MIDTURNSWITCHIN,
	BATTLESEQ_POSTMIDTURNSWITCHIN,
	//Loop back to BATTLESEQ_PRETECHUSE for next tech
	BATTLESEQ_ACTIONSCOMPLETE,

	//Block 5: End of turn events.
	BATTLESEQ_TURNEND_STATUSDMG,
	BATTLESEQ_TURNEND_FIELDDMG,
	BATTLESEQ_TURNEND_ITEMPERK,
	BATTLESEQ_TURNEND_CHECKFIELDSTATUSCHANGE,
	//Loop back to Block 2 until battle ends, then proceed to BATTLESEQ_END

	BATTLESEQ_END
};

enum {
	BS_END,
	BS_HIT,
	BS_MAX
};


void BattleScript_CheckStun();
void BattleScript_CheckDrowsy();
void BattleScript_CheckDizzy();

void BattleScript_EffectHit();
void BattleScript_EffectHitStatusChance();
void BattleScript_EffectHitDrainHP();
void BattleScript_EffectHitDrainNRG();
void BattleScript_EffectHitLowerOppStats();
void BattleScript_EffectHitLowerOwnStats();
void BattleScript_EffectHitRaiseOwnStats();
void BattleScript_EffectHitRecoil25();
void BattleScript_EffectHitRecoil50();
void BattleScript_EffectHitTwice();
void BattleScript_EffectHitMulti();
void BattleScript_EffectHitBeforeSwitch();
void BattleScript_EffectHitOnFirstTurn();
void BattleScript_EffectHitSwap();

void BattleScript_EffectLowerOppStats();
void BattleScript_EffectRaiseOwnStats();
void BattleScript_EffectLowerOwnStats();

void BattleScript_TrySwap();

void BattleScript_TryLowerOppStats();
void BattleScript_TryRaiseOwnStats();
void BattleScript_TryLowerOwnStats();
void BattleScript_TryInflictMajorStatus();
void BattleScript_TryInflictBattleStatus();
void BattleScript_TrySetHazards();
void BattleScript_TryClearHazards();

static BattleScript gBattleScripts[BS_MAX];