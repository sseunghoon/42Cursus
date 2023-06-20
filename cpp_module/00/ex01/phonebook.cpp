/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:34:06 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/20 17:44:04 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	index = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {
	int	idx = this->index % 8;

	this->contacts[idx].index = idx;
	std::cout << "FirstName: ";
	std::getline(std::cin, this->contacts[idx].firstName);
	std::cout << "LastName: ";
	std::getline(std::cin, this->contacts[idx].lastName);
	std::cout << "NickName: ";
	std::getline(std::cin, this->contacts[idx].nickName);
	std::cout << "PhoneNumber: ";
	std::getline(std::cin, this->contacts[idx].phoneNumber);
	std::cout << "DarkestSecret: ";
	std::getline(std::cin, this->contacts[idx].darkestSecret);
	this->index++;
}

void PhoneBook::printAll() {
	int len;

	std::cout << std::setw(10) << "Number" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "NickName" << "|";
	std::cout << std::setw(10) << "Phone" << "|";
	std::cout << std::setw(10) << "Secret" << std::endl;
	len = std::min(this->index, 8);
	for (int i = 0; i < len; i++) {
		contacts[i].printShort();
	}
}

void PhoneBook::search() {
	std::string	str;
	int			idx;

	printAll();
	if (this->index == 0)
		return ;
	std::cout << "Number: ";
	std::getline(std::cin, str);
	try {
		idx = std::stoi(str);
		if (idx < 0 || idx > 7 || idx >= this->index)
			throw std::invalid_argument("invalid_argument");
	} catch(const std::exception& e) {
		std::cerr << "invalid_argument" << '\n';
		return ;
	}
	this->contacts[idx].printSelf();
}