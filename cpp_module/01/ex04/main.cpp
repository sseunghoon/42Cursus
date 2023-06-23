/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/06/22 12:24:34 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
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
	std::ofstream outFile(fileName + ".replace");
	while (file.good()) {
		char c = file.get();
		if (c >= 0)
			buffer += c;
	}
	for (size_t i = 0; i < buffer.length(); i++) {
		if (buffer.substr(i, s1.length()) == s1) {
			outFile << s2;
			i += s1.length() - 1;
		}
		else
			outFile << buffer[i];
	}
	file.close();
	outFile.close();
	
	return (0);
}
