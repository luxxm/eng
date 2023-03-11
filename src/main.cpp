#include <iostream>
#include "objects/objects.h"

int main() {
	Cube cube;

	cube.setPosition(5, 11, 9.2);

	for (int i = 0; i < cube.points.size(); i++)
		std::cout << cube.getTPoint(i).vertex << std::endl;

	return 0;
}
