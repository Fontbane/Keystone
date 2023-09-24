#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "constants/bf_types.h"

enum {
	ENTTYPE_NONE,
	ENTTYPE_EVENTOBJ,
	ENTTYPE_WARP,
	ENTTYPE_SIGN,
	ENTTYPE_ITEM,
	ENTTYPE_TRIGGER,
	ENTTYPE_MAX
};

#define WARPFLAG_LOCAL	0x01
#define WARPFLAG_SPIN	0x02
#define WARPFLAG_FADE	0x04

#define ITEMEVFLAG_HIDDEN	0x01

#define ENTFLAG_INTERACTABLE	1<<31
#define ENTFLAG_CAMERA			1<<30
#define ENTFLAG_BG				1<<29

typedef struct warp_s {
	u8 warpId;
	u8 targetWarpId;
	u8 targetMapGroup;
	u8 targetMapId;
}Warp;

typedef struct signpost_s {
	u16 textId;
	u8 background;
	u8 filler;
}Signpost;

typedef struct itemevent_s {
	u16 item_id;
	u16 save_flag;
}ItemEvent;

typedef enum {
	TURNCMD_NONE,
	TURNCMD_EAST,
	TURNCMD_NORTH,
	TURNCMD_WEST,
	TURNCMD_SOUTH,
	TURNCMD_90,
	TURNCMD_180,
	TURNCMD_270,
	TURNCMD_SPIN,
	TURNCMD_90_CLOCKWISE,
	TURNCMD_180_CLOCKWISE,
	TURNCMD_270_CLOCKWISE,
	TURNCMD_SPIN_CLOCKWISE,
	TURNCMD_CPY_MOVE,
	TURNCMD_FACE_PLAYER,
	TURNCMD_FACE_AWAY_PLAYER,
	TURNCMD_MAX
}TurnCmd;

typedef enum {
	MOVECMD_NONE,
	MOVECMD_RIGHT,
	MOVECMD_UP,
	MOVECMD_LEFT,
	MOVECMD_DOWN,
	MOVECMD_FACING,
	MOVECMD_BACKWARDS,
	MOVECMD_SIDE_LEFT,
	MOVECMD_SIDE_RIGHT,
	MOVECMD_HOP,
	MOVECMD_JUMP_RIGHT,
	MOVECMD_JUMP_UP,
	MOVECMD_JUMP_LEFT,
	MOVECMD_JUMP_DOWN,
	MOVECMD_JUMP_FACING,
	MOVECMD_JUMP_BACKWARDS,
	MOVECMD_HOP_FACING,
	MOVECMD_HOP_BACKWARDS,
	MOVECMD_HOP_SIDE_LEFT,
	MOVECMD_HOP_SIDE_RIGHT,
	MOVECMD_SLIDE,
	MOVECMD_SLIDE_FACING,
	MOVECMD_SLIDE_BACKWARDS,
	MOVECMD_SLIDE_SIDE_LEFT,
	MOVECMD_SLIDE_SIDE_RIGHT,
	MOVECMD_SLIDE_UP,
	MOVECMD_SLIDE_DOWN,
	MOVECMD_SLIDE_LEFT,
	MOVECMD_SLIDE_RIGHT,
	MOVECMD_MAX
}MoveCmd;

typedef struct movementcmd_s {
	struct movementcmd_s* next;
	TurnCmd turn;
	MoveCmd mvmt;
	u32 flags;
}MovementCmd;

typedef struct moveq_s {
	MovementCmd* head;
	MovementCmd* tail;
	int len;
}MoveQ;

typedef struct eventobject_s {
	u16 scriptid;
	u8 movementtype;
	u8 sightradius_plantid;

	Coord8 targetPos;
	u32 flags;
	
	void(*ThinkScript)(void *self);
	void(*UpdateScript)(void* self);
	
}EventObject;

enum {
	MOVEMENTTYPE_NONE,
	
	MOVEMENTTYPE_CIRCLE_SMALL,
	MOVEMENTTYPE_CIRCLE_MED,
	MOVEMENTTYPE_CIRCLE_LARGE,

	MOVEMENTTYPE_CIRCLE_SMALL_CC,
	MOVEMENTTYPE_CIRCLE_MED_CC,
	MOVEMENTTYPE_CIRCLE_LARGE_CC,

	MOVEMENTTYPE_FACE_RANDOM,
	MOVEMENTTYPE_FACE_LEFT_DOWN,
	MOVEMENTTYPE_FACE_RIGHT_DOWN,
	MOVEMENTTYPE_FACE_LEFT_UP,
	MOVEMENTTYPE_FACE_RIGHT_UP,
	MOVEMENTTYPE_FACE_LEFT_RIGHT,
	MOVEMENTTYPE_FACE_UP_DOWN,

	MOVEMENTTYPE_RUN_LEFT_RIGHT,
	MOVEMENTTYPE_RUN_UP_DOWN,

	MOVEMENTTYPE_PACE_LR,
	MOVEMENTTYPE_PACE_UPDOWN,
	MOVEMENTTYPE_PACE_RANDOM,
};

enum {
	MOVESTATE_STOPPED,
	MOVESTATE_TRANSITION,
	MOVESTATE_NEW_TILE
};

typedef struct edict_s {
	u16 id;
	u8 type;
	u8 isActive;

	Coord8 origin;
	u8 facing;
	u8 frame;

	u8 x;
	u8 y;
	u8 z;
	u8 moveState;

	MoveQ moveq;

	u16 tracker16;
	u8 tracker8;
	u8 tracker8_2;

	union {
		Warp w;
		Signpost s;
		ItemEvent i;
		EventObject e;
	} info;

	u32 timer;

	u32 flags;

	struct edict_s *target;

	void (*InteractCB)(struct edict_s *self);
	void (*CollideCB)(struct edict_s *self);
}Entity;

void init_ent_manager();

void ent_think_all();
void ent_update_all();
void ent_free(Entity* ent);

#endif /*__ENTITY_H__*/