#pragma once

#include "../components/linearA.h"
#include <vector>

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
public:
	std::vector<Point> points;
	Mat4 objectMatrix = Mat4().makeIdentity();
	Vec4 position;
	Vec4 size;
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
