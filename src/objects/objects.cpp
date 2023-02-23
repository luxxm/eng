#include "objects.h"

void Cube::setPoints() {
	int i = 0;
	Vertex nextVertex(0, 0, 0, 0);

	//-1, -1, -1
	nextVertex = position - this->size;
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//1, -1, -1
	nextVertex = position - Vertex(this->size[0] * -1, this->size[1], this->size[2], this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//-1, -1, 1
	nextVertex = position - Vertex(this->size[0], this->size[1], this->size[2] * -1, this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//1, -1, 1
	nextVertex = position - Vertex(this->size[0] * -1, this->size[1], this->size[2] * -1, this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//1, 1, 1
	nextVertex = position + this->size;
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//-1, 1, 1
	nextVertex = position + Vertex(this->size[0] * -1, this->size[1], this->size[2], this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//1, 1, -1
	nextVertex = position + Vertex(this->size[0], this->size[1], this->size[2] * -1, this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
	//-1, 1, -1
	nextVertex = position + Vertex(this->size[0] * -1, this->size[1], this->size[2] * -1, this->size[3]);
	nextVertex[3] = 1;
	this->points.push_back(Point(nextVertex, i++));
}

Cube::Cube() {
	this->position.x = this->position.y = this->position.z = this->position.w = 0;
	this->size.x = this->size.y = this->size.z = this->size.w = 1;	

	this->setPoints();
}

Cube::Cube(Vec4 position, Vec4 size) {
	this->position = position;
	this->size = size;

	this->setPoints();
}

Cube::Cube(std::vector<Vertex> vertices) {
	for (int i = 0; i < vertices.size(); i++)
		this->points.push_back(Point(vertices[i], i));
}

Cube::Cube(Vertex vertices[8]) {
	for (int i = 0; i < 8; i++)
		this->points.push_back(Point(vertices[i], i));
}

Cube::Cube(std::vector<Point> points) {
	for (Point i : points)
		this->points.push_back(i);
}
