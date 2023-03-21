#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() {
	index = 0;
}

void PhoneBook::Add() {
	this->index = this->index % 8;
	std::cout << "FirstName: ";
	std::cin >> this->contacts[this->index].firstName;
	std::cout << "LastName: ";
	std::cin >> this->contacts[this->index].lastName;
	std::cout << "NickName: ";
	std::cin >> this->contacts[this->index].nickName;
	std::cout << "PhoneNumber: ";
	std::cin >> this->contacts[this->index].phoneNumber;
	std::cout << "DarkestSecret: ";
	std::cin >> this->contacts[this->index].darkestSecret;
	this->index++;
}

void PhoneBook::PrintAll() {
	for (int i = 0; i < 8; i++) {
		contacts[i].PrintShort();
	}
}

void PhoneBook::Search() {
	std::string	str;
	int			idx;

	std::cin >> str;
	idx = std::stoi(str);
	if (idx < 0 || idx > 7)
		return ;
	this->contacts[idx].PrintSelf();
}