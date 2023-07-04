#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
	std::cout << "WrongAnimal type constructor called: " << type << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) {
	std::cout << "WrongCat copy constructor called: " << type << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	std::cout << "WrongCat Copy assignment operator called: " << type << std::endl;
	type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << type << ": Meow~" << std::endl;
}