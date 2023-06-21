/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/03/22 01:10:20 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	std::string str = "Hi This is Brain";

	std::string *stringPRT = &str;
	std::string &stringREF = str;

	std::cout << &str << std::endl;
	std::cout << stringPRT << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << *stringPRT << std::endl;
	std::cout << stringREF << std::endl;
	
	return (0);
}