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
			if (token[i] < '0' || token[i] > '9') {
				std::cout << "Error" << std::endl;
				exit(1);
			}
		}
		if (num <= 0) {
			std::cout << "Error" << std::endl;
			exit(1);
		}

		v.push_back(num);
		deq.push_back(num);
	}


	jacobsthalNumbers.push_back(0);
	jacobsthalNumbers.push_back(1);

	for (unsigned int i = 2, jn = 1; jn < v.size(); i++) {
		jn = jacobsthalNumbers[i - 1] + jacobsthalNumbers[i-2] * 2;
		jacobsthalNumbers.push_back(jn);
	}
	std::vector<unsigned int>::iterator it = jacobsthalNumbers.begin();
	jacobsthalNumbers.erase(it);
	jacobsthalNumbers.erase(it);
}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	(*this) = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	this->deq = other.deq;
	this->v = other.v;

	return (*this);
}

PmergeMe::~PmergeMe() {
}

std::vector<int> PmergeMe::makeMainChain(std::vector<std::pair<int, int> >& pv) {
	std::vector<int> mainChain;

	for (unsigned int i = 0; i < pv.size(); i++) {
		mainChain.push_back(pv[i].first);
	}
	
	return mainChain;
}

std::deque<int> PmergeMe::makeMainChain(std::deque<std::pair<int, int> >& pdeq) {
	std::deque<int> mainChain;

	for (unsigned int i = 0; i < pdeq.size(); i++) {
		mainChain.push_back(pdeq[i].first);
	}
	
	return mainChain;
}

std::vector<int>& PmergeMe::getV() {
	return v;
}

std::deque<int>& PmergeMe::getDeq() {
	return deq;
}

std::deque<int>::iterator PmergeMe::binarySearch(std::deque<int>& mc, int num) {
	std::deque<int>::iterator it = mc.begin();
	std::deque<int>::iterator end = mc.end();
	std::deque<int>::iterator mid;
	
	while (it != end) {
		mid = it + (end - it) / 2;
		if (it == mid) {
			if (*it < num) {
				return it + 1;
			}
			return mid;
		}
		// std::cout << "it: " << *it << std::endl;
		// std::cout << "mid: " << *mid << std::endl;
		if (*(mid-1) <= num && *mid >= num)
			return mid;
		else if (*mid > num)
			end = mid;
		else
			it = mid + 1;
	}
	return it;
}

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int>& mc, int num) {
	std::vector<int>::iterator it = mc.begin();
	std::vector<int>::iterator end = mc.end();
	std::vector<int>::iterator mid;
	
	while (it != end) {
		mid = it + (end - it) / 2;
		if (it == mid) {
			if (*it < num) {
				return it + 1;
			}
			return mid;
		}
		// std::cout << "it: " << *it << std::endl;
		// std::cout << "mid: " << *mid << std::endl;
		if (*(mid-1) <= num && *mid >= num)
			return mid;
		else if (*mid > num)
			end = mid;
		else
			it = mid + 1;
	}
	return it;
}

void PmergeMe::insertElement(std::deque<int>& mc, int num) {
	std::deque<int>::iterator it = binarySearch(mc, num);
	mc.insert(it, num);
}

void PmergeMe::insertElement(std::vector<int>& mc, int num) {
	std::vector<int>::iterator it = binarySearch(mc, num);
	mc.insert(it, num);
}

std::vector<int> PmergeMe::mergeInsertionSortVector() {
	if (v.size() == 1)
		return v;

	std::vector<std::pair<int, int> > pv;

	for (unsigned int i = 0; i + 1 < v.size(); i += 2) {
		if (v[i] < v[i + 1])
			pv.push_back(std::pair<int,int>(v[i + 1], v[i]));
		else
			pv.push_back(std::pair<int,int>(v[i], v[i + 1]));
	}
	sort(pv.begin(), pv.end(), compare);
	
	std::vector<int> mc = makeMainChain(pv);
	insertElement(mc, pv[0].second);

	unsigned int i;
	for (i = 1; jacobsthalNumbers[i] < pv.size(); i++) {
		for (unsigned int k = jacobsthalNumbers[i] - 1; k > jacobsthalNumbers[i-1] - 1; k--) {
			insertElement(mc, pv[k].second);
		}
	}

	for (unsigned int j = jacobsthalNumbers[i - 1]; j < pv.size(); j++) {
		insertElement(mc, pv[j].second);
	}

	if (v.size() % 2) {
		insertElement(mc, v.back());
	}
	return mc;
}

std::deque<int> PmergeMe::mergeInsertionSortDeque() {
	if (deq.size() == 1)
		return deq;

	std::deque<std::pair<int, int> > pdeq;

	for (unsigned int i = 0; i + 1 < deq.size(); i += 2) {
		if (deq[i] < deq[i + 1])
			pdeq.push_back(std::pair<int,int>(deq[i + 1], deq[i]));
		else
			pdeq.push_back(std::pair<int,int>(deq[i], deq[i + 1]));
	}
	sort(pdeq.begin(), pdeq.end(), compare);
	
	std::deque<int> mc = makeMainChain(pdeq);
	insertElement(mc, pdeq[0].second);

	unsigned int i;
	for (i = 1; jacobsthalNumbers[i] < pdeq.size(); i++) {
		for (unsigned int k = jacobsthalNumbers[i] - 1; k > jacobsthalNumbers[i-1] - 1; k--) {
			insertElement(mc, pdeq[k].second);
		}
	}

	for (unsigned int j = jacobsthalNumbers[i - 1]; j < pdeq.size(); j++) {
		insertElement(mc, pdeq[j].second);
	}

	if (deq.size() % 2) {
		insertElement(mc, deq.back());
	}
	return mc;
}

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first < b.first;
}