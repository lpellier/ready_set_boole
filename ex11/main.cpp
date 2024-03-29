#include <string>
#include <iostream>
#include <tuple>

double	map(unsigned short x, unsigned short y);
std::tuple<unsigned short, unsigned short>	reverse_map(double n);

void printTuple(std::tuple<unsigned short, unsigned short> a) {
	std::cout << "(" << std::get<0>(a) << ", " << std::get<1>(a) << ")" << std::endl;
}

int main() {
	std::cout << "(25, 30) -> " << map(25, 30) << " -> ";
	printTuple(reverse_map(map(25, 30)));
	std::cout << "(22254, 30845) -> " << map(22254, 30845) << " -> ";
	printTuple(reverse_map(map(22254, 30845)));
	std::cout << "(22254, 30845) -> " << map(0, 0) << " -> ";
	printTuple(reverse_map(map(0, 0)));
	std::cout << "(65535, 65535) -> " << map(65535, 65535) << " -> ";
	printTuple(reverse_map(map(65535, 65535)));

	exit(0);
}
