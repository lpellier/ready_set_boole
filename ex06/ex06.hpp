#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Node {
public:
	char	value;
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
		this->negation = src->negation;
		this->left = src->left ? new Node(src->left) : NULL;
		this->right = src->right ? new Node(src->right) : NULL;
	}
};

void free_nodes(Node * cur);
std::string readTree(Node * cur);
std::string	conjunction_normal_form(const std::string & formula);
std::string	negation_normal_form(const std::string & formula);