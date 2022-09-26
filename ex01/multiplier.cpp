// ? allowed operations
	// &
	// |
	// ^
	// <<
	// >>
	// =
	// ==, !=, <, >, <=, >=
	// ++ just for iterating in loops

use super::adder::adder;

pub fn multiplier(a: u32, b: u32) -> u32 {
	let mut i = 0;
	let mut result = 0;
	while i < b {
		result = adder(result, a);
		i += 1;
	}
	return result;
}
