#include <ostream>
#include <stdexcept>

#pragma once

struct Vec4 {
	float x, y, z, w = 0.0f;

	Vec4();
	Vec4(float x, float y, float z, float w);

	//Vector adding
	Vec4 operator+(Vec4 a);
	Vec4 operator+=(Vec4 a);
	Vec4 operator++(int);
	Vec4 operator++();
	//Vector subtracting
	Vec4 operator-(Vec4 a);	
	Vec4 operator-=(Vec4 a);
	Vec4 operator--(int);
	Vec4 operator--();
	//Vector multiplying
	float operator*(Vec4 a);
	Vec4 operator*(float a);
	Vec4 operator*=(float a);

	float operator[] (int i);

	friend auto operator<<(std::ostream& os, Vec4 const& a) -> std::ostream& {
		return os << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << ")";
	}
};
