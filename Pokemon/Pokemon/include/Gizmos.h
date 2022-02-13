#pragma once

namespace Gizmos
{
	struct Vector2
	{
		double x;
		double y;

		Vector2(double _x = 0, double _y = 0)
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
