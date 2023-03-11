#include <iostream>
#include "objects/objects.h"

int main() {
	Cube cube;

	cube.setPosition(2, 2, 2);
	cube.setScale(1, 3, 3);

	for (int i = 0; i < 4; i++) {
		std::cout << "|";
		for (int j = 0; j < 4; j++)
			std::cout << " 	" << cube.objectMatrix[i][j];
		std::cout << " 	|";
		std::cout << std::endl;
	}

	for (int i = 0; i < cube.points.size(); i++)
		std::cout << cube.getTPoint(i).vertex << std::endl;

	return 0;
}
