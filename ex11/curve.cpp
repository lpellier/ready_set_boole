#include <string>
#include <iostream>
#include <limits>

double	map(unsigned short x, unsigned short y) {
	double res;

	unsigned int max = std::numeric_limits<unsigned int>::max();
	unsigned int computed_value = (static_cast<unsigned int>(x + 1)) * (static_cast<unsigned int>(y + 1)) - 1;

	res = static_cast<double>(computed_value) / static_cast<double>(max);

	return res;
}
