#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<unsigned int> jacobsthalNumbers;
		std::vector<int> v;
		std::deque<int> deq;

		PmergeMe();

    public:
		PmergeMe(std::string& str);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		std::vector<int>& getV();
		std::deque<int>& getDeq();

		void insertElement(std::vector<int>& mc, int num);
		void insertElement(std::deque<int>& mc, int num);

		std::vector<int> makeMainChain(std::vector<std::pair<int, int> >& pv);
		std::deque<int> makeMainChain(std::deque<std::pair<int, int> >& pl);

		std::vector<int>::iterator binarySearch(std::vector<int>& mc, int num);
		std::deque<int>::iterator binarySearch(std::deque<int>& mc, int num);

		std::vector<int> mergeInsertionSortVector();
		std::deque<int> mergeInsertionSortDeque();
		
};

bool compare(std::pair<int, int> a, std::pair<int, int> b);

#endif
