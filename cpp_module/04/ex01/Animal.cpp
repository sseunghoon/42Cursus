#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called: " << type << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal type constructor called: " << type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called: " << type << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy constructor called: " << type << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal Copy assignment operator called: " << type << std::endl;
	type = copy.type;
	
	return (*this);
}

std::string Animal::getType() const {
	return (this->type);
}

void Animal::makeSound() const {
	std::cout << type << ": Animal~" << std::endl;
}
