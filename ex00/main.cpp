#include <iostream>

unsigned int adder(const unsigned int a, const unsigned int b);

int main() {
	std::cout << "Adder" << std::endl;
	std::cout << "3 + 4 = " << adder(3, 4) << " (" << 3 + 4 << ")" << std::endl;
	std::cout << "12 + 655887 = " << adder(12, 655887) << " (" << 12 + 655887 << ")" << std::endl;
	std::cout << "4758 + 587 = " << adder(4758, 587) << " (" << 4758 + 587 << ")" << std::endl;
	std::cout << "987 + 789 = " << adder(987, 789) << " (" << 987 + 789 << ")" << std::endl;

	exit(0);
}
