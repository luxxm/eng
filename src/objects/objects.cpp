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

Mat4* gameObject::setRotationMatrix() {
	//yaw * pitch * roll
	Vec4 radRot = this->rotation;
	radRot.x /= RAD_U;
	radRot.y /= RAD_U;
	radRot.z /= RAD_U;

	//Pitch x
	Mat4 pitch = Mat4().makeIdentity();
	pitch[0][0] = cos(radRot.x);
	pitch[0][2] = -sin(radRot.x);
	pitch[2][0] = sin(radRot.x);
	pitch[2][2] = cos(radRot.x);

	//Yaw y
	Mat4 yaw = Mat4().makeIdentity();
	yaw[0][0] = cos(radRot.y);
	yaw[0][1] = sin(radRot.y);
	yaw[1][0] = -sin(radRot.y);
	yaw[1][1] = cos(radRot.y);

	//Roll z
	Mat4 roll = Mat4().makeIdentity();
	roll[1][1] = cos(radRot.z);
	roll[1][2] = sin(radRot.z);
	roll[2][1] = -sin(radRot.z);
	roll[2][2] = cos(radRot.z);

	this->rotationMat = (yaw*pitch)*roll;
	
return &this->rotationMat;
}

//Public functions
Mat4* gameObject::calcTranslationMat() {
	this->objectMatrix = this->translationMat*(this->rotationMat*this->scaleMat);

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

Vec4* gameObject::setRotation(float x, float y, float z) {
	this->rotation = Vec4(x, y, z, 1);
	this->setRotationMatrix();
	this->calcTranslationMat();

	return &this->rotation;
}

Vec4* gameObject::setRotation(Vec4 rot) {
	this->rotation = rot;
	this->setRotationMatrix();
	this->calcTranslationMat();

	return &this->rotation;
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
	this->setPosition(0, 0, 0);
	this->setScale(1, 1, 1);
	this->setRotation(0, 0, 0);

	this->calcTranslationMat();	

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
