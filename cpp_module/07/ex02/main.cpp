/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/21 19:14:49 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

int main(void)
{
	Array<int> arr(100);
	int *mirror = new int[100];

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		const int value = rand();
		arr[i] = value;
		mirror[i] = value;
	}

	std::cout << "\n[ Same Test ]" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (mirror[i] != arr[i]) {
			std::cerr << "*** arr != mirror ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** arr == mirror ***\n" << std::endl;
	delete[] mirror;
	
	std::cout << "\n[ Out of bounds Test ]" << std::endl;
	try {
	    arr[-1] = 0;
	} catch(const std::exception& e) {
	    std::cerr << "Out of bounds : [-1]\n";
	}
	try {
	    arr[100] = 0;
	} catch(const std::exception& e) {
	    std::cerr << "Out of bounds : [100]\n";
	}


	std::cout << "\n[ Copy Constructor Test ]" << std::endl;
	Array<int> copy(arr);
	for (int i = 0; i < 100; i++) {
		if (copy[i] != arr[i]) {
			std::cerr << "*** copy != arr ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** copy == arr ***\n" << std::endl;

	std::cout << "\n[ Assignment Operator Test ]" << std::endl;
	Array<int> ass;
	ass = arr;
	for (int i = 0; i < 100; i++) {
		if (ass[i] != arr[i]) {
			std::cerr << "*** ass != arr ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** ass == arr ***\n" << std::endl;
	

	std::cout << "\n[ Deep Copy Test ]" << std::endl;
	copy[0] = -1;
	copy[1] = -1;
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}