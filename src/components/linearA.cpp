#include "linearA.h"

Vec4::Vec4() {
	this->x = this->y = this->z = this->w = 0.0f;
}

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

float& Vec4::operator[](int i) {
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

Vec4 Vec4::invert() {
	return Vec4(this->x * -1, this->y * -1, this->z * -1, this->w * -1);
}

//Matrices
Mat4::Mat4() {
	for (int i = 0; i < 4; i++) {
		std::vector<float> line;
		for (int j = 0; j < 4; j++)
			line.push_back(0);

		this->matrix.push_back(line);
	}
}

Mat4::Mat4(Vec4 a[4]) {
	for (int i = 0; i < 4; i++) {
		std::vector<float> line;
		for (int j = 0; j < 4; j++)
			line.push_back(a[i][j]);

		this->matrix.push_back(line);
	}
}

Mat4::Mat4(std::vector<Vec4> a) {
	for (int i = 0; i < 4; i++) {
		std::vector<float> line;
		for (int j = 0; j < 4; j++)
			line.push_back(a[i][j]);

		this->matrix.push_back(line);
	}
}

Vec4 Mat4::operator*(Vec4 a) {
	Vec4 result(0, 0, 0, 0);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			result[i] += this->matrix[i][j] * a[j];

	return result;
}

Mat4 Mat4::operator*(Mat4 a) {
	Mat4 result;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				result[i][j] += this->matrix[i][k] * a[k][j];

	return result;
}

std::vector<float>& Mat4::operator[](int i) {
	return this->matrix[i];
}

Mat4 Mat4::makeIdentity() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (j == i)
				this->matrix[i][j] = 1;
			else
				this->matrix[i][j] = 0;

	return *this;
}
