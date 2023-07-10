#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	checkException();
}

Form::Form(std::string name, int signGrade, int exeGrade) : name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	checkException();
}

Form::Form(const Form& other) : signGrade(other.getSignGrade()), exeGrade(other.getExeGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	checkException();
	*this = other;
}

Form& Form::operator=(const Form& source) {
	this->isSigned = source.getIsSigned();
	checkException();
	
	return (*this);
}

Form::~Form() {
}

const char * Form::GradeTooHighException::what(void) const throw() {
	return "Grade can't exceed 150";
}

const char * Form::GradeTooLowException::what(void) const throw() {
	return "Grade can't be lower than 1";
}

void Form::checkException() const {
	if (signGrade < 1 || exeGrade < 1) {
		throw Form::GradeTooLowException();
	}
	if (signGrade > 150 || exeGrade > 150) {
		throw Form::GradeTooHighException();
	}
}

void Form::beSigned(const Bureaucrat &bc) {
	if (bc.getGrade() <= signGrade) {
		isSigned = true;
	} else {
		throw GradeTooHighException();
	}
}

const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getSignGrade() const {
    return signGrade;
}

int Form::getExeGrade() const {
    return exeGrade;
}

std::ostream& operator << (std::ostream &out, const Form &form) {
	out << form.getName() << ", isSigned: " << form.getIsSigned()
		<< ", isSigned: " << form.getIsSigned()
		<< ", signGrade: " << form.getSignGrade()
		<< ", exeGrade: " << form.getExeGrade() << std::endl;
	return out;
}
