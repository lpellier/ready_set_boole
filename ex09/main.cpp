#include <iostream>
#include <vector>

std::vector<int>	eval_set(const std::string & formula, std::vector<std::vector<int> > sets);

void printVec(const std::vector<int> & vec) {
	std::vector<int>::const_iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> set_one;
	set_one.push_back(0);
	set_one.push_back(1);
	set_one.push_back(2);
	std::vector<int> set_two;
	set_two.push_back(0);
	set_two.push_back(3);
	set_two.push_back(4);
	std::vector<int> set_three;
	set_three.push_back(3);
	set_three.push_back(4);
	set_three.push_back(5);

	std::vector<std::vector<int> > sets;
	sets.push_back(set_one);
	sets.push_back(set_two);
	printVec(eval_set("AB&", sets));
	sets.clear();
	sets.push_back(set_one);
	sets.push_back(set_three);
	printVec(eval_set("AB|", sets));
	sets.clear();
	sets.push_back(set_one);
	printVec(eval_set("A!", sets));
	sets.clear();
	exit(0);
}