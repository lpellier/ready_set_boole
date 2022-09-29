#include <iostream>
#include <string>

// ? must recognize patterns : 
// ? material condition, equivalence, elimination of double negation, de morgan's law, distributivity

// ? first apply distributivity
// ? then look for morgan's law, equivalence and material condition and translate
// ? then look for double negations and eliminate them



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
	unsigned int i = 0;
	vars.clear();
	operators.clear();

	// distributivity 

	// BC|A& -> AB&AC&|
	// BCA|&
	// AB|AC& shouldn't work
	for (int i = 0; rf[i]; i++) {
		if (rf[i] >= 'A' && rf[i] <= 'Z') {
			vars.push_back(rf[i]);
		}
		else if (rf[i] == '!' || rf[i] == '&' || rf[i] == '|' || rf[i] == '^' || rf[i] == '>' || rf[i] == '=') {
			operators.push_back(rf[i]);
		}
		if (vars.size() == 3 && operators.size() == 2 && operators[0] == '|' && operators[1] == '&') {
			std::string add = std::string(vars[2] + vars[0] + "&" + vars[2] + vars[1] + "|");
			// then add the rest of the formula
			rf.erase(0, 5);

			// reparse every operand and operator and start again
		}
	}
	
	// BC&A| -> AB|AC|&
	// BCA&|

	// morgan's law
	// AB|! -> A!B!&
	// AB&! -> A!B!|

	// equivalence
	// AB= -> AB&A!B!&|

	// material conditions
	// AB> -> A!B|
	return "something";
}
