/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/04/08 02:16:33 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Invalid Input" << std::endl;
	}

	std::string fileName(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::string buffer("");

	if (fileName.length() == 0 || s1.length() == 0 || s2.length() == 0) {
		std::cout << "Invalid Input" << std::endl;
		return (1);
	}

	std::ifstream file(fileName);
	while (file.good()) {
		char c = file.get();
		if (c >= 0)
			buffer += c;
		
	}
	
	return (0);
}
