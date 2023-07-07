#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source) {
	
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::ostream& operator << (std::ostream &out, const Bureaucrat &bc) {
	// out << bc.toFloat();
	return out;
}