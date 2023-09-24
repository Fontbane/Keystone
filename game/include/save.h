#ifndef __SAVE_H__
#define __SAVE_H__

#include "constants/bf_types.h"

typedef struct {
	TextWord name;
	time_t startTime;
	time_t playTime;
	time_t lastPlayed;
	time_t clearTime;
	u8 bikeProgress;
} PlayerData;

typedef struct {
	u8 hash1;
	u16 salt;
	u8 hash2;

	u8 hash3;
	u8 bikeProgress;
	u8 hash4;

	u8 hash5;
	u16 mapId;
	u8 hash6;

	u32 hash7;

	u32 itemFlags;

	u32 hash8;

	u32 eventFlags;

	u8 hash9;
	u16 pepper;
	u8 hashA;
}SaveData;

PlayerData gPlayerData;
SaveData gBackupSave;
SaveData gSave;

#endif // !__SAVE_H__
