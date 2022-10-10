#include <string>
#include <algorithm>
#include <iostream>

unsigned int pow(const unsigned int n, const unsigned int i) {
	unsigned int j = 0;
	unsigned int result = 1;
	while (j < i) {
		result *= n;
		j += 1;
	}
	return result;
}

unsigned int gray_code(const unsigned int n) {
	std::string n_binary = std::string("");
	unsigned int n_nbr = n;

	if (!n_nbr)
		n_binary.push_back('0');
	while (n_nbr) {
		n_binary.push_back((n_nbr % 2 + 48));
		n_nbr /= 2;
	}
	std::reverse(n_binary.begin(), n_binary.end());
	unsigned int n_len = n_binary.length();

	std::string n_gray = std::string("");
	try {
		n_gray.push_back(n_binary.at(0));
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return 0;
	}

	unsigned int i = 0;
	std::string::iterator beg = n_binary.begin();
	while (beg != n_binary.end()) {
		if (i + 1 < n_len) {
			if (*beg == *(beg + 1))
				n_gray.push_back('0');
			else
				n_gray.push_back('1');
		}
		i++;
		beg++;
	}

	std::reverse(n_gray.begin(), n_gray.end());
	unsigned int result = 0;
	i = 0;
	beg = n_gray.begin();
	while (beg != n_gray.end()) {
		if (*beg == '1') {
			result += pow(2, i);
		}
		beg++;
		i++;
	}

	return result;
}
