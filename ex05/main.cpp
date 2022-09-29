#include <iostream>
#include <string>

std::string	negation_normal_form(const std::string & formula);

int main() {
	std::cout << negation_normal_form("BC|A&D|") << std::endl;
	exit(0);
}
