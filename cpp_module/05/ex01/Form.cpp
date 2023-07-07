#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Form::Form(const Form& other) : signGrade(other.getSignGrade()), exeGrade(other.getExeGrade()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& source) : name(sou{
	this.
	
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

void Form::beSigned(Bureaucrat bc) {
	
}

const std::string &Form::getName() const {
    return name;
}

const bool Form::getIsSigned() const {
    return isSigned;
}

const int Form::getSignGrade() const {
    return signGrade;
}

const int Form::getExeGrade() const {
    return exeGrade;
}

std::ostream& operator << (std::ostream &out, const Form &form) {
	out << form.getName() << ", isSigned: " << form.getIsSigned()
		<< ", isSigned: " << form.getIsSigned()
		<< ", signGrade: " << form.getSignGrade()
		<< ", exeGrade: " << form.getExeGrade() << std::endl;
	return out;
}
