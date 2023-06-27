/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:33:57 by songseunghu       #+#    #+#             */
/*   Updated: 2023/03/21 22:33:58 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::resizing(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	}
	return str;
}

void Contact::printSelf() {
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nick Name: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest_secret: " << this->darkestSecret << std::endl;
}

void Contact::printShort() {
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << resizing(this->firstName) << "|";
	std::cout << std::setw(10) << resizing(this->lastName) << "|";
	std::cout << std::setw(10) << resizing(this->nickName) << "|";
	std::cout << std::setw(10) << resizing(this->phoneNumber) << "|";
	std::cout << std::setw(10) << resizing(this->darkestSecret) << std::endl;
}

void Contact::setIndex(int index) {
	this->index = index;
}

void Contact::setFirstName(std::string firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
	this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->darkestSecret = darkestSecret;
}

int Contact::getIndex() {
    return this->index;
}

std::string Contact::getFirstName() {
    return this->firstName;
}

std::string Contact::getNickName() {
    return this->nickName;
}

std::string Contact::getPhoneNumber() {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() {
    return this->darkestSecret;
}
