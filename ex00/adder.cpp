// ? allowed operations
	// &
	// |
	// ^
	// <<
	// >>
	// =
	// ==, !=, <, >, <=, >=
	// ++ just for iterating in loops

unsigned int adder(const unsigned int a, const unsigned int b) {
	unsigned int result = a ^ b;
	unsigned int carry = (a & b) << 1;

	if (!carry)
		return result;
	else
		return adder(result, carry);
}
