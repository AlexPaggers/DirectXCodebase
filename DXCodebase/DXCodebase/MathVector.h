#pragma once
#include <cmath>

struct Vector3
{
	float x, y, z;

	inline Vector3(void) {}
	inline Vector3(const float _x, const float _y, const float _z)
	{
		x = _x; y = _y; z = _z;
	}

	inline Vector3 operator + (const Vector3& _vector3) const
	{
		return Vector3(x + _vector3.x, y + _vector3.y, z + _vector3.z);
	}

	inline Vector3 operator += (const Vector3& _vector3) const
	{
		return Vector3(x + _vector3.x, y + _vector3.y, z + _vector3.z);
	}

	inline Vector3 operator - (const Vector3& _vector3) const
	{
		return Vector3(x - _vector3.x, y - _vector3.y, z - _vector3.z);
	}

	inline Vector3 operator + (const float _vector3) const
	{
		return Vector3(x + _vector3, y + _vector3, z + _vector3);
	}

	inline Vector3 operator * (const float _multiplier) const
	{
		return Vector3(x * _multiplier, y * _multiplier, z * _multiplier);
	}

	inline float Dot(const Vector3& _vector3) const
	{
		return _vector3.x*x + _vector3.y*y + _vector3.z*z;
	}

	inline float Distance(const Vector3& vector1, const Vector3& vector2)
	{
		float _zDifference = vector1.z - vector2.z;
		float _yDifference = vector1.y - vector2.y;
		float _xDifference = vector1.x - vector2.x;
		return sqrt((_zDifference * _zDifference) + (_yDifference * _yDifference) + (_xDifference * _xDifference));
	}

	inline float Magnitude(const Vector3& _vector3)
	{
		return sqrt((_vector3.x * _vector3.x) + (_vector3.y * _vector3.y) + (_vector3.z * _vector3.z));
	}


};

struct Vector2
{

	float x, y;

	inline Vector2(void) {}
	inline Vector2(const float _x, const float _y)
	{
		x = _x; y = _y;
	}

	inline Vector2 operator + (const Vector3& _vector2) const
	{
		return Vector2(x + _vector2.y, y + _vector2.y);
	}

	inline Vector2 operator + (const float _vector2) const
	{
		return Vector2(x + _vector2, y + _vector2);
	}

	inline float Distance(const Vector2& vector1, const Vector2& vector2)
	{
		float _yDifference = vector1.y - vector2.y;
		float _xDifference = vector1.x - vector2.x;
		return sqrt((_yDifference * _yDifference) + (_xDifference * _xDifference));
	}

	inline float Magnitude(const Vector2& _vector2)
	{
		return sqrt((_vector2.x * _vector2.x) + (_vector2.y * _vector2.y));
	}

};