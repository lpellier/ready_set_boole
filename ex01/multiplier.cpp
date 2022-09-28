// ? allowed operations
	// &
	// |
	// ^
	// <<
	// >>
	// =
	// ==, !=, <, >, <=, >=
	// ++ just for iterating in loops

unsigned int adder(const unsigned int a, const unsigned int b);

unsigned int multiplier(const unsigned int a, const unsigned int b) {
	unsigned int i = 0;
	unsigned int result = 0;
	while (i < b) {
		result = adder(result, a);
		i += 1;
	}
	return result;
}
