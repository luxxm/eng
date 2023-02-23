#include <iostream>
#include "objects/objects.h"

int main() {
	Cube cube;

	for (Point i : cube.points)
		std::cout << i.vertex << std::endl;

	return 0;
}
