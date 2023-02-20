#include <iostream>
#include "components/linearA.h"

int main() {
	Mat4 m1;
	Mat4 m2;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;  j++) {
			m1[i][j] = (j+1)/(i+1)*2.0+3;
			m2[i][j] = (i+1)*(j+1)/2 + 4.1;
		}

	Mat4 result = m1*m2;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << m1[i][j] << ", ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << m2[i][j] << ", ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			std::cout << result[i][j] << ", ";
		std::cout << std::endl;
	}
}
