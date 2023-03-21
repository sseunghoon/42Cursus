#include "Contact.hpp"

std::string Contact::resizing(std::string str) {
	if (str.length() > 10) {
		str.resize(9);
		str.append(".");
	}
	return str;
}

void Contact::PrintSelf() {
	std::cout << "First Name: " << this->firstName << std::endl;
	std::cout << "Last Name: " << this->lastName << std::endl;
	std::cout << "Nick Name: " << this->nickName << std::endl;
	std::cout << "Phone Number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest_secret: " << this->darkestSecret << std::endl;
}

void Contact::PrintShort() {
	std::cout << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << resizing(this->firstName) << "|";
	std::cout << std::setw(10) << resizing(this->lastName) << "|";
	std::cout << std::setw(10) << resizing(this->nickName) << "|";
	std::cout << std::setw(10) << resizing(this->phoneNumber) << "|";
	std::cout << std::setw(10) << resizing(this->darkestSecret) << std::endl;
}
