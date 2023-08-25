#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe {
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
    public:
		~PmergeMe();

		static void run(std::string& str);
};

#endif
