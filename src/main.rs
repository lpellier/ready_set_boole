mod operations;
use operations::multiplier::multiplier;

mod evaluations;

fn main() {
	// adder
	println!("Adder");
	// multiplier
	println!("\nMultiplier");
	println!("{0} * {1} = {2} ({3})", 25, 12, multiplier(25, 12), (25 * 12));
    println!("{0} * {1} = {2} ({3})", 56, 23, multiplier(56, 23), (56 * 23));
    println!("{0} * {1} = {2} ({3})", 564, 564, multiplier(564, 564), (564 * 564));
    println!("{0} * {1} = {2} ({3})", 587, 6451, multiplier(587, 6451), (587 * 6451));
    println!("{0} * {1} = {2} ({3})", 9, 2, multiplier(9, 2), (9 * 2));
    println!("{0} * {1} = {2} ({3})", 98, 23, multiplier(98, 23), (98 * 23));

	// gray code
	println!("\nGray Code");
	println!("{} (0)", evaluations::gray_code::gray_code(0));
	println!("{} (1)", evaluations::gray_code::gray_code(1));
	println!("{} (3)", evaluations::gray_code::gray_code(2));
	println!("{} (2)", evaluations::gray_code::gray_code(3));
	println!("{} (6)", evaluations::gray_code::gray_code(4));
	println!("{} (7)", evaluations::gray_code::gray_code(5));
	println!("{} (5)", evaluations::gray_code::gray_code(6));
	println!("{} (4)", evaluations::gray_code::gray_code(7));
	println!("{} (12)", evaluations::gray_code::gray_code(8));

	// boolean evaluation
	println!("\nBoolean Evaluation");
	println!("{} (false)", evaluations::eval_formula::eval_formula("10&"));
	println!("{} (true)", evaluations::eval_formula::eval_formula("10|"));
	println!("{} (true)", evaluations::eval_formula::eval_formula("11>"));
	println!("{} (false)", evaluations::eval_formula::eval_formula("10="));
	println!("{} (true)", evaluations::eval_formula::eval_formula("1011||="));

	println!("{} (true)", evaluations::eval_formula::eval_formula("101|&"));
	println!("{} (true)", evaluations::eval_formula::eval_formula("10|1&"));

	// print truth table
	println!("\nTruth Table");
	evaluations::truth_table::print_truth_table("ABC&|!");
}
