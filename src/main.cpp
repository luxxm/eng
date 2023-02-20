#include <iostream>
#include "components/linearA.h"

int main() {
	Vec4 vector1(5.23, 3.41, 12.0, 4.44);
	Mat4 matrix1;
	matrix1.makeIdentity();

	matrix1[0][3] = 1;
	
	Vec4 result = matrix1*vector1;

	for (int i = 0; i < 4; i++) {
		std::cout << "|";
		for (int j = 0; j < 4; j++)
			if (j < 3)
				std::cout << matrix1[i][j] << " ";
			else 
				std::cout << matrix1[i][j];
		std::cout << "|" << std::endl;
	}

	std::cout << result << std::endl;
}
