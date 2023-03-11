#include "objects.h"
//Private functions
Mat4* gameObject::setTranslationMatrix() {
	for (int i = 0; i < 3; i++)
		this->translationMat[i][3] = this->position[i];

	return &this->translationMat;
}

Mat4* gameObject::setScaleMatrix() {
	this->scaleMat[0][0] = this->size.x;
	this->scaleMat[1][1] = this->size.y;
	this->scaleMat[2][2] = this->size.z;

	return &this->scaleMat;
}

//Public functions
Mat4* gameObject::calcTranslationMat() {
	this->objectMatrix = this->translationMat*this->scaleMat;

	return &this->objectMatrix;
}

Point gameObject::getTPoint(int id) {
	Point tPoint = this->points[id];
	tPoint.vertex = this->objectMatrix * this->points[id].vertex;
	return tPoint;
}

Vec4* gameObject::setPosition(float x, float y, float z) {
	this->position = Vec4(x, y, z, 1);
	this->setTranslationMatrix();
	this->calcTranslationMat();

	return &this->position;
}

Vec4* gameObject::setPosition(Vec4 pos) {
	this->position = pos;
	this->setTranslationMatrix();
	this->calcTranslationMat();

	return &this->position;
}

Vec4* gameObject::setScale(float x, float y, float z) {
	this->size = Vec4(x, y, z, 1);
	this->setScaleMatrix();
	this->calcTranslationMat();

	return &this->size;
}

Vec4* gameObject::setScale(Vec4 size) {
	this->size = size;
	this->setScaleMatrix();
	this->calcTranslationMat();

	return &this->size;
}

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
