#include <string>
#include <iostream>
#include <limits>

// potential solution would be to record every bit of x and those of y into a single double
// then to reverse that, just read every bit of the result s

double	map(unsigned short x, unsigned short y) {
	double res;

	unsigned int max = std::numeric_limits<unsigned int>::max();
	unsigned int computed_value = (static_cast<unsigned int>(x + 1)) * (static_cast<unsigned int>(y + 1)) - 1;

	res = static_cast<double>(computed_value) / static_cast<double>(max);

	return res;
}
