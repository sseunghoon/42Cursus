#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default constructor called: " << type << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "AAnimal type constructor called: " << type << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy constructor called: " << type << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal Copy assignment operator called: " << type << std::endl;
	type = copy.type;
	
	return (*this);
}

std::string AAnimal::getType() const {
	return (this->type);
}

void AAnimal::makeSound() const {
	std::cout << type << ": (No Sound)" << std::endl;
}
