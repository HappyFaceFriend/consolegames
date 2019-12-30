#include "Vector2.h"

#include <cmath>

namespace Engine	{
	
	Vector2::Vector2()
		: x(0), y(0)
	{}
	
	Vector2::Vector2(float x, float y)
		:x(x), y(y)
	{}
	
	Vector2::Vector2(const Vector2& other)
		:x(other.x), y(other.y)
	{}
	
	Vector2::~Vector2()
	{}
	
	const Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	
	const Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	
	const Vector2 Vector2::operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}
	
	const Vector2 Vector2::operator*(float f) const
	{
		return Vector2(x*f, y*f);
	}
	
	const Vector2 operator*(float f, const Vector2& other)
	{
		return Vector2(f*other.x, f*other.y);
	}
	
	const Vector2 Vector2::operator/(const Vector2& other) const
	{
		return Vector2(x / other.x, y / other.y);
	}
	
	const Vector2 Vector2::operator/(float f) const
	{
		return Vector2(x/f, y/f);
	}
	
	bool Vector2::operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	
	bool Vector2::operator!=(const Vector2& other) const
	{
		return !((*this)==other);
	}
	
	Vector2& Vector2::operator=(const Vector2& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	
	Vector2& Vector2::operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	
	Vector2& Vector2::operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}
	
	Vector2& Vector2::operator*=(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}
	
	Vector2& Vector2::operator/=(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}
	
	Vector2& Vector2::operator*=(float f)
	{
		x *= f;
		y *= f;
		return *this;
	}
	
	Vector2& Vector2::operator/=(float f)
	{
		x /= f;
		y /= f;
		return *this;
	}
	
	float Vector2::Size() const
	{
		return sqrt(x*x+y*y);
	}
	
	const Vector2 Vector2::Normalized() const
	{
		return Vector2(x,y)/Size();
	}
	
	float Vector2::Size(const Vector2 &vec)
	{
		return vec.Size();
	}
	
	const Vector2 Vector2::Normalized(const Vector2 &vec)
	{
		return vec.Normalized();
	}
	
	float Vector2::GetDistance(const Vector2 &a, const Vector2 &b)
	{
		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	}
	
	std::ostream& Vector2::operator<<(std::ostream& stream) const
	{
		stream << "(" << x << "," << y << ")";
		return stream;
	}
	
	std::ostream& operator<<(std::ostream& stream, const Vector2& other)
	{
		stream << "(" << other.x << "," << other.y << ")";
		return stream;
	}
	
}
