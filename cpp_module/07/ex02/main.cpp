/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/16 21:48:34 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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

	std::cout << "[ Same Test ]" << std::endl;
	for (int i = 0; i < 100; i++) {
		if (mirror[i] != arr[i]) {
			std::cerr << "*** arr != mirror ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** arr == mirror ***\n" << std::endl;
	delete[] mirror;
	
	std::cout << "[ Out of bounds Test ]" << std::endl;
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


	std::cout << "[ Copy Constructor Test ]" << std::endl;
	Array<int> copy(arr);
	for (int i = 0; i < 100; i++) {
		if (copy[i] != arr[i]) {
			std::cerr << "*** copy != arr ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** copy == arr ***\n" << std::endl;

	std::cout << "[ Assignment Operator Test ]" << std::endl;
	Array<int> ass;
	ass = arr;
	for (int i = 0; i < 100; i++) {
		if (ass[i] != arr[i]) {
			std::cerr << "*** ass != arr ***\n" << std::endl;
			return 1;
		}
	}
	std::cout << "*** ass == arr ***\n" << std::endl;
	

	std::cout << "[ Deep Copy Test ]" << std::endl;
	copy[0] = -1;
	copy[1] = -1;
	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";
}