#pragma once

#ifndef SCENE_DATA_H
#define SCENE_DATA_H

#include <dinput.h>

enum GameState
{
	NULL_STATE = 0,
	MAIN_MENU_STATE = 1,
	GAME_STATE = 2,
	PAUSED_STATE = 3,
	END_STATE = 3,
};

struct GameData
{
	float m_deltaTime; //deltatime - time between frames
	GameState m_state; //current state of simulation

	//Input
	unsigned char* m_keyboardState;
	unsigned char* m_previousKeyboardState;
	//DIMOUSESTATE* m_mouseState;
};

#endif