#include "Scene.h"
#include "GameData.h"
#include "modelclass.h"
#include <DirectXMath.h>


Scene::Scene(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance)
{
	device = _pd3dDevice;
	device->GetImmediateContext(&pd3dImmediateContext);
	m_hWnd = _hWnd;

	m_SceneData = new GameData();
	m_Model = new ModelClass(Vector3(0,0,0), Vector3(1,1,1));
	m_Model->Initialize(_pd3dDevice);
	m_GameObjects.push_back(m_Model);
}

Scene::~Scene()
{
}

bool Scene::Tick()
{
	DWORD currentTime = GetTickCount();
	m_SceneData->m_deltaTime = min((float)(currentTime - m_playTime) / 1000.0f, 0.1f);
	m_playTime = currentTime;
	
	for (auto& go : m_GameObjects)
	{
		go->SetAcceleration(Vector3(0, 0, 0));
		//go->SetPos(Vector3(go->GetPos().x + 0.01f, go->GetPos().y, go->GetPos().z));
		//go->SetRoll(go->GetRoll() + 0.01);
		//go->SetScale(Vector3(go->GetScale().x, go->GetScale().y + 0.01f, go->GetScale().z));
		go->Tick(m_SceneData);
	}
	Draw(pd3dImmediateContext);
	return true;
}

bool Scene::Draw(ID3D11DeviceContext * context)
{
	for (auto& go : m_GameObjects)
	{
		go->Draw(context);
	}
	
	return true;
}

DirectX::XMMATRIX Scene::getMatrices()
{
	XMMATRIX matrix = XMMatrixIdentity();
	for (auto& gameObject : m_GameObjects)
	{
		matrix *= gameObject->GetWorldMat();
	}
	return matrix;
}

//XMMATRIX Scene::getMatrices()
//{
//	XMMATRIX matrix = XMMatrixIdentity();
//	for (auto& gameObject : m_GameObjects)
//	{
//		matrix *= gameObject->GetWorldMat();
//	}
//	return matrix;
//}


