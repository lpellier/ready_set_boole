#include <iostream>

unsigned int multiplier(unsigned int a, unsigned int b);

int main() {
	std::cout << "Multiplier" << std::endl;
	std::cout << "25 * 12 = " << multiplier(25, 12) << " (" << 25 * 12 << ")" << std::endl;
	std::cout << "666 * 25 = " << multiplier(666, 25) << " (" << 666 * 25 << ")" << std::endl;
	std::cout << "789 * 987 = " << multiplier(789, 987) << " (" << 789 * 987 << ")" << std::endl;
	std::cout << "2 * 6 = " << multiplier(2, 6) << " (" << 2 * 6 << ")" << std::endl;

	exit(0);
}
