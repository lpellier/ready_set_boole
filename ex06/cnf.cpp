#include "ex06.hpp"

// ? must recognize patterns : 
// ? material condition, equivalence, elimination of double negation, de morgan's law, distributivity

// ? first apply distributivity
// ? then look for morgan's law, equivalence and material condition and translate
// ? then look for double negations and eliminate them



void rewriteTree2(Node * cur) {
	if (cur->negation % 2 == 0)
		cur->negation = 0;
	else
		cur->negation = 1;

	// distrbutivity
	if (cur->left && cur->right && cur->value == '|' && cur->left->value == '&' && \
		cur->left->left && cur->left->right && !cur->right->left && !cur->right->right) {
		Node * tmp_right = new Node(cur->right);
		Node * tmp_left_left = new Node(cur->left->left);
		Node * tmp_left_right = new Node(cur->left->right);

		cur->value = '&';
		cur->left->value = '|';
		cur->right->value = '|';

		// ? may need to change left/right
		free_nodes(cur->right->right);
		cur->right->right = new Node(tmp_right);
		free_nodes(cur->right->left); 
		cur->right->left = new Node(tmp_left_right);  
		free_nodes(cur->left->right);
		cur->left->right = new Node(tmp_right);
		free_nodes(cur->left->left);
		cur->left->left = new Node(tmp_left_left);
	
		free_nodes(tmp_right);
		free_nodes(tmp_left_left);
		free_nodes(tmp_left_right);
	}
	else if (cur->left && cur->right && cur->value == '|' && cur->right->value == '&' && \
		cur->right->left && cur->right->right && !cur->left->left && !cur->left->right) {
		Node * tmp_left = new Node(cur->left);
		Node * tmp_right_left = new Node(cur->right->left);
		Node * tmp_right_right = new Node(cur->right->right);

		cur->value = '&';
		cur->left->value = '|';
		cur->right->value = '|';

		// ? may need to change left/right
		free_nodes(cur->left->right);
		cur->left->right = new Node(tmp_left); 
		free_nodes(cur->left->left);
		cur->left->left = new Node(tmp_right_right);  
		free_nodes(cur->right->right);
		cur->right->right = new Node(tmp_left);
		free_nodes(cur->right->left);
		cur->right->left = new Node(tmp_right_left);
		free_nodes(tmp_left);
		free_nodes(tmp_right_left);
		free_nodes(tmp_right_right);
	}


	if (cur->left)
		rewriteTree2(cur->left);
	if (cur->right)
		rewriteTree2(cur->right);
}

bool operatorsAndOnly(const std::string result) {
	bool only_and = true;
	for (std::string::const_iterator ite = result.begin(); ite != result.end(); ite++) {
		if (*ite == '|')
			only_and = false;
	}
	return only_and;
}

bool operatorsOrOnly(const std::string result) {
	bool only_or = true;
	for (std::string::const_iterator ite = result.begin(); ite != result.end(); ite++) {
		if (*ite == '&')
			only_or = false;
	}
	return only_or;
}

void moveOperatorsBack(std::string & res) {
	std::string operators = std::string("");
	std::string operands = std::string("");
	for (std::string::const_iterator ite = res.begin(); ite != res.end(); ite++) {
		if (*ite == '|' || *ite == '&')
			operators.push_back(*ite);
		else
			operands.push_back(*ite);
	}
	res = operands + operators;
}

std::string	conjunction_normal_form(const std::string & formula) {
	std::string res = negation_normal_form(formula);
	if (res == "none")
		return "none";
	
	std::stack<Node *> node_stack;

	for (std::string::const_iterator it = res.begin(); it != res.end(); it++) {
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
			return("none");
		}
	}

	// ? apply rewrite rules
	rewriteTree2(node_stack.top());

	// ? read the tree -> result
	std::string result = readTree(node_stack.top());

	// if every operator is ! or &
	if (operatorsAndOnly(result) || operatorsOrOnly(result)) {
		// -> move them to the top of the tree
		moveOperatorsBack(result);
	}

	free_nodes(node_stack.top());
	// while (node_stack.size() > 0) {
	// 	node_stack.pop();
	// }

	return result;
}
