#include <iostream>
#include "objects/objects.h"

int main() {
	Cube cube;

	cube.setPosition(2, 2, 2);
	cube.setScale(1, 3, 3);
	cube.setRotation(0, 90, 0);

	for (int i = 0; i < cube.points.size(); i++) {
		std::cout << "(";
		for (int j = 0; j < 3; j++)
			std::cout << cube.getTPoint(i).vertex[j] << ((j<2)?",":"");
		std::cout << ")" << std::endl;
	}

	return 0;
}
