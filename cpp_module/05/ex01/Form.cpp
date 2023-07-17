#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {
	std::cout << "Form Default constructor called" << std::endl;
	checkException();
}

Form::Form(std::string name, int signGrade, int exeGrade) : name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade) {
	std::cout << "Form Default constructor called" << std::endl;
	checkException();
}

Form::Form(const Form& other) : name(other.getName()), isSigned(false), signGrade(other.getSignGrade()), exeGrade(other.getExeGrade()) {
	std::cout << "Form Copy constructor called" << std::endl;
	checkException();
	*this = other;
}

Form& Form::operator=(const Form& source) {
	std::cout << "Form Assignation operator called" << std::endl;
	
	(void)source;
	
	return (*this);
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

const char * Form::GradeTooHighException::what(void) const throw() {
	return "Form : Grade Too High";
}

const char * Form::GradeTooLowException::what(void) const throw() {
	return "Form : Grade Too Low";
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
		throw Form::GradeTooHighException();
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
		<< ", exeGrade: " << form.getExeGrade();
	return out;
}
