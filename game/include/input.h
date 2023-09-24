#ifndef __INPUT_H__
#define __INPUT_H__

#include "SDL_gamecontroller.h"



typedef struct {
	SDL_GameControllerButton left;
	SDL_GameControllerButton right;
	SDL_GameControllerButton up;
	SDL_GameControllerButton down;
	SDL_GameControllerButton hop;
	SDL_GameControllerButton shiftGear;
	SDL_GameControllerAxis turnAxisX;
	SDL_GameControllerAxis turnAxisY;
	SDL_GameControllerAxis brakeAxis;
	SDL_GameControllerAxis throttleAxis;
	SDL_GameControllerAxis wheelieAxisX;
	SDL_GameControllerAxis wheelieAxisY;
} ControllerBindings;

typedef struct {
	SDL_KeyCode left;
	SDL_KeyCode right;
	SDL_KeyCode up;
	SDL_KeyCode down;
	SDL_KeyCode wheelieLeft;
	SDL_KeyCode wheelieRight;
	SDL_KeyCode hop;
	SDL_KeyCode shiftGear;
	SDL_KeyCode grind;
	SDL_KeyCode brake;
	SDL_KeyCode cruise;
	SDL_KeyCode throttle;
} KeyboardBindings;

ControllerBindings gBackupCtrlBindings;
ControllerBindings gControllerBindings;

KeyboardBindings gBackupKeyboardBindings;
KeyboardBindings gKeyboardBindings;

#endif // !__INPUT_H__
