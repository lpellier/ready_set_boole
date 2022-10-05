#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool eval_formula(const std::string & formula);

bool g_satisfiable;

class Node {
public:
	bool * value;

	Node * left;
	Node * right;

	Node() {
		this->value = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	Node(bool value) {
		this->value = new bool(value);
		this->left = NULL;
		this->right = NULL;
	}

	~Node() {
		delete this->value;
	}

	void add_layer() {
		if (!this->left && !this->right) {
			this->left = new Node(true);
			this->right = new Node(false);
		}
		else {
			this->left->add_layer();
			this->right->add_layer();
		}
	}

	void clear() {
		if (this->left) {
			this->left->clear();
			delete this->left;
		}
		if (this->right) {
			this->right->clear();
			delete this->right;
		}
	}
};

void replaceEvaluateFormula(std::vector<bool> path, const std::string & vars, std::string formula) {
	unsigned int i = 0;
	for (std::string::const_iterator beg = vars.begin(); beg != vars.end(); beg++) {
		std::replace(formula.begin(), formula.end(), *beg, (path[i] == 1 ? '1' : '0'));
		i++;
	}
	if (eval_formula(formula))
		g_satisfiable = true;
}

void getPaths(Node * node, std::vector<bool> path, const std::string & vars, const std::string & formula) {
	if (!node || g_satisfiable)
		return ;
	if (node->value)
		path.push_back(*(node->value));

	if (!node->left && !node->right) {
		replaceEvaluateFormula(path, vars, formula);
	}
	else {
		getPaths(node->right, path, vars, formula);
		getPaths(node->left, path, vars, formula);
	}
}

bool sat(const std::string & formula) {
	std::string vars = std::string("");
	unsigned int operator_size = 0;
	unsigned int operand_size = 0;

	for (std::string::const_iterator beg = formula.begin(); beg != formula.end(); beg++) {
		if (*beg >= 'A' && *beg <= 'Z') {
			if (vars.find(*beg) == vars.npos)
				vars.push_back(*beg);
			operand_size += 1;
		}
		else if (*beg == '&' || *beg == '|' || *beg == '^' || *beg == '>' || *beg == '=')
			operator_size += 1;
		else if (*beg != '!') {
			std::cout << "Error : " << *beg << " is not a supported operator.";
			return false;
		}
	}
	if (operand_size == 0 || operator_size != operand_size - 1) {
		std::cout << "Error : not the right amount of operators or operands." << std::endl;
		return false;
	}

	Node * tree = new Node();
	for (unsigned int i = 0; i < vars.size(); i++) {
		tree->add_layer();
	}
	
	std::vector<bool> path = std::vector<bool>();

	g_satisfiable = false;
	getPaths(tree, path, vars, formula);

	tree->clear();
	delete tree;
	return g_satisfiable;
}

