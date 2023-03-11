#pragma once

#include "../components/linearA.h"
#include <vector>
#include <cmath>

struct Point {
	Vertex vertex;
	int number = 0;

	Point() {};
	Point(Vertex vertex, int number) {
		this->vertex = vertex;
		this->number = number;
	}
};

class gameObject {
private:
	Mat4 translationMat = Mat4().makeIdentity();
	Mat4 scaleMat = Mat4().makeIdentity();
	Mat4 rotationMat = Mat4().makeIdentity();

	Mat4* setTranslationMatrix();
	Mat4* setScaleMatrix();
	Mat4* setRotationMatrix();
public:
	std::vector<Point> points;
	Mat4 objectMatrix = Mat4().makeIdentity();

	Vec4 position;
	Vec4 size;
	Vec4 rotation;

	Mat4* calcTranslationMat();

	Point getTPoint(int id);

	Vec4* setPosition(float x, float y, float z);
	Vec4* setPosition(Vec4 pos);
	Vec4* setScale(float x, float y, float z);
	Vec4* setScale(Vec4 size);
	Vec4* setRotation(float x, float y, float z);
	Vec4* setRotation(Vec4 rot);
};

class Cube : public gameObject {
private:
	void setPoints();
public:
	Cube();
	Cube(Vec4 position, Vec4 size = Vec4(1, 1, 1, 1));
	Cube(std::vector<Vertex> vertices);
	Cube(Vertex vertices[8]);
	Cube(std::vector<Point> points);
};
