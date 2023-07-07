#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int exeGrade;

		class GradeTooHighException : public std::exception {
			public:
				const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what(void) const throw();
		};

    public:
    	Form();
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		void beSigned(Bureaucrat bc);

		const std::string& getName() const;
		const bool getIsSigned() const;
		const int getSignGrade() const;
		const int getExeGrade() const;
};

std::ostream& operator << (std::ostream &out, const Form &form);


#endif
