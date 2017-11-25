#include "Scene.h"
#include "GameData.h"
#include "modelclass.h"

Scene::Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance)
{
	device = _pd3dDevice;
	device->GetImmediateContext(&pd3dImmediateContext);
	m_hWnd = _hWnd;

	m_Model = new ModelClass;
	m_Model->Initialize(_pd3dDevice);
}

Scene::~Scene()
{
}

bool Scene::Tick()
{
	Draw(pd3dImmediateContext);
	return true;
}

bool Scene::Draw(ID3D11DeviceContext * context)
{
	m_Model->Render(pd3dImmediateContext);
	return true;
}

