/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/28 16:59:18 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Usage: ./PmergeMe [numbers]" << std::endl;
		return (1);
	}

	int i = 1;
	std::string str(argv[i++]);
	while (i < argc) {
		str += " ";
		str += argv[i];
		i++;
	}
	
	clock_t	start;
	clock_t	end;
	double vectorInterval;
	double dequeInterval;
	PmergeMe pm(str);

	start = clock();
	std::vector<int> sortedVector = pm.mergeInsertionSortVector();
	end = clock();
	vectorInterval = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	start = clock();
	std::deque<int> sortedDeque = pm.mergeInsertionSortDeque();
	end = clock();
	dequeInterval = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "Before: ";
	for (std::vector<int>::iterator it = pm.getV().begin(); it != pm.getV().end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (std::vector<int>::iterator it = sortedVector.begin(); it != sortedVector.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << pm.getV().size() << " elements with std::vector : " << vectorInterval << " ms" << std::endl;
	std::cout << "Time to process a range of " << pm.getDeq().size() << " elements with std::deque : " << dequeInterval << " ms" << std::endl;

	std::cout << "\n[Check Sorted Test]" << std::endl;
	std::sort(pm.getV().begin(), pm.getV().end());
	if (pm.getV() == sortedVector)
		std::cout << "std::vector is sorted" << std::endl;
	else
		std::cout << "std::vector is not sorted" << std::endl;
	
	std::sort(pm.getDeq().begin(), pm.getDeq().end());
	if (pm.getDeq() == sortedDeque)
		std::cout << "std::deque is sorted" << std::endl;
	else
		std::cout << "std::deque is not sorted" << std::endl;

	return (0);
}