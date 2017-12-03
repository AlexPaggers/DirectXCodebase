#include "GameObject.h"

GameObject::GameObject()
{
	m_pos = Vector3(0.0f, 0.0f, 0.0f);
	m_pitch = 0.0f;
	m_roll = 0.0f;
	m_yaw = 0.0f;
	m_scale = Vector3(1.0f, 1.0f, 1.0f);
	m_drag = 0.5f;
	m_velocity = Vector3(0.0f, 0.0f, 0.0f);

	m_worldMat = XMMatrixIdentity();
	m_fudge = XMMatrixIdentity();

	physics = true;
}

GameObject::~GameObject()
{

}

void GameObject::Tick(GameData* _GD)
{
	if (physics)
	{
		//Vector3 new_velocity = m_velocity + (m_acceleration - m_velocity * m_drag) * _GD->m_deltaTime;
		//Vector3 new_pos = m_pos + m_velocity * _GD->m_deltaTime;
		//m_velocity = new_velocity;
		//m_pos = new_pos;

		m_velocity =	m_velocity + m_acceleration	* _GD->m_deltaTime;
		m_pos =			m_pos + m_velocity			* _GD->m_deltaTime;

		m_acceleration = Vector3(0.0f, 0.0f, 0.0f);

	}
	

	DirectX::XMMATRIX scale_matrix = XMMatrixScaling(m_scale.x, m_scale.y, m_scale.z);
	m_rotMat = XMMatrixRotationRollPitchYaw(m_pitch, m_yaw, m_roll);
	DirectX::XMMATRIX translation_matrix = XMMatrixTranslation(m_pos.x, m_pos.y, m_pos.z);
	m_worldMat = m_fudge * scale_matrix * m_rotMat * translation_matrix;

	m_acceleration = Vector3(0, 0, 0);
}