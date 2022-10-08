#include <string>
#include <iostream>
#include <limits>

double	map(unsigned short x, unsigned short y) {
	unsigned int res = 0;

	for (int i = 0; i < 16; i++) {
		res |= (x & (1 << i));
		res |= (y & (1 << i)) << 16;
	}
	return (static_cast<double>(res) / std::numeric_limits<unsigned int>::max());
}
