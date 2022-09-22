mod operations;
use operations::multiplier::multiplier;

fn main() {
    println!("{0} * {1} = {2} ({3})", 25, 12, multiplier(25, 12), (25 * 12));
    println!("{0} * {1} = {2} ({3})", 56, 23, multiplier(56, 23), (56 * 23));
    println!("{0} * {1} = {2} ({3})", 564, 564, multiplier(564, 564), (564 * 564));
    println!("{0} * {1} = {2} ({3})", 587, 6451, multiplier(587, 6451), (587 * 6451));
    println!("{0} * {1} = {2} ({3})", 9, 2, multiplier(9, 2), (9 * 2));
    println!("{0} * {1} = {2} ({3})", 98, 23, multiplier(98, 23), (98 * 23));
}
