#include "ex06.hpp"
// ? must recognize patterns : 
// ? material condition, equivalence, elimination of double negation, de morgan's law, distributivity

// ? first apply distributivity
// ? then look for morgan's law, equivalence and material condition and translate
// ? then look for double negations and eliminate them

void free_nodes(Node * cur) {
	if (cur->left)
		free_nodes(cur->left);
	if (cur->right)
		free_nodes(cur->right);
	delete cur;
}

void rewriteTree(Node * cur) {
	if (cur->negation % 2 == 0)
		cur->negation = 0;
	else
		cur->negation = 1;

	if (cur->left && cur->right && cur->value == '>') {
		cur->value = '|';
		cur->right->negation += 1; 
		if (cur->negation % 2 == 0)
			cur->negation = 0;
		else
			cur->negation = 1;
	}
	else if (cur->left && cur->right && cur->value == '=') {
		Node * left_tmp = new Node(*cur->left);
		Node * right_tmp = new Node(*cur->right);
		
		cur->value = '&';

		cur->left = new Node('>');
		cur->left->left = new Node(*right_tmp);
		cur->left->right = new Node(*left_tmp);
		
		cur->right = new Node('>');
		cur->right->left = new Node(*left_tmp);
		cur->right->right = new Node(*right_tmp);
		free_nodes(left_tmp);
		free_nodes(right_tmp);
	}
	else if (cur->left && cur->right && cur->value == '|' && cur->negation == 1) {
		cur->value = '&';
		cur->negation = 0;
		cur->left->negation += 1;
		cur->right->negation += 1;
	}
	else if (cur->left && cur->right && cur->value == '&' && cur->negation == 1) {
		cur->value = '|';
		cur->negation = 0;
		cur->left->negation += 1;
		cur->right->negation += 1;
	}

	if (cur->left)
		rewriteTree(cur->left);
	if (cur->right)
		rewriteTree(cur->right);
}

std::string readTree(Node * cur) {
	std::string ret = "";
	if (cur->right)
		ret += readTree(cur->right);
	if (cur->left)
		ret += readTree(cur->left);
	ret += cur->value;
	if (cur->negation == 1) {
		ret += '!';
	}
	return ret;
}

std::string	negation_normal_form(const std::string & formula) {
	std::string vars = std::string("");
	std::string operators = std::string("");
	unsigned int operator_size = 0;

	// ? error handling
	for (std::string::const_iterator beg = formula.begin(); beg != formula.end(); beg++) {
		if (*beg >= 'A' && *beg <= 'Z')
			vars.push_back(*beg);
		else if (*beg == '!' || *beg == '&' || *beg == '|' || *beg == '^' || *beg == '>' || *beg == '=') {
			operators.push_back(*beg);
			if (*beg != '!')
				operator_size += 1;
		}
		else {
			std::cout << "Error : " << *beg << " is not a supported operator.";
			return "none";
		}
	}
	if (vars.size() == 0 || operator_size != vars.size() - 1) {
		std::cout << "Error : not the right amount of operators or operands." << std::endl;
		return "none";
	}
	
	std::stack<Node *> node_stack;

	for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
		if (*it >= 'A' && *it <= 'Z')
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
			node_stack.top()->negation += 1;
		}
		else {
			std::cout << "Error" << std::endl;
			return ("none");
		}
	}

	// ? apply rewrite rules
	rewriteTree(node_stack.top());

	// ? read the tree -> result
	std::string result = readTree(node_stack.top());

	free_nodes(node_stack.top());
	while (node_stack.size() > 0) {
		node_stack.pop();
	}

	return result;
}
