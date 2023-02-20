#include "linearA.h"

Vec4::Vec4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vec4 Vec4::operator+(Vec4 a) {
	return Vec4(
			this->x + a.x,
			this->y + a.y,
			this->z + a.z,
			this->w + a.w
			);
}

Vec4 Vec4::operator+=(Vec4 a) {
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	this->w += a.w;

	return *this;
}

Vec4 Vec4::operator++(int) {
	this->x++;
	this->y++;
	this->z++;
	this->w++;

	return *this;
}

Vec4 Vec4::operator++() {
	Vec4 cpy = *this;

	this->x++;
	this->y++;
	this->z++;
	this->w++;

	return cpy;
}

Vec4 Vec4::operator-(Vec4 a) {
	return Vec4(
			this->x - a.x,
			this->y - a.y,
			this->z - a.z,
			this->w - a.w
			);
}

Vec4 Vec4::operator-=(Vec4 a) {
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	this->w -= a.w;

	return *this;
}

Vec4 Vec4::operator--(int) {
	this->x--;
	this->y--;
	this->z--;
	this->w--;

	return *this;
}

Vec4 Vec4::operator--() {
	Vec4 cpy = *this;

	this->x--;
	this->y--;
	this->z--;
	this->w--;

	return cpy;
}

float Vec4::operator*(Vec4 a) {
	return (
			this->x * a.x +
			this->y * a.y +
			this->z * a.z +
			this->w * a.w
			);
}

Vec4 Vec4::operator*(float a) {
	return Vec4(
			this->x * a,
			this->y * a,
			this->z * a,
			this->w * a
			);
}

Vec4 Vec4::operator*=(float a) {
	this->x *= a;
	this->y *= a;
	this->z *= a;
	this->w *= a;

	return *this;
}

float Vec4::operator[](int i) {
	switch (i) {
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		default:
			throw std::out_of_range("Number is out of range (range is from 0-3)\n");
			break;
	}
}
