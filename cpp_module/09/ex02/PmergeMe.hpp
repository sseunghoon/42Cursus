#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<int> jacobsthalNumbers;
		std::vector<int> v;
		std::list<int> l;

		PmergeMe();

    public:
		PmergeMe(std::string& str);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void insertElement(std::vector<int>& mc, int num);
		void mergeInsertionSortVector();
		void mergeInsertionSortList();
		std::vector<int> makeMainChain(std::vector<std::pair<int, int>>& pv);
		std::vector<int>::iterator binarySearch(std::vector<int>& mc, int num);
};

bool compare(std::pair<int, int> a, std::pair<int, int> b);

#endif
