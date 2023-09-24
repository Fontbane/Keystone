// game.c : Defines the entry point for the application.
//

#include <time.h>
#include "include/game.h"

void init_game() {
	gRandSeed = ((time(0) * 0xbeef) << 4 )^ 0xdeadbeef;
}

int main()
{

}
