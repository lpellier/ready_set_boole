#include <iostream>
#include <string>

std::string	negation_normal_form(const std::string & formula);

int main() {
	std::cout << negation_normal_form("AB&!") << std::endl;
	std::cout << negation_normal_form("AB|!") << std::endl;
	std::cout << negation_normal_form("AB>") << std::endl;
	std::cout << negation_normal_form("AB=") << std::endl;
	std::cout << negation_normal_form("AB|C&!") << std::endl;
	exit(0);
}
