

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
	};
}
