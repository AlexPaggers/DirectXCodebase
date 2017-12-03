#pragma once

#include "GameData.h"
#include <DirectXMath.h>
#include <d3d11.h>
#include "MathVector.h"

using namespace DirectX;

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Tick(GameData* _GD);
	virtual void Draw(ID3D11DeviceContext* _DD) = 0;

	//getters
	Vector3		GetPos() { return m_pos; }
	Vector3		GetVelocity() { return m_velocity; }
	Vector3		GetScale() { return m_scale; }
	float		GetPitch() { return m_pitch; }
	float		GetYaw() { return m_yaw; }
	float		GetRoll() { return m_roll; }

	XMMATRIX	GetWorldMat() { return m_worldMat; }
	XMMATRIX	GetFudge() { return m_fudge; }
	XMMATRIX	GetRotationMat() { return m_rotMat; }


	//setters
	void		SetPos(Vector3 _pos) { m_pos = _pos; }
	//void		Set

	void		SetScale(float _scale) { m_scale = Vector3(1,1,1) * _scale; }
	void		SetScale(float _x, float _y, float _z) { m_scale = Vector3(_x, _y, _z); }
	void		SetScale(Vector3 _scale) { m_scale = _scale; }

	void		SetPitch(float _pitch) { m_pitch = _pitch; }
	void		SetYaw(float _yaw) { m_yaw = _yaw; }
	void		SetRoll(float _roll) { m_roll = _roll; }
	void		SetPitchYawRoll(float _pitch, float _yaw, float _roll) { m_pitch = _pitch; m_yaw = _yaw; m_roll = _roll; }
	void		SetAcceleration(Vector3 _acc) { m_acceleration = _acc; }


protected:

	XMMATRIX m_worldMat;
	XMMATRIX m_rotMat;
	XMMATRIX m_fudge;

	float m_pitch, m_yaw, m_roll;
	float m_drag;
	
	Vector3 m_scale;
	Vector3 m_pos;

	Vector3 m_velocity;
	Vector3 m_acceleration;

	bool physics;

};
