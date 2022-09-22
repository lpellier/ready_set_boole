// ? allowed operations
	// &
	// |
	// ^
	// <<
	// >>
	// =
	// ==, !=, <, >, <=, >=
	// ++ just for iterating in loops

pub fn adder(a: u32, b: u32) -> u32 {
	let result = a ^ b;
	let carry = (a & b) << 1;
	if carry == 0 {
		return result;
	}
	else {
		return adder(result, carry);
	}
}
