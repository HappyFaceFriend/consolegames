#pragma once

namespace Engine	{
	
	struct Vector2
	{
		float x, y;
		
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& other);
		~Vector2();
	
		const Vector2 operator+(const Vector2& other) const;
		const Vector2 operator-(const Vector2& other) const;
		const Vector2 operator*(const Vector2& other) const;
		const Vector2 operator*(float f) const;
		friend const Vector2 operator*(float f, const Vector2& other);
		const Vector2 operator/(const Vector2& other) const;
		const Vector2 operator/(float f) const;
		
		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;
		
		Vector2& operator=(const Vector2& other);
		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator*=(float f);
		Vector2& operator/=(const Vector2& other);
		Vector2& operator/=(float f);
		
		std::ostream& operator<<(std::ostream& stream) const;
		friend std::ostream& operator<<(std::ostream& stream, const Vector2& other);
		
		float Size() const;
		const Vector2 Normalized() const;
		
		static float GetDistance(const Vector2 &a, const Vector2 &b);
		static float Size(const Vector2 &vec);
		static const Vector2 Normalized(const Vector2 &vec);
	};
	
}
