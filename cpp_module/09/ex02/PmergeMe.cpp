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

	







}
