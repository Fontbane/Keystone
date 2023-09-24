#ifndef __BATTLE_SETUP_H__
#define __BATTLE_SETUP_H__

#include "monster.h"
#include "stdlib.h"

#define MONS_PER_SIDE	2
#define MAX_PARTICIPANTS	(MONS_PER_SIDE*2)

enum {
	ME_L,
	ME_R,
	ENEMY_L,
	ENEMY_R
};

typedef struct battle_s {
	BattleSetup setup;
	BattleField field;
	BattleRecord record;
	BattleTurn* currentTurn;
	u32 coda;
} Battle;

typedef struct battlesetup_s {
	u32 flags;

	PersonalData* challengerParties[PARTY_SIZE*2];

	BattleField* initialfield;
} BattleSetup;

typedef struct battleside_s {
	u8 id;
	u8 counter;
	u8 counter2;
	u32 status;
	BattleMon* inhabitants[MONS_PER_SIDE];
} BattleSide;

typedef struct battlefield_s {
	u32 status;
	u8 statusCounter;
	u8 fleeAttempts;
	u16 miscCounter;

	BattleSide sides[2];

	PersonalData* challenger1Party[PARTY_SIZE];
	PersonalData* challenger2Party[PARTY_SIZE];
	BattleMon* inhabitants[MAX_PARTICIPANTS];

	u16 turnCounter;
	u8 fieldType;
	u8 battleType;

	u16 lastUsedTechnique;
	u16 lastUsedItem;
	u8 lastUsedPerk;
	u8 lastActionResult;
	u8 weather;
	u8 weatherCounter;

	u8 itemstims[4];
	u8 perkstims[4];

	s32 lastDamageDealt;
} BattleField;

#define BACTIONFLAG_PREEMPTIVE		0x01
#define BACTIONFLAG_CANNOT_PREEMPT	0x02
#define BACTIONFLAG_FINISHED		0x10

typedef struct battleaction_s {
	u8 actor;//participant id
	u8 target;//target's participant id, if there is one
	//u8 techDir;//If tech is skewed to a direction
	//u8 dodgeDir;//Which direction are you dodging?
	u16 techToUse;
	u8 swap;//if mon swapped out, then to who?
	u8 calculatedOrder;
	//u8 techTargets;
	u16 bagItemToUse;
	u32 flags;
} BattleAction;


//Actions requested by one side
typedef struct battlesideactions_s {
	BattleAction actionsRequested[MONS_PER_SIDE];
	u8 numActions;
} BattleSideActions;

//Once actions are gathered from both sides, put it in a queue based on turn order protocol
typedef struct battleactionq_s {
	BattleAction actionsRequested[MAX_PARTICIPANTS];
	u8 numActions;
	u8 cursor;
} BattleActionQueue;

typedef struct battleactionindividualresult_s {
	BattleAction* action;
	s32 damageActorDealt; //Total Damage Dealt
	s32 damageActorTaken;

	u16 techUsed;
	u16 filler;

	u8 effectiveness;
	u8 perkProc;
	u16 itemProc;

	u32 flags;
} BattleActionIndividualResult;

typedef struct battleactionresult_s {
	u8 action;
	u8 preemption;//An action may be pre-empted
	u8 numTargetsHit;
	u8 numTargetsHealed;

	BattleActionIndividualResult individualResults[MAX_PARTICIPANTS];

	s32 totalDamageActorDealt; //Total Damage Dealt
	s32 totalDamageActorTaken;

	u16 techUsed;	//A different tech might be used due to shenanigans
	u16 bagItemUsed;

	u32 flags;
} BattleActionResult;

typedef struct battleturn_s {
	BattleField fieldState;
	BattleActionQueue actionsTried;
	BattleActionResult actionResults[MAX_PARTICIPANTS];
	u8 order[4];
	struct battleturn_s* prev;
	struct battleturn_s* next;
} BattleTurn;

typedef struct battle_s {
	BattleTurn* turns;

	PersonalData* challenger1Party[6];
	PersonalData* challenger2Party[6];
} BattleRecord;

void battle_Setup(u8 battleType, u8 fieldType, u8 c1PartySize, u8 c2PartySize, PersonalData* participants);
void battle_PromptAction();
void battle_ChooseAction(BattleAction* action);
void battle_DetermineAIAction();
void battleturn_DoPreliminaryCalcs(BattleTurn* turn, BattleActionQueue* actions);
void battleturn_DetermineActionOrder(BattleTurn* turn);
BattleActionResult battleturn_ExecuteBattleAction(u8 actionID);
void battleturn_PromptMidturnAction(BattleTurn* turn);
void battleturn_DetermineMidturnAIAction(BattleTurn* turn);
void battleturn_HandleEndOfTurnEvents(BattleTurn* turn);
void battle_EndBattle();

bool8 battleEV_DetermineCrit(BattleAction* action, BattleMon* target);
s32 battleEV_CalculateDamage(BattleAction* action, BattleMon* target);
void battleEV_UseTechnique(BattleAction* action, BattleActionResult* result);

Battle gBattle;

#endif // !__BATTLE_SETUP_H__
