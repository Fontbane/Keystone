#ifndef __FIELDMAP_H__
#define __FIELDMAP_H__

#include "constants/bf_types.h"
#include "entity.h"

typedef void(*TileCB)(void);

typedef struct {
	u32 numTiles;
	u16 *metatiles;
	u16 *metatile_attributes;
	TileCB callback;
}Tileset;

typedef struct {
	u16 width;
	u16 height;

	u16 borderBlock[4];
	u16 *map;
	u16 *layer2;
	u16 *collision;
}MapLayout;

typedef struct {
	u16 mapId;
	u8 dir;
	u8 offset;
}MapConnection;

typedef struct {
	u16 species;
	u8 form;
	u8 level;
}Encounter;

enum {
	ENCTYPE_LAND,
	ENCTYPE_WATER,
	ENCTYPE_FISHING
};

typedef struct {
	const MapLayout *layout;
	const Tileset *tileset;

	u16 id;
	u16 music;

	u8 worldMapSection;
	u8 weather;
	u8 mapType;
	u8 battleType;

	u32 flags;

	Encounter landEncounters[12];
	Encounter waterEncounters[8];
	Encounter fishingEncounters[8];

	u8 encounterRate;
	u8 numConnections;
	MapConnection *mapConnections;
}MapHeader;

#define LAND_ENCOUNTERS		12
#define WATER_ENCOUNTERS	10
#define FISHING_ENCOUNTERS	8

void map_draw();
MapHeader* map_init(u16 mapId);
u16 GetMetatileIdAt(u8 x, u8 y);
u8 GetMetatileBehaviorAt(u8 x, u8 y);
Encounter fldsp_trygetencounter(MapHeader* map, u8 encounterType, u32 encounterFlags);


/*GLOBAL VARIABLE GMAPHEADER*/
extern MapHeader* gMapHeader;

extern Tileset* gTilesets;
extern MapLayout* gMapLayouts;

#endif /*__FIELDMAP_H__*/
