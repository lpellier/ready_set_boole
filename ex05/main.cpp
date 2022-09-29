#include <iostream>
#include <string>

std::string	negation_normal_form(const std::string & formula);

int main() {
	negation_normal_form("AB|CCC&&&");
	exit(0);
}
