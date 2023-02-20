#include <iostream>
#include "components/linearA.h"

int main() {
	Vec4 vector(5, 2, 3, 1);

	vector += Vec4(2, 2, 2, 0);
	vector++;

	std::cout << vector << std::endl;

	return 0;
}
