

#pragma once

namespace Gizmos
{
	struct Vector2
	{
		int x;
		int y;

		Vector2(int _x = 0, int _y = 0)
		{
			x = _x;
			y = _y;
		}
		Vector2(const Vector2& other)
		{
			x = other.x;
			y = other.y;
		}
		Vector2& operator+(const Vector2& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		Vector2& operator-(const Vector2& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vector2& operator*(const Vector2& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}
		Vector2& operator*(const int other)
		{
			x *= other;
			y *= other;
			return *this;
		}
		Vector2& operator/(const Vector2& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}
		Vector2& operator/(const int other)
		{
			x /= other;
			y /= other;
			return *this;
		}
	};

	struct Vector2f
	{
		float x;
		float y;

		Vector2f(float _x = 0, float _y = 0)
		{
			x = _x;
			y = _y;
		}
		Vector2f(const Vector2f& other)
		{
			x = other.x;
			y = other.y;
		}
		Vector2f& operator+(const Vector2f& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		Vector2f& operator-(const Vector2f& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vector2f& operator*(const Vector2f& other)
		{
			x *= other.x;
			y *= other.y;
			return *this;
		}
		Vector2f& operator*(const float other)
		{
			x *= other;
			y *= other;
			return *this;
		}
		Vector2f& operator/(const Vector2f& other)
		{
			x /= other.x;
			y /= other.y;
			return *this;
		}
		Vector2f& operator/(const float other)
		{
			x /= other;
			y /= other;
			return *this;
		}
	};
}
