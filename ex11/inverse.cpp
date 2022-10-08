#include <string>
#include <iostream>
#include <limits>
#include <tuple>

std::tuple<unsigned short, unsigned short> reverse_map(double n)
{
	std::tuple<unsigned short, unsigned short> tup(0, 0);
	unsigned int computed_value;

	computed_value = (unsigned int)(n * std::numeric_limits<unsigned int>::max());
	for (int i = 0; i < 16; i++) {
		std::get<0>(tup) |= computed_value & (1 << i);
		std::get<1>(tup) |= (computed_value >> 16) & (1 << i);
	}

	return (tup);
}
