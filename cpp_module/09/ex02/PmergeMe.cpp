#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	jacobsthalNumbers.push_back(0);
	jacobsthalNumbers.push_back(1);
}

PmergeMe::PmergeMe(std::string& str) {
	std::stringstream ss(str);
	std::string token;

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

	jacobsthalNumbers.push_back(0);
	jacobsthalNumbers.push_back(1);

	for (int i = 2, jn = 1; jn < v.size(); i++) {
		jn = jacobsthalNumbers[i - 1] + jacobsthalNumbers[i-2] * 2;
		jacobsthalNumbers.push_back(jn);
	}
	std::vector<int>::iterator it = jacobsthalNumbers.begin();
	jacobsthalNumbers.erase(it++);
	jacobsthalNumbers.erase(it);
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	(*this) = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	this->l = other.l;
	this->v = other.v;

	return (*this);
}

PmergeMe::~PmergeMe() {
}

std::vector<int> PmergeMe::makeMainChain(std::vector<std::pair<int, int>>& pv) {
	std::vector<int> mainChain;

	for (unsigned int i = 0; i < pv.size(); i++) {
		mainChain.push_back(pv[i].first);
	}
	
	return mainChain;
}

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int>& mc, int num) {
	
}

void PmergeMe::insertElement(std::vector<int>& mc, int num) {
	// 이분탐색해서 삽입
	std::vector<int>::iterator it = binarySearch(mc, num);
	mc.insert(it, num);
}

void PmergeMe::mergeInsertionSortVector() {
	std::vector<std::pair<int, int>> pv;

	for (unsigned int i = 0; i + 1 < v.size(); i += 2) {
		if (v[i] < v[i + 1])
			pv.push_back(std::pair<int,int>(v[i], v[i + 1]));
		else
			pv.push_back(std::pair<int,int>(v[i + 1], v[i]));
	}
	sort(pv.begin(), pv.end(), compare);
	
	std::vector<int> mc = makeMainChain(pv);
	for (unsigned int i = 1; jacobsthalNumbers[i] < pv.size(); i++) {
		for (unsigned int k = jacobsthalNumbers[i]; k > jacobsthalNumbers[i-1]; k--) {
			insertElement(mc, pv[k].second);
		}
	}
	for (unsigned int i = 1 + jacobsthalNumbers[i - 1]; i < pv.size(); i++) {
		insertElement(mc, pv[i].second);
	}
	if (v.size() % 2) {
		insertElement(mc, v.back());
	}
}

void PmergeMe::mergeInsertionSortList() {

}

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first > b.first;
}