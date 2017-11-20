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
	END_STATE = 4,
};

struct GameData
{
	float m_deltaTime; 
	GameState m_state; 

	//Input
	unsigned char* m_keyboardState;
	unsigned char* m_previousKeyboardState;
	//DIMOUSESTATE* m_mouseState;
};

#endif