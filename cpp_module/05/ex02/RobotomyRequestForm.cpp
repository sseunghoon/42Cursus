#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
	std::cout << "RobotomyRequestForm constructor called: " << getName() << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm Destructor called: " << getName() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm Copy constructor called: " << getName() << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "RobotomyRequestForm Copy assignment operator called: " << getName() << std::endl;
	AForm::operator=(copy);
	
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	isExecutable(executor);

	std::cout << "DRRRRRRRRRRRRRRRR!!!" << std::endl;
	std::srand((unsigned int)std::time(NULL));
	if (std::rand() % 2) {
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << getName() << " robotomization failed" << std::endl;
	}
}