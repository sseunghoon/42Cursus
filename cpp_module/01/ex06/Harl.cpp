/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/22 14:14:58 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug() {
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info() {
	std::cout << "[INFO]\nI cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!\n" << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month.\n" << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR]\nThis is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

int convert_level(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

void Harl::complain(std::string level) {
	int converted_level = convert_level(level);
	
	switch (converted_level)
	{
	case 0:
		this->debug();
	case 1:
		this->info();
	case 2:
		this->warning();
	case 3:
		this->error();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}