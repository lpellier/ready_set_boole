#include <iostream>
#include <vector>

std::vector<std::vector<int> >	powerset(const std::vector<int> & set);

void printVec(const std::vector<std::vector<int> > & set) {
	std::cout << "set :" << std::endl;
	for (std::vector<std::vector<int> >::const_iterator it = set.begin(); it != set.end(); it++) {
		for (std::vector<int>::const_iterator ite = (*it).begin(); ite != (*it).end(); ite++) {
			std::cout << *ite << " ";
		}
		if ((*it).size() == 0)
			std::cout << "empty";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> set;
	set.push_back(0);
	set.push_back(1);
	set.push_back(2);
	
	// {
		// {}
		// {0, 1, 2}
		// {0}
		// {1}
		// {2}
		// {0, 1}
		// {0, 2}
		// {1, 2}
	// }

	std::vector<std::vector<int> > result;
	result = powerset(set);
	printVec(result);
	exit(0);
}