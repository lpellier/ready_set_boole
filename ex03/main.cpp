#include <iostream>
#include <string>

bool eval_formula(const std::string & str);

int main() {
	std::cout << "Boolean Evaluation" << std::endl;
	std::cout << (eval_formula("10&") == true ? "true" : "false") << " (false)" << std::endl;
	std::cout << (eval_formula("10|") == true ? "true" : "false") << " (true)" << std::endl;
	std::cout << (eval_formula("11>") == true ? "true" : "false") << " (true)" << std::endl;
	std::cout << (eval_formula("10=") == true ? "true" : "false") << " (false)" << std::endl;
	std::cout << (eval_formula("1011||=") == true ? "true" : "false") << " (true)" << std::endl;

	std::cout << (eval_formula("101|&") == true ? "true" : "false") << " (true)" << std::endl;
	std::cout << (eval_formula("10|1&") == true ? "true" : "false") << " (true)" << std::endl;

	std::cout << (eval_formula("10&&") == true ? "true" : "false") << " (error)" << std::endl;
	std::cout << (eval_formula("1&") == true ? "true" : "false") << " (error)" << std::endl;

	std::cout << (eval_formula("00&1|") == true ? "true" : "false") << " (true)" << std::endl;


	exit(0);
}
