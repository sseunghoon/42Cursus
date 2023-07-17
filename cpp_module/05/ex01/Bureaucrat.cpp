#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	std::cout << "Bureaucrat Name + Grade constructor called: " << getName() << std::endl;
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()), grade(other.getGrade()){
	std::cout << "Bureaucrat Copy constructor called: " << getName() << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source) {
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	std::cout << "Just Grade Changed" << std::endl;
	this->grade = source.getGrade();

	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called: " << getName() << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade can't lower than 150";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade can't be higher than 1";
}

void Bureaucrat::checkGrade(int futureGrade) const {
	if (futureGrade < 1) {
		throw Bureaucrat::GradeTooLowException();
	}
	if (futureGrade > 150) {
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::incrementGrade() {
	checkGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrementGrade() {
	checkGrade(grade + 1);
	grade++;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::signForm(Form form) {
	try {
		form.beSigned(*this);
	} catch (const std::exception &e) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &bc) {
	out << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return out;
}
