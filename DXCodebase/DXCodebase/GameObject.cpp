#include "GameObject.h"

GameObject::GameObject()
{
<<<<<<< HEAD
	//m_worldMat = XMFLOAT4X4(
	//	1, 2, 3, 4,
	//	5, 6, 7, 8,
	//	9, 10, 11, 12,
	//	13, 14, 15, 16);

	//m_fudge = XMFLOAT4X4(
	//	1, 2, 3, 4,
	//	5, 6, 7, 8,
	//	9, 10, 11, 12,
	//	13, 14, 15, 16);
=======
	m_worldMat = XMFLOAT4X4(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);

	m_fudge = XMFLOAT4X4(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16);
>>>>>>> c5cdf751d494af544a85e377889bf5034825443c
}

GameObject::~GameObject()
{

}

void GameObject::tick(GameData* _GD)
{

}

void GameObject::draw(ID3D11DeviceContext * _DD)
{

}
