#include <vector>

unsigned int	pow(unsigned int n, unsigned int poww) {
	unsigned int res = 1;
	for (unsigned int i = 0; i < poww; i++)
		res *= n;
	return res;
}

std::vector<std::vector<int> >	powerset(const std::vector<int> & set) {
	std::vector<std::vector<int> > pwrset;
    unsigned int pow_set_size = pow(2, set.size());
 
    for (unsigned int counter = 0; counter < pow_set_size; counter++) {
		std::vector<int> cur_set = std::vector<int>();
        for (unsigned int j = 0; j < set.size(); j++) {
            if (counter & (1 << j)) {
				cur_set.push_back(set[j]);
			}
        }
		pwrset.push_back(cur_set);
    }

	return pwrset;
}