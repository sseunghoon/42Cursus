#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called: " << std::endl;
}

Brain::~Brain() {
	std::cout << "Animal type constructor called: " << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called: " << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain Copy assignment operator called: " << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = copy.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int idx) const{
	return ideas[idx];
}

void Brain::setIdea(std::string idea, int idx) {
	ideas[idx] = idea;
}