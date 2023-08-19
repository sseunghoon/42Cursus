/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/16 19:03:11 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	::iter<int>(arr, 10, ::print);

	std::string str = "Hello, World!";
	iter<const char>(str.c_str(), str.length(), ::print);

	return 0;
}