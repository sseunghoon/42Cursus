#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
	std::cout << "PresidentialPardonForm constructor called: " << getName() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm Destructor called: " << getName() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {
	std::cout << "PresidentialPardonForm Copy constructor called: " << getName() << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << "PresidentialPardonForm Copy assignment operator called: " << getName() << std::endl;
	AForm::operator=(copy);
	
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	isExecutable(executor);

	std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}