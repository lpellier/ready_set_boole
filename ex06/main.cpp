#include "ex06.hpp"

int main() {
	std::cout << conjunction_normal_form("AB&!") << std::endl;
	std::cout << conjunction_normal_form("AB|!") << std::endl;
	std::cout << conjunction_normal_form("AB|C&") << std::endl;
	std::cout << conjunction_normal_form("AB|C|D|") << std::endl;
	std::cout << conjunction_normal_form("AB&C&D&") << std::endl;
	std::cout << conjunction_normal_form("AB&!C!|") << std::endl;
	std::cout << conjunction_normal_form("AB|!C!&") << std::endl;
	std::cout << conjunction_normal_form("ABCD&|&") << std::endl;
	// std::cout << conjunction_normal_form("AB>") << std::endl;
	// std::cout << conjunction_normal_form("AB=") << std::endl;
	// std::cout << conjunction_normal_form("AB|C&!") << std::endl;
	exit(0);
}
