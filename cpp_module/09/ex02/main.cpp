/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/25 15:34:47 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	int i = 1;
	std::string str(argv[i++]);
	while (i < argc) {
		str += " ";
		str += argv[i];
		i++;
	}

	
	
	clock_t	start;
	clock_t	end;
	PmergeMe pm;

	start = clock();
	pm.mergeInsertionSort(v);
	end = clock();
	std::cout << end - start << std::endl;
	
	return (0);
}