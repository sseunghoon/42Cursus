#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called: " << type << std::endl;
	brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called: " << type << std::endl;
	delete brain;
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called: " << type << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy) {
	std::cout << "Dog Copy assignment operator called: " << type << std::endl;
	type = copy.type;
	
	return (*this);
}

void Dog::makeSound() const {
	std::cout << type << ": Bark~" << std::endl;
}

void Dog::setIdea(std::string idea, int idx) {
	brain->setIdea(idea, idx);
}