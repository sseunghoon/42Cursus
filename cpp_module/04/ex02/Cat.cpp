#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat default constructor called: " << type << std::endl;
	brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called: " << type << std::endl;
	delete brain;
}

Cat::Cat(const Cat& copy) : AAnimal("Cat") {
	std::cout << "Cat copy constructor called: " << type << std::endl;
	brain = new Brain();

	*this = copy;
}

Cat& Cat::operator=(const Cat& copy) {
	std::cout << "Cat Copy assignment operator called: " << type << std::endl;
	type = copy.type;

	delete brain;
	brain = new Brain(*copy.brain);

	return (*this);
}

void Cat::makeSound() const {
	std::cout << type << ": Meow~" << std::endl;
}
