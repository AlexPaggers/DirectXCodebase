#pragma once
#include "GameData.h"
#include "GameObject.h"
#include <memory>
#include <vector>
#include "MathVector.h"

class Game
{
public:
	void tick();

private:

	std::unique_ptr<GameData> m_GD;
	std::vector<GameObject*> m_gameObjects;


};