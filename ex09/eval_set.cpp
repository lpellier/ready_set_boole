#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
	char	value;
	std::vector<int>	set;
	unsigned int	negation;
	Node *	left;
	Node *	right;

	Node(char value) {
		this->value = value;
		this->negation = 0;
		this->left = NULL;
		this->right = NULL;
	}

	Node(const Node * src) {
		this->value = src->value;
		this->set = std::vector<int>(src->set);
		this->negation = src->negation;
		this->left = src->left ? new Node(src->left) : NULL;
		this->right = src->right ? new Node(src->right) : NULL;
	}
};

void free_nodes(Node * cur) {
	if (!cur)
		return ;
	if (cur->left)
		free_nodes(cur->left);
	if (cur->right)
		free_nodes(cur->right);
	delete cur;
	cur = NULL;
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
		Node * left_tmp = new Node(cur->left);
		Node * right_tmp = new Node(cur->right);
		
		cur->value = '&';

		free_nodes(cur->left);
		cur->left = new Node('>');
		cur->left->left = new Node(right_tmp);
		cur->left->right = new Node(left_tmp);
		
		free_nodes(cur->right);
		cur->right = new Node('>');
		cur->right->left = new Node(left_tmp);
		cur->right->right = new Node(right_tmp);
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


bool				_in(const std::vector<int> & set, int nbr) {
	for (unsigned int i = 0; i < set.size(); i++) {
		if (set[i] == nbr)
			return true;
	}
	return false;
}

std::vector<int>	_and(const std::vector<int> & a, const std::vector<int> & b) {
	std::vector<int> result;

	for (unsigned int i = 0; i < a.size(); i++) {
		if (_in(b, a[i]) && !_in(result, a[i]))
			result.push_back(a[i]);
	}

	return result;
}

std::vector<int>	_or(const std::vector<int> & a, const std::vector<int> & b) {
	std::vector<int> result;

	for (unsigned int i = 0; i < a.size(); i++) {
		if (!_in(result, a[i]))
			result.push_back(a[i]);
	}
	
	for (unsigned int i = 0; i < b.size(); i++) {
		if (!_in(result, b[i]))
			result.push_back(b[i]);
	}

	return result;
}

std::vector<int> evaluateTree(Node * cur) {
	std::vector<int> result = cur->set;
	if (cur->value == '&') {
		result = _and(evaluateTree(cur->left), evaluateTree(cur->right));
	}
	else if (cur->value == '|') {
		result = _or(evaluateTree(cur->left), evaluateTree(cur->right));
	}

	if (cur->negation) {
		result.clear();
	}
	return result;
}

std::vector<int>	eval_set(const std::string & formula, std::vector<std::vector<int> > sets) {
	std::string vars = std::string("");
	std::string operators = std::string("");
	unsigned int operator_size = 0;

	std::vector<int> result;

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
			return result;
		}
	}
	if (vars.size() == 0 || operator_size != vars.size() - 1) {
		std::cout << "Error : not the right amount of operators or operands." << std::endl;
		return result;
	}
	
	std::stack<Node *> node_stack;

	for (std::string::const_iterator it = formula.begin(); it != formula.end(); it++) {
		if (*it >= 'A' && *it <= 'Z') {
			node_stack.push(new Node(*it));
			unsigned int index = 0;
			for (; index < vars.size(); index++)
				if (*it == vars[index])
					break;
			node_stack.top()->set = std::vector<int>(sets[index]);
		}
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
			return result;
		}
	}

	rewriteTree(node_stack.top());

	result = evaluateTree(node_stack.top());
	free_nodes(node_stack.top());
	return result;
}