#include "include/game.h"
#include "include/mersenne.h"

u8 GetRandOutOf100() {
	gLastRand = randomMT() / 0x28F5C29;//100 equal sized buckets, as per haven on rhh
	return gLastRand;
}

u8 GetRand8() {
	gLastRand = randomMT();
	return (u8)gLastRand;
}

u16 GetRand16() {
	gLastRand = randomMT();
	return (u16)gLastRand;
}

u32 GetRand32() {
	gLastRand = randomMT();
	return gLastRand;
}