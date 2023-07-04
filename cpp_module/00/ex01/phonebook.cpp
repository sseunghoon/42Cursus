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
	std::string tmp;
	int	idx = this->index % 8;

	this->contacts[idx].setIndex(idx);
	this->contacts[idx].setFirstName(get_input("FirstName: "));
	this->contacts[idx].setLastName(get_input("LastName: "));
	this->contacts[idx].setNickName(get_input("NickName: "));
	this->contacts[idx].setPhoneNumber(get_input("PhoneNumber: "));
	this->contacts[idx].setDarkestSecret(get_input("DarkestSecret: "));

	this->index++;
}

void PhoneBook::printAll() {
	int len;

	std::cout << std::setw(10) << "Number" << "|";
	std::cout << std::setw(10) << "FirstName" << "|";
	std::cout << std::setw(10) << "LastName" << "|";
	std::cout << std::setw(10) << "NickName" << std::endl;
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
	str = get_input("Number: ");
	if (str.length() == 0) {
		return ;
	}
	try {
		idx = ft_stoi(str);
		if (idx < 0 || idx > 7 || idx >= this->index)
			throw std::invalid_argument("invalid_argument");
	} catch(const std::exception& e) {
		std::cerr << "invalid_argument" << '\n';
		return ;
	}
	this->contacts[idx].printSelf();
}

int ft_stoi(std::string str) {
	int i;
	std::stringstream ss;
	
	ss << str;
	ss >> i;

	return i;
}

std::string get_input(std::string str) {
	std::string tmp;

	std::cout << str;
    std::getline(std::cin, tmp);
	if (std::cin.eof()) {
		std::cin.clear();
		std::cout << std::endl;
		clearerr(stdin);
	}
	return tmp;
}
