#pragma once
#include <d3d11.h>
#include <vector>

class GameObject;
class GameData;
class ModelClass;

class Scene
{
public:
	Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance);
	virtual ~Scene();
	
	bool Tick();

	bool Draw(ID3D11DeviceContext* context);

private:
	GameData* m_GD;
	HWND m_hWnd;
	ID3D11Device* device;
	ID3D11DeviceContext* pd3dImmediateContext;
	std::vector<GameObject*> m_gameObjects;
	ModelClass* m_Model;
};