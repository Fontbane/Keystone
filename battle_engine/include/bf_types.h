#ifndef __BANEFRAME_TYPES_H__
#define __BANEFRAME_TYPES_H__

#include "SDL_types.h"

typedef Uint8 u8;
typedef Uint16 u16;
typedef Uint32 u32;
typedef Sint8 s8;
typedef Sint16 s16;
typedef Sint32 s32;

typedef Uint8 bool8;

#define HIHALF(n)	n>>8
#define LOHALF(n)	n&0xffff

typedef enum {
	DIR_EAST,
	DIR_NORTHEAST,
	DIR_NORTH,
	DIR_NORTHWEST,
	DIR_WEST,
	DIR_SOUTHWEST,
	DIR_SOUTH,
	DIR_SOUTHEAST,
	DIR_MAX
}Direction;

#define TURN_90(dir)	(dir+DIR_NORTH)%DIR_MAX
#define TURN_180(dir)	(dir+DIR_WEST)%DIR_MAX
#define TURN_270(dir)	(dir+DIR_SOUTH)%DIR_MAX

#define TEXTWORD_MAX	16
typedef char TextWord[TEXTWORD_MAX];
#define TEXTWORD_CPY(dst, src)	SDL_strlcpy(dst, src, TEXTWORD_MAX)
#define TEXTWORD_CMP(a, b)		SDL_strncmp(a, b, TEXTWORD_MAX)

#define TEXTLINE_MAX	128
typedef char TextLine[TEXTLINE_MAX];
#define TEXTLINE_CPY(dst, src)	SDL_strlcpy(dst, src, TEXTLINE_MAX)
#define TEXTLINE_CMP(a, b)		SDL_strncmp(a, b, TEXTLINE_MAX)

#define TEXTBLOCK_MAX	1024
typedef char TextBlock[TEXTBLOCK_MAX];
#define TEXTBLOCK_CPY(dst, src)	SDL_strlcpy(dst, src, TEXTBLOCK_MAX)
#define TEXTBLOCK_CMP(a, b)		SDL_strncmp(a, b, TEXTBLOCK_MAX)

typedef struct {
	u8 x;
	u8 y;
} Coord8;

typedef struct {
	s8 x;
	s8 y;
} SCoord8;

#define COORD8_EQ(a, b) a.x==b.x&&a.y==b.y


#endif /*__BANEFRAME_TYPES_H__*/
