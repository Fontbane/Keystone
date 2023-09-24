#include "include/game.h"
#include "include/fieldmap.h"

const u8 LandEncounterIndex[] = {
	20,
	20,
	10,
	10,
	10,
	10,
	5,
	5,
	4,
	4,
	1,
	1
};
const u8 WaterEncounterIndex[] = {
	30,
	20,
	10,
	10,
	10,
	5,
	5,
	5,
	4,
	1
};
const u8 FishingEncounterIndex[] = {
	30,
	30,
	10,
	10,
	10,
	5,
	4,
	1
};


Encounter fldsp_trygetencounter(MapHeader* map, u8 encounterType, u32 encounterFlags) {
	Encounter e = {
		.species = 0,
		.form = 0,
		.level = 0
	};
	u8 r = GetRandOutOf100();
	u8 i;
	u8 c=0;
	switch (encounterType) {
	case ENCTYPE_LAND:
		for (i = 0; i < LAND_ENCOUNTERS;i++) {
			c += LandEncounterIndex[i];
			if (r < c) {
				return map->landEncounters[i];
			}
		}
		break;

	case ENCTYPE_WATER:
		for (i = 0; i < WATER_ENCOUNTERS; i++) {
			c += WaterEncounterIndex[i];
			if (r < c) {
				return map->waterEncounters[i];
			}
		}
		break;
	case ENCTYPE_FISHING:
		for (i = 0; i < FISHING_ENCOUNTERS; i++) {
			c += FishingEncounterIndex[i];
			if (r < c) {
				return map->fishingEncounters[i];
			}
		}
		break;
	}
	return e;
}