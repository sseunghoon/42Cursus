#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	(void)copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::run(std::string& str) {
	std::stringstream ss(str);
	std::string token;

	std::vector<int> v;
	std::list<int> l;

	while (ss >> token) {
		int num = std::atoi(token.c_str());
		for (unsigned int i = 0; i < token.length(); i++) {
			if (token[i] <= '0' || token[i] > '9') {
				std::cout << "Error" << std::endl;
				return ;
			}
		}
		if (num < 0)
			return ;

		v.push_back(num);
		l.push_back(num);
	}

	// sort vector by  Ford-Johnson algorithm.
	// https://en.wikipedia.org/wiki/Ford%E2%80%93Johnson_algorithm
	for (unsigned int i = 0; i < v.size(); i++) {
		for (unsigned int j = 0; j < v.size(); j++) {
			if (v[i] < v[j]) {
				int tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}


}
