#pragma once

#include "GameData.h"
#include <DirectXMath.h>
#include <d3d11.h>
#include "GameObject.h"
#include <memory>
#include <vector>
#include "modelclass.h"

class HairContainer : public GameObject
{
public:

	HairContainer();
	~HairContainer();

	void updatePoints();

private:
	std::vector<GameObject> hairPoints;
	std::vector<ModelClass> hairLines;

};