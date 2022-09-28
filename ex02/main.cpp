#include <iostream>

unsigned int gray_code(const unsigned int n);

int main() {
	// gray code
	std::cout << "Gray Code" << std::endl;
	std::cout << "0 -> " << gray_code(0) << " (0)" << std::endl;
	std::cout << "1 -> " << gray_code(1) << " (1)" << std::endl;
	std::cout << "2 -> " << gray_code(2) << " (3)" << std::endl;
	std::cout << "3 -> " << gray_code(3) << " (2)" << std::endl;
	std::cout << "4 -> " << gray_code(4) << " (6)" << std::endl;
	std::cout << "5 -> " << gray_code(5) << " (7)" << std::endl;
	std::cout << "6 -> " << gray_code(6) << " (5)" << std::endl;
	std::cout << "7 -> " << gray_code(7) << " (4)" << std::endl;
	std::cout << "8 -> " << gray_code(8) << " (12)" << std::endl;
	
	exit(0);
}
