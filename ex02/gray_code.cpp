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

// pub fn gray_code(n: u32) -> u32 {
// 	let mut n_binary : String = String::from("");
// 	let mut n_nbr = n;

// 	if n_nbr == 0 {
// 		n_binary.push('0');
// 	}
// 	while n_nbr > 0 {
// 		n_binary.push(char::from_u32(n_nbr % 2 + 48).unwrap());
// 		n_nbr /= 2;
// 	}
// 	n_binary = n_binary.chars().rev().collect();
	
// 	let n_len = n_binary.chars().count();

// 	let mut n_gray : String = String::from("");


// 	n_gray.push(n_binary.chars().nth(0).unwrap());

// 	for (i, c) in n_binary.chars().enumerate() {
// 		if i + 1 < n_len {
// 			if c == n_binary.chars().nth(i + 1).unwrap() {
// 				n_gray.push('0');
// 			}
// 			else {
// 				n_gray.push('1');
// 			}
// 		}
// 	}
	
// 	n_gray = n_gray.chars().rev().collect();
	
// 	let mut result = 0;
// 	for (i, c) in n_gray.chars().enumerate() {
// 		if c == '1' {
// 			result += pow(2, i);
// 		}
// 	}

// 	return result;
// }
