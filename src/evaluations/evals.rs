pub fn negation(x : bool) -> bool {
	return !x;
}

pub fn and(x : bool, y : bool) -> bool {
	return x && y;
}

pub fn or(x: bool, y: bool) -> bool {
	return x || y;
}

pub fn xor(x: bool, y: bool) -> bool {
	return or(and(x, negation(y)), and(negation(x), y))
}

pub fn material_condition(x: bool, y: bool) -> bool {
	return or(negation(x), y);
}

pub fn logical_equivalence(x: bool, y: bool) -> bool {
	return or(and(x, y), and(negation(x), negation(y)));
}
