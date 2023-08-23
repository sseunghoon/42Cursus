/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:06:22 by seunghso          #+#    #+#             */
/*   Updated: 2023/08/23 18:18:26 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	
	std::ifstream file(argv[1]);
	if (!file.good()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange exchanger;
	std::string line;
	std::string date;
	float amount;

	while (file.good()) {
		std::getline(file, line);
		if (line.compare("date | value") == 0)
			continue;
		if (line.find(" | ") == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		date = line.substr(0, line.find('|') - 1);
		if (date.length() != 10) {
			std::cerr << "Error: bad date format => " << date << std::endl;
			continue ;
		}
		amount = std::atof(line.substr(line.find('|') + 2).c_str());
		if (amount < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		} else if (amount > 1000) {
			std::cerr << "Error: too much money." << std::endl;
			continue ;
		}

		exchanger.exchange(date, amount);
	}
	
	file.close();

	return (0);
}