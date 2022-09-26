fn pow(n : u32, i : usize) -> u32 {
	let mut j = 0;
	let mut result = 1;
	while j < i {
		result *= n;
		j += 1;
	}
	return result;
}

pub fn gray_code(n: u32) -> u32 {
	let mut n_binary : String = String::from("");
	let mut n_nbr = n;

	if n_nbr == 0 {
		n_binary.push('0');
	}
	while n_nbr > 0 {
		n_binary.push(char::from_u32(n_nbr % 2 + 48).unwrap());
		n_nbr /= 2;
	}
	n_binary = n_binary.chars().rev().collect();
	
	let n_len = n_binary.chars().count();

	let mut n_gray : String = String::from("");


	n_gray.push(n_binary.chars().nth(0).unwrap());

	for (i, c) in n_binary.chars().enumerate() {
		if i + 1 < n_len {
			if c == n_binary.chars().nth(i + 1).unwrap() {
				n_gray.push('0');
			}
			else {
				n_gray.push('1');
			}
		}
	}
	
	n_gray = n_gray.chars().rev().collect();
	
	let mut result = 0;
	for (i, c) in n_gray.chars().enumerate() {
		if c == '1' {
			result += pow(2, i);
		}
	}

	return result;
}
