#include <iostream>
#include <string>

// ? must recognize patterns : 
// ? material condition, equivalence, elimination of double negation, de morgan's law, distributivity

// ? first apply distributivity
// ? then look for morgan's law, equivalence and material condition and translate
// ? then look for double negations and eliminate them

std::string addDistributivityAnd(char v1, char v2, char v3) {
	std::string add = std::string("");
	add += v3;
	add += v1;
	add += "&";
	add += v3;
	add += v2;
	add += "&";
	add += "|";
	return add;
}

std::string addDistributivityOr(char v1, char v2, char v3) {
	std::string add = std::string("");
	add += v3;
	add += v1;
	add += "|";
	add += v3;
	add += v2;
	add += "|";
	add += "&";
	return add;
}

std::string addMorganAnd(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += "!";
	add += v2;
	add += "!";
	add += "&";
	return add;
}

std::string addMorganOr(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += "!";
	add += v2;
	add += "!";
	add += "|";
	return add;
}

std::string addEquivalence(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += v2;
	add += "&";
	add += v1;
	add += "!";
	add += v2;
	add += "!";
	add += "&";
	add += "|";
	return add;
}

std::string addMaterialCondition(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += "!";
	add += v2;
	add += "|";
	return add;
}

std::string addInverseAnd(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += "!";
	add += v2;
	add += "!";
	add += "&";
	return add;
}

std::string addInverseOr(char v1, char v2) {
	std::string add = std::string("");
	add += v1;
	add += "!";
	add += v2;
	add += "!";
	add += "|";
	return add;
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
	
	std::string rf = formula;
	unsigned int found = 0;
	vars.clear();
	operators.clear();

	for (int i = 0; rf[i]; i++) {
		if (rf[i] >= 'A' && rf[i] <= 'Z') {
			vars.push_back(rf[i]);
		}
		else if (rf[i] == '!' || rf[i] == '&' || rf[i] == '|' || rf[i] == '^' || rf[i] == '>' || rf[i] == '=') {
			operators.push_back(rf[i]);
		}

		// ? distributivity 
		// BC|A& -> AB&AC&|
		// BCA|&
		if (vars.size() == 3 && operators.size() == 2 && operators[0] == '|' && operators[1] == '&') {
			rf.erase(0, 5);
			rf.insert(0, addDistributivityAnd(vars[0], vars[1], vars[2]));
			found = 6;
		}
		// BC&A| -> AB|AC|&
		// BCA&|
		else if (vars.size() == 3 && operators.size() == 2 && operators[0] == '&' && operators[1] == '|') {
			rf.erase(0, 5);
			rf.insert(0, addDistributivityOr(vars[0], vars[1], vars[2]));
			found = 6;
		}

		// ? morgan's law
		// AB|! -> A!B!&
		else if (vars.size() == 2 && operators.size() == 2 && operators[0] == '|' && operators[1] == '!') {
			rf.erase(0, 4);
			rf.insert(0, addMorganAnd(vars[0], vars[1]));
			found = 4;
		}

		// AB&! -> A!B!|
		else if (vars.size() == 2 && operators.size() == 2 && operators[0] == '&' && operators[1] == '!') {
			rf.erase(0, 4);
			rf.insert(0, addMorganOr(vars[0], vars[1]));
			found = 4;
		}
		
		// ? equivalence
		// AB= -> AB&A!B!&|
		else if (vars.size() == 2 && operators.size() == 1 && operators[0] == '=') {
			rf.erase(0, 3);
			rf.insert(0, addEquivalence(vars[0], vars[1]));
			found = 8;
		}

		// ? material conditions
		// AB> -> A!B|
		else if (vars.size() == 2 && operators.size() == 1 && operators[0] == '>') {
			rf.erase(0, 3);
			rf.insert(0, addMaterialCondition(vars[0], vars[1]));
			found = 3;
		}

		else if (vars.size() == 2 && operators.size() == 1 && operators[0] == '|') {
			rf.erase(0, 3);
			rf.insert(0, addInverseAnd(vars[0], vars[1]));
			found = 4;
		}

		
		else if (vars.size() == 2 && operators.size() == 1 && operators[0] == '&') {
			rf.erase(0, 3);
			rf.insert(0, addInverseOr(vars[0], vars[1]));
			found = 4;
		}

		if (found) {
			i = found;
			vars.clear();
			operators.clear();
			found = 0;
		}
	}
	



	return rf;
}
