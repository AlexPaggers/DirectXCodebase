#include "game.h"

void Game::tick()
{
	for (auto &_gameObject : m_gameObjects) 
	{
		_gameObject->tick(m_GD.get());
	}
}
