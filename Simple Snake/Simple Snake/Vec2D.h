#pragma once
#include <iostream>
#include <cmath>

namespace mEngine
{
	
	class Vec2D
	{
	public:
		float x, y;

		Vec2D(float x = 0, float y = 0) : x(x), y(y) {}

		void Log(const std::string& msg = "") const {
			std::cout << msg << ' ';
			std::cout << "(X,Y)" << '(' << x << "," << y << ')' << '\n';
		}

		// arithmetic operators
		inline Vec2D operator+(const Vec2D& other) const { return { x + other.x, y + other.y }; }
		inline Vec2D operator-(const Vec2D& other) const { return { x - other.x, y - other.y }; }
		inline Vec2D operator*(float scalar) const { return { x * scalar, y * scalar }; }
		inline Vec2D operator/(float scalar) const { return { x / scalar, y / scalar }; }

		// assignment operators
		inline Vec2D& operator+=(const Vec2D& other) { x += other.x; y += other.y; return *this; }
		inline Vec2D& operator-=(const Vec2D& other) { x -= other.x; y -= other.y; return *this; }
		inline Vec2D& operator/=(float scalar) { x /= scalar; y /= scalar; return *this; }
		inline Vec2D& operator*=(float scalar) { x *= scalar; y *= scalar; return *this; }

		// comparison operators
		inline bool operator==(const Vec2D& other) const { return x == other.x && y == other.y; }
		inline bool operator!=(const Vec2D& other) const { return !(*this == other); }

	};	
}