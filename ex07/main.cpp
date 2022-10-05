#include <iostream>

bool sat(const std::string & formula);

int main() {
	std::cout << sat("AB&!") << std::endl;
	std::cout << sat("AB|!") << std::endl;
	std::cout << sat("AB|C&") << std::endl;
	std::cout << sat("AB|C|D|") << std::endl;
	std::cout << sat("AB&C&D&") << std::endl;
	std::cout << sat("AB&!C!|") << std::endl;
	std::cout << sat("AB|!C!&") << std::endl;
	std::cout << sat("ABCD&|&") << std::endl;
	
	std::cout << sat("AA!&") << std::endl;
	std::cout << sat("AA^") << std::endl;
	exit(0);
}
