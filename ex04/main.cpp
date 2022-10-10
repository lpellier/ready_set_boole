#include <iostream>

void print_truth_table(const std::string & formula);

int main() {
	print_truth_table("AB&C|");
	print_truth_table("AC|");

	print_truth_table("A!B|B!A|&");
	print_truth_table("AB&A!B!&|");
	print_truth_table("AB=");

	print_truth_table("AB&C|DE|&!F&");

	// print_truth_table("ABCDEFGHIJKLMNOPQRSTUVWXYZ&&|||||||||&&||||||||||||");

	exit(0);
}
