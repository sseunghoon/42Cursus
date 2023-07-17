#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {
	std::cout << "AForm Default constructor called" << std::endl;
	checkException();
}

AForm::AForm(std::string name, int signGrade, int exeGrade) : name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade) {
	std::cout << "AForm Default constructor called" << std::endl;
	checkException();
}

AForm::AForm(const AForm& other) : name(other.getName()), isSigned(false), signGrade(other.getSignGrade()), exeGrade(other.getExeGrade()) {
	std::cout << "AForm Copy constructor called" << std::endl;
	checkException();
	*this = other;
}

AForm& AForm::operator=(const AForm& source) {
	std::cout << "AForm Assignation operator called" << std::endl;
	(void)source;
	
	return (*this);
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

const char * AForm::GradeTooHighException::what(void) const throw() {
	return "AForm : Grade Too High";
}

const char * AForm::GradeTooLowException::what(void) const throw() {
	return "AForm : Grade Too Low";
}

const char * AForm::NotSignedException::what(void) const throw() {
	return "AForm is not signed";
}

void AForm::checkException() const {
	if (signGrade < 1 || exeGrade < 1) {
		throw AForm::GradeTooLowException();
	}
	if (signGrade > 150 || exeGrade > 150) {
		throw AForm::GradeTooHighException();
	}
}

void AForm::isExecutable(const Bureaucrat &executor) const {
	if (!isSigned) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > exeGrade) {
		throw AForm::GradeTooLowException();
	}

}

void AForm::beSigned(const Bureaucrat &bc) {
	if (bc.getGrade() <= signGrade) {
		isSigned = true;
	} else {
		throw AForm::GradeTooHighException();
	}
}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExeGrade() const {
    return exeGrade;
}

std::ostream& operator << (std::ostream &out, const AForm &AForm) {
	out << AForm.getName() << ", isSigned: " << AForm.getIsSigned()
		<< ", isSigned: " << AForm.getIsSigned()
		<< ", signGrade: " << AForm.getSignGrade()
		<< ", exeGrade: " << AForm.getExeGrade();
	return out;
}
