#ifndef __MERSENNE_H__
#define __MERSENNE_H__

#include "constants/bf_types.h"

void seedMT(u32 seed);
u32 reloadMT(void);
u32 randomMT(void);

#endif /*__MERSENNE_H__*/
