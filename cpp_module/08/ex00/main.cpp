/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:02:33 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/23 12:29:38 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void) {
	std::cout << "[ Test easyfind() in Vector ]" << std::endl;

	std::vector<int> vector;

	for (int i = 0; i < 10; i++)
		vector.push_back(i);

	try {
		std::cout << "easyfind(vector, 0): " << *easyfind(vector, 0) << std::endl;
		std::cout << "easyfind(vector, 9): " << *easyfind(vector, 9) << std::endl;
		std::cout << "easyfind(vector, 10): " << *easyfind(vector, 10) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}