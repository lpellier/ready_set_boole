#include <string>
#include <iostream>
#include <limits>
#include <tuple>

std::tuple<unsigned short, unsigned short>	getTuple(unsigned int value) {
	for (unsigned int a = 0; a <= std::numeric_limits<unsigned short>::max(); a++) {
		for (unsigned int b = 0; b <= std::numeric_limits<unsigned short>::max(); b++) {
			if ((a + 1) * (b + 1) - 1 == value) {
				return std::make_tuple(a, b);
			}
		}
	}
	return std::make_tuple(0, 0);
}

std::tuple<unsigned short, unsigned short>	reverse_map(double n) {
	unsigned int max = std::numeric_limits<unsigned int>::max();

	double set_max = 1;
	double computed_value = n / set_max;

	unsigned int computed_value_uint = max * computed_value;

	return getTuple(computed_value_uint);
}
