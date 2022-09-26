// boolean algebra
// 0     -> false
// 1     -> true
// x !   -> negation of x
// x y & -> x and y
// x y | -> x or y
// x y ^ -> (x and (negation of y)) or ((negation of x) and y)
// x y > -> (negation of x) or y
// x y = -> (x and y) or ((negation of x) and (negation of y))

use super::evals;

pub fn eval_formula(formula : &str) -> bool {
	let mut result : Vec<bool> = vec![];
	let mut operators : Vec<char> = vec![];
	let mut op_size = 0;

	for c in formula.chars() {
		if c == '0' || c == '1' {
			result.push(c.to_digit(10).unwrap() != 0);
		}
		else if c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=' {
			operators.push(c);
			if c != '!' {
				op_size += 1;
			}
		}
		else {
			println!("Error : {} is not a supported operator.", c);
			return false;
		}
	}

	if result.len() == 0 || op_size != result.len() - 1 {
		println!("Error : not the right amount of operators or operands.");
		return false;
	}

	result = result.into_iter().rev().collect();

	for c in operators.into_iter() {
		if result.len() == 1 {
			break;
		}
		if c == '!' {
			result[0] = evals::negation(result[0]);
		}
		else if c == '&' {
			result[0] = evals::and(result[0], result[1]);
			result.remove(1);
		}
		else if c == '|' {
			result[0] = evals::or(result[0], result[1]);
			result.remove(1);
		}
		else if c == '^' {
			result[0] = evals::xor(result[0], result[1]);
			result.remove(1);
		}
		else if c == '>' {
			result[0] = evals::material_condition(result[0], result[1]);
			result.remove(1);
		}
		else if c == '=' {
			result[0] = evals::logical_equivalence(result[0], result[1]);
			result.remove(1);
		}
	}

	return result[0];
}
