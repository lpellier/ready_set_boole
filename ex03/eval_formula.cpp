#include <string>
#include <vector>
#include <stack>
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

class Node {
public:
	char	value;
	bool	negation;
	Node *	left;
	Node *	right;

	Node(char value) {
		this->value = value;
		this->negation = false;
		this->left = NULL;
		this->right = NULL;
	}
};

void free_nodes(Node * cur) {
	if (cur->left)
		free_nodes(cur->left);
	if (cur->right)
		free_nodes(cur->right);
	delete cur;
}

bool resolveTree(Node * cur) {
	bool result = cur->value - 48 != 0;
	if (cur->value == '&') {
		result = _and(resolveTree(cur->left), resolveTree(cur->right));
	}
	else if (cur->value == '|') {
		result = _or(resolveTree(cur->left), resolveTree(cur->right));
	}
	else if (cur->value == '^') {
		result = _xor(resolveTree(cur->left), resolveTree(cur->right));
	}
	else if (cur->value == '>') {
		result = _material_condition(resolveTree(cur->left), resolveTree(cur->right));
	}
	else if (cur->value == '=') {
		result = _logical_equivalence(resolveTree(cur->left), resolveTree(cur->right));
	}

	if (cur->negation) {
		return !result;
	}
	else {
		return result;
	}
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

	std::stack<Node *> node_stack;

	for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
		if (*it == '0' || *it == '1')
			node_stack.push(new Node(*it));
		else if (*it != '!' && node_stack.size() >= 2) {
			Node * op_node = new Node(*it);
			op_node->left = node_stack.top();
			node_stack.pop();
			op_node->right = node_stack.top();
			node_stack.pop();
			node_stack.push(op_node);
		}
		else if (*it == '!') {
			node_stack.top()->negation = true;
		}
		else {
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}

	bool res = resolveTree(node_stack.top());

	free_nodes(node_stack.top());
	while (node_stack.size() > 0) {
		node_stack.pop();
	}

	return res;
}	
