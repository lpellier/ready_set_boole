// use super::evals;
// use super::eval_formula;

#[derive(Copy, Clone, PartialEq)]
struct Node<'a> {
	pub val: &'a bool,
	pub left: Option<Box<Node<'a>>>,
	pub right: Option<Box<Node<'a>>>
}

impl<'a> Node<'a> {
	pub fn insert(&mut self) {
		let target_node = &mut self.left;
		match target_node {
			&mut Some(ref mut subnode) => subnode.insert(),
			&mut None => {
				let new_node = Node { val: &true, left: None, right: None };
				let boxed_node = Some(Box::new(new_node));
				*target_node = boxed_node;
			}
		}
	}
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
fn print2DUtil(root: Option<Box<Node>>, mut space: u32)
{
    // Base case
    if root == None {
        return;
	}
 
    // Increase distance between levels
    space += 5;
 
    // Process right child first
	let test_r = root.unwrap().right;
    print2DUtil(test_r, space);
 
    // Print current node after space
    // count
	println!("");
	let mut i = 0;
    while i < space {
        print!(" ");
		i += 1;
	}
	let test = root.unwrap().val;
	println!("{}", test);
 
    // Process left child
	let test_l = root.unwrap().left;
    print2DUtil(test_l, space);
}
 
// Wrapper over print2DUtil()
fn print2D(root: Option<Box<Node>>)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// ? for every single variable, test every single possible outcome of eval formula
// ? max of 26 variables so 2^26 = 67 108 864 possibilities 
pub fn print_truth_table(formula: &str) {
	let mut vars : Vec<char> = vec![];
	let mut operator_size = 0;
	let mut operand_size = 0;

	for c in formula.chars() {
		if c >= 'A' && c <= 'Z' {
			if !vars.contains(&c) {
				vars.push(c);
			}
			operand_size += 1;
		}
		else if c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=' {
			if c != '!' {
				operator_size += 1;
			}
		}
		else {
			println!("Error : {} is not a supported operator.", c);
			return ;
		}
	}
	if operand_size == 0 || operator_size != operand_size - 1 {
		println!("Error : not the right amount of operators or operands.");
		return ;
	}

	let mut tree = Node { val: &true, left: None, right: None};
	tree.insert();
	print2D(Some(Box::new(tree)));
	// let mut current = tree;
	// for _var in vars.into_iter() {
	// 	current.add_layer();	
	// 	current = tree;
	// }
	
}
