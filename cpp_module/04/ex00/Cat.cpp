#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called: " << type << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called: " << type << std::endl;
}

Cat::Cat(const Cat& copy) : Animal("Cat") {
	std::cout << "Cat copy constructor called: " << type << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat Copy assignment operator called: " << type << std::endl;
	type = copy.type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << type << ": Meow~" << std::endl;
}