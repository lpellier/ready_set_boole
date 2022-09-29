#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// boolean algebra
// 0     -> false
// 1     -> true
// x !   -> negation of x
// x y & -> x and y
// x y | -> x or y
// x y ^ -> (x and (negation of y)) or ((negation of x) and y)
// x y > -> (negation of x) or y
// x y = -> (x and y) or ((negation of x) and (negation of y))

bool _negation(const bool x) {
	return !x;
}

bool _and(const bool x, const bool y) {
	return x && y;
}

bool _or(const bool x, const bool y) {
	return x || y;
}

bool _xor(const bool x, const bool y) {
	return _or(_and(x, _negation(y)), _and(_negation(x), y));
}

bool _material_condition(const bool x, const bool y) {
	return _or(_negation(x), y);
}

bool _logical_equivalence(const bool x, const bool y) {
	return _or(_and(x, y), _and(_negation(x), _negation(y)));
}

bool eval_formula(const std::string & formula) {
	std::vector<bool> result = std::vector<bool>();
	std::string operators = std::string("");
	unsigned int op_size = 0;

	for (std::string::const_iterator beg = formula.begin(); beg != formula.end(); beg++) {
		if (*beg == '0' || *beg == '1')
			result.push_back(*beg - 48);
		else if (*beg == '!' || *beg == '&' || *beg == '|' || *beg == '^' || *beg == '>' || *beg == '=') {
			operators.push_back(*beg);
			if (*beg != '!')
				op_size += 1;
		}
		else {
			std::cout << "Error : " << *beg << " is not a supported operator." << std::endl;
			return false;
		}
	}

	if (result.size() == 0 || op_size != result.size() - 1) {
		std::cout << "Error : not the right amount of operators or operands." << std::endl;
		return false;
	}

	for (std::string::iterator beg = operators.begin(); beg != operators.end(); beg++) {
		if (result.size() == 1)
			break;
		if (*beg == '!')
			result[0] = _negation(result[0]);
		else if (*beg == '&') {
			result[0] = _and(result[0], result[1]);
			result.erase(result.begin() + 1);
		}
		else if (*beg == '|') {
			result[0] = _or(result[0], result[1]);
			result.erase(result.begin() + 1);
		}
		else if (*beg == '^') {
			result[0] = _xor(result[0], result[1]);
			result.erase(result.begin() + 1);
		}
		else if (*beg == '>') {
			result[0] = _material_condition(result[0], result[1]);
			result.erase(result.begin() + 1);
		}
		else if (*beg == '=') {
			result[0] = _logical_equivalence(result[0], result[1]);
			result.erase(result.begin() + 1);
		}
	}

	return result[0];
}	
