#pragma once

#include <ostream>
#include <stdexcept>
#include <vector>

struct Vec4 {
	float x, y, z, w ;

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

	float& operator[] (int i);

	friend auto operator<<(std::ostream& os, Vec4 const& a) -> std::ostream& {
		return os << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w << ")";
	}

	Vec4 invert();
};

typedef Vec4 Vertex;

class Mat4 {
	std::vector<std::vector<float>> matrix;
public:
	Mat4();
	Mat4(Vec4 a[4]);
	Mat4(std::vector<Vec4> a);

	Vec4 operator*(Vec4 a);
	Mat4 operator*(Mat4 a);

	std::vector<float>& operator[](int i);

	Mat4 makeIdentity();
};
