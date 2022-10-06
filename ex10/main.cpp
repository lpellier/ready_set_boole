#include <string>
#include <iostream>

double	map(unsigned short x, unsigned short y);

int main() {
	std::cout << map(25, 30) << std::endl;
	std::cout << map(22254, 30845) << std::endl;
	std::cout << map(0, 0) << std::endl;
	std::cout << map(65535, 65535) << std::endl;


	exit(0);
}
