#include <string>
#include <iostream>
#include <limits>

// potential solution would be to record every bit of x and those of y into a single double
// then to reverse that, just read every bit of the result s

double	map(unsigned short x, unsigned short y) {
	unsigned int res = 0;

	for (int i = 0; i < 16; i++) {
		res |= (x & (1 << i));
		res |= (y & (1 << i)) << 16;
	}
	return (static_cast<double>(res) / std::numeric_limits<unsigned int>::max());
}
